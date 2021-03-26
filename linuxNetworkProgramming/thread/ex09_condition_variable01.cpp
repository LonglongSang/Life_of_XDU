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
bool ok;
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
    cv.wait(lm,[]()->bool{return ok;});
    pri(id,2);
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
        ok=true;
        sleep(50);
        pri(typ,2);
        cv.notify_one();
        sleep(100);
        lm.unlock();
        sleep(100);
    }
    t.join();
    return 0;
}

/*
id:thread typ:0 0.00 ms
id:main typ:0 51.00 ms
id:thread typ:1 203.00 ms
id:main typ:1 208.00 ms
id:main typ:2 260.00 ms
id:thread typ:2 358.00 ms
*/
/**
 * test在0ms开始运行，运行到32行将m进行上锁，主进程休眠50ms在51ms左右运行到47行，此时m被上锁，main线程被阻塞
 * 
 * test线程在34休眠200ms后，在203ms运行到36行，此时test线程会调用条件变量cv进行wait（直到有人发送notify信息，并且ok被设置为true），
 * 同时会将m的锁unlock
 * 
 * 在5ms后，也就是208ms，main线程发现m已经被解锁，此时开始继续从47行开始运行，并在49行将ok设置为true
 * 
 * 可以看到我们208ms已经将ok设置为true，但是可以看到test线程并没有在208ms左右被唤醒，还被卡在wait处（36行）
 * 
 * 在main线程处，50行休眠了50ms，在260ms对cv变量进行了notify_one，此时test线程在36行处会收到信息，并检查发现ok被设置为true。
 * 但此时互斥锁m还被锁着所以还不能继续运行，当53行（main线程休眠100ms）运行结束，并且54行执行了lm.unlock()对互斥锁m解锁后，
 * test线程才能运行
 * 
 * 
 * 重点:
 * 调用cv.wait后会对锁进行unlock，并被阻塞
 * 
 * 只有当ok被设置为true，并且发送notify_one信息后，同时互斥锁背unlock后，cv.wait处才能继续向下运行
 * 
 * 
 * 
 * 
 * 
 */
