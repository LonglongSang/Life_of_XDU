#ifndef SEMAPHOREQUEUE_H
#define SEMAPHOREQUEUE_H
#include <condition_variable>
#include <mutex>
#include <queue>
#include <bitset>
#include <iostream>
namespace sang
{
    template <typename T,size_t N>
    class semaphoreQueue
    {
        public:
            semaphoreQueue();
            T P();
            bool V(T v);
            void shutdown();
            bool haveShutdown();
            int size();
            bool inQueue(T v);
            void pop(T v);
            size_t n;
        private:
            std::mutex m;
            std::condition_variable cv;
            int cnt;
            int wakeup;
            bool end;
            std::queue<T> Q;
            std::bitset<N> vis;
            T x;
    };

    template <typename T,size_t N>
    semaphoreQueue<T,N>::semaphoreQueue()
    {
        this->cnt=0;//初试量设为0
        wakeup=0;
        end=false;
    };


    template <typename T,size_t N>
    T semaphoreQueue<T,N>::P()
    {
        std::unique_lock<std::mutex> lm(m);
        if(--cnt<0)
        {

            cv.wait(lm,[&](){return wakeup>0 || end;});
            if(end) return x;
            wakeup--;
        }
        x=Q.front();
        Q.pop();
        return x;
    };
    template <typename T,size_t N>
    void semaphoreQueue<T,N>::pop(T v)
    {
        std::unique_lock<std::mutex> lm(m);
        vis[v]=false;
    }


    template <typename T,size_t N>
    bool semaphoreQueue<T,N>::haveShutdown()
    {
        std::unique_lock<std::mutex> lm(m);
        return end;
    };
    template <typename T,size_t N>
    bool semaphoreQueue<T,N>::inQueue(T v)
    {
        std::unique_lock<std::mutex> lm(m);
        return vis[v];
    };

    template <typename T,size_t N>
    void semaphoreQueue<T,N>::shutdown()
    {
        std::unique_lock<std::mutex> lm(m);
        end=true;
        cv.notify_all();
    };

    template <typename T,size_t N>
    int semaphoreQueue<T,N>::size()
    {
        std::unique_lock<std::mutex> lm(m);
        return Q.size();
    };


    template <typename T,size_t N>
    bool semaphoreQueue<T,N>::V(T v)
    {
        if(v>N) return false;
        std::unique_lock<std::mutex> lm(m);
        if(vis[v]) return false;
        vis[v]=true;
        Q.push(v);
        if(++cnt<=0)
        {
            wakeup++;
            cv.notify_all();
            return true;
        }else
        {
            return true;
        }
        
    };
};
#endif