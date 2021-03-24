#include <stdio.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <time.h>
#include <string>
void printTime(){
    auto now=std::chrono::system_clock::now();
    auto b=std::chrono::system_clock::to_time_t(now);
    auto tmvp=localtime(&b);
    printf("now is:%d %d %d %0.2d:%0.2d:%0.2d\n",1900+tmvp->tm_year,tmvp->tm_mon,tmvp->tm_mday,tmvp->tm_hour,tmvp->tm_min,tmvp->tm_sec);
}
void test(std::string typ){
    std::cout<<typ<<" thread's id is "<<std::this_thread::get_id()<<std::endl;
    int sec=2;
    std::cout<<"I will sleep "<<sec*1000<<" ms"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000*sec));
}
int main(int argc,char* argv[]){
    printTime();
    test("main");
    std::thread t(test,"thread");
    t.join();
    return 0;
}