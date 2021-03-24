#include <stdio.h>
#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <chrono>
#include <unordered_set>
void temp(){
    std::this_thread::sleep_for(std::chrono::seconds(5));
}
int main(int argv,char*argc[]){
    using ll=long long;
    ll beg=std::clock();
    auto last=[&]()->ll{
        return (std::clock()-beg)/CLOCKS_PER_SEC;
    };
    auto pri=[&]()->void{
        ll k=last();
        if(k%5!=0) return;
        printf("%have already running: %llds\n",k);
    };
    srand(time(0));
    std::unordered_set<std::thread> kk;
    while(last()<=100){

    }
    return 0;
}





/*
//主线程
while(true){
    //1、检查是否需要开启新的线程
    //2、将新开启的线程加入到一个unordered_set<thread>中去

    //3、检查是否有结束的线程，
}
*/