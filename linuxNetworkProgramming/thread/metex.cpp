#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <functional>
#include <mutex>
#include <thread>
#include <time.h>
#define N 1000000000
int cnt;
std::mutex m;
void testFor_defer_lock()
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    lm.lock();
    for(int i=0;i<N;i++) cnt++;
}
void testFor_try_to_lock()
{
    m.lock();
    std::unique_lock<std::mutex> lm(m,std::try_to_lock);
    //std::try_to_lock会尝试加锁，加锁失败不会阻塞
    if(lm.owns_lock())
    {
        std::cout<<"try to lock failed"<<std::endl;
        //try to lock成功
    }
    else
    {
        //加锁失败
        std::cout<<"try to lock success"<<std::endl;
        lm.lock();
    }
}
int main(int argv,char* argc[])
{
    std::sleep(1);
    testFor_try_to_lock();
}