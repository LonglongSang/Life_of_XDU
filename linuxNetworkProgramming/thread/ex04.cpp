#include <stdio.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <time.h>
#include <string>
#include <mutex>//once_falg call_once
/**
 * 一次调用
 * 
 */
void func1(){
    std::cout<<"func1:however your call me, I will only running once\n";
}
void func2(){
    std::cout<<"func2:I am same with func1\n";
}
void threadRun(std::once_flag* flag,void(*func)(void)){
    std::call_once(*flag,func);
}
void testForOnceFlag(){
    std::once_flag flag1;
    std::once_flag flag2;
    std::vector<std::thread> arr;
    for(int i=0;i<5;i++){
        arr.push_back(std::thread(threadRun,&flag1,func1));
    }
    for(int i=0;i<5;i++){
        arr.push_back(std::thread(threadRun,&flag2,func2));
    }
    for(auto&e:arr) e.join();
}
int main(int argc,char* argv[]){
    testForOnceFlag();
    return 0;
}