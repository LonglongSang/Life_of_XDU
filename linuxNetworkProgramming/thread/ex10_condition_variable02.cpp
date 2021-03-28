// condition_variable example
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
uint32_t beg;
bool testOk,mainOk;
std::mutex m;
std::condition_variable cv;
std::mutex priLock;
double getms(int beg)
{
    return (double)(clock()-beg)/CLOCKS_PER_SEC*1000;
}
void pri(std::string& id,int typ)
{
    std::lock_guard<std::mutex> l(priLock);
    printf("id:%s typ:%d %.2lf ms\n",id.c_str(),typ,getms(beg));
}
void sleep(double t)
{
    int beg=clock();
    while(getms(beg)<=t);
}

void test(std::string id)
{
    std::unique_lock<std::mutex> lm(m);
    pri(id,0);
    sleep(200);
    pri(id,1);
    cv.wait(lm,[]()->bool{return testOk;});
    pri(id,2);
    sleep(300);
    pri(id,3);
    mainOk=true;
    cv.notify_all();
    //sleep(200);
    pri(id,4);
}
int main ()
{
    beg=clock();
    std::thread t(test,"thread");
    sleep(50);
    std::string typ="main";
    {
        pri(typ,0);
        std::unique_lock<std::mutex> lm(m);
        pri(typ,1);
        testOk=true;
        sleep(50);
        pri(typ,2);
        cv.notify_one();
        sleep(100);
        lm.unlock();
        sleep(50);
        pri(typ,3);
        cv.wait(lm,[](void)->bool{return mainOk;});
        pri(typ,4);
    }
    t.join();
    return 0;
}

