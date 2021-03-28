#include <stdio.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>
int beg;
double getms(int beg)
{
    return (double)(clock()-beg)/CLOCKS_PER_SEC*1000;
}
void pri(std::string id,int typ)
{
    printf("id:%s typ:%d %.2lf ms\n",id.c_str(),typ,getms(beg));
}
void sleep(double t)
{
    int beg=clock();
    while(getms(beg)<=t);
}

class Semaphore
{
public:
    Semaphore(int cnt)
    {
        this->cnt=cnt;
        wakeup=0;
    }
    Semaphore()
    {
        this->cnt=std::thread::hardware_concurrency();
        wakeup=0;
    }
    void setting(int cnt)
    {
        //重新设置
        this->cnt=cnt;
    }
    void P()
    {
        //P操作
        std::unique_lock<std::mutex> lm(m);
        if(--cnt<0)
        {
            cv.wait(lm,[&](void)->bool{return wakeup>0;});
            wakeup--;
        }
    }
    void V()
    {
        //V操作
        std::unique_lock<std::mutex> lm(m);
        if(++cnt<=0)
        {
            wakeup++;
            cv.notify_all();
        }
    }
private:
    std::mutex m;
    std::condition_variable cv;
    int cnt;
    int wakeup;
};


void producer(int id,Semaphore& sema)
{
    pri(std::to_string(id),0);
    sema.P();
    sleep(3000);
    pri(std::to_string(id),1);
    sema.V();
}

#define N 10
int main(int argv,char* argc[])
{
    Semaphore sema(3);
    beg=clock();
    std::thread t[N];
    for(int i=0;i<N;i++) t[i]=std::thread(producer,i,std::ref(sema));
    for(int i=0;i<N;i++) t[i].join();

    return 0;
}