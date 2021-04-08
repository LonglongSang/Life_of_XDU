#ifndef DELAY_QUEUE_H
#define DELAY_QUEUE_H
#include <time.h>
#include <condition_variable>
#include <mutex>
#include <bitset>
#include <queue>
#include <signal.h>
#include <unistd.h>
#include <iostream>
#define SIGALRM 14

namespace sang
{
    template <typename T>
    class delayQueue
    {
        private:
            int cnt;
            int wakeup;
            std::bitset<65536> vis;
            bool shutdowned;
        public:
            bool haveShutdown();
            delayQueue();
            ~delayQueue();
            bool V(T v,time_t delay);
            void shutdown();
            int size();
            bool inQueue(T v);
            T P();
            struct cmp
            {
                bool operator()(std::pair<T,time_t>&a,std::pair<T,time_t>&b);
            };
            std::priority_queue<std::pair<T,time_t>,std::vector<std::pair<T,time_t>>,cmp> Q;
            
    };
    static bool __DELAY_QUEUE_canDo;
    static std::mutex __DELAY_QUEUE_MUTEX;
    static std::condition_variable __DELAY_QUEUE_CV;
    static void __DELAY_QUEUE_HANDLE(int a)
    {
        std::unique_lock<std::mutex> lm(__DELAY_QUEUE_MUTEX);
        __DELAY_QUEUE_canDo=true;
        std::cout<<"alarm"<<std::endl;
        __DELAY_QUEUE_CV.notify_all();
    }
};
template <typename T>
bool sang::delayQueue<T>::cmp::operator()(std::pair<T,time_t>&a,std::pair<T,time_t>&b){
    return a.second>b.second;
};
template <typename T>
sang::delayQueue<T>::delayQueue()
{
    cnt=0;
    wakeup=0;
    shutdowned=false;
    signal(SIGALRM,__DELAY_QUEUE_HANDLE);
    __DELAY_QUEUE_canDo=true;
};

template <typename T>
void sang::delayQueue<T>::shutdown()
{
    shutdowned=true;
    __DELAY_QUEUE_CV.notify_all();
};
template <typename T>
bool sang::delayQueue<T>::haveShutdown()
{
    return shutdowned;
};
template <typename T>
int sang::delayQueue<T>::size()
{
    std::unique_lock<std::mutex> lm(__DELAY_QUEUE_MUTEX);
    return Q.size();
};

template <typename T>
bool sang::delayQueue<T>::inQueue(T v)
{
    std::unique_lock<std::mutex> lm(__DELAY_QUEUE_MUTEX);
    return vis[v];
};
template <typename T>
sang::delayQueue<T>::~delayQueue()
{

};

template <typename T>
T sang::delayQueue<T>::P()
{
    time_t cur;
    std::unique_lock<std::mutex> lm(__DELAY_QUEUE_MUTEX);
    cnt--;
    while(1)
    {
        __DELAY_QUEUE_CV.wait(lm,[&](){
            return shutdowned || ((cnt>=0 || wakeup>0) && __DELAY_QUEUE_canDo);
        });
        if(shutdowned) break;
        time(&cur);
        if(Q.top().second>cur)
        {
            __DELAY_QUEUE_canDo=false;
            time(&cur);
            time_t x=Q.top().second-cur;
            alarm(x);
            continue;
        }
        if(cnt<0) wakeup--;
        break;
    }
	T temp=Q.top().first;
	Q.pop();
    vis[temp]=false;
	return temp;
}
template <typename T>
bool sang::delayQueue<T>::V(T v,time_t delay)
{
    time_t wantTime;
    time(&wantTime);
    wantTime+=delay;
    std::unique_lock<std::mutex> lm(__DELAY_QUEUE_MUTEX);
    if(vis[v]) return false;
    vis[v]=true;
    if(!__DELAY_QUEUE_canDo && Q.size() && Q.top().second>wantTime)
    {
        time_t cur;
        time(&cur);
        alarm(int(wantTime-cur));
    }
    Q.push({v,wantTime});
    if(++cnt<=0)
    {
        wakeup++;
        __DELAY_QUEUE_CV.notify_all();
    }
	return true;
};
#endif