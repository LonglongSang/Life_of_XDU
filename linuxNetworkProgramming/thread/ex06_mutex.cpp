#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <functional>
#include <time.h>

#define G 10
#define N 10000000


void add(int cnt,int& sum){
    for(int i=0;i<cnt;i++) sum++;
}
void timeSand(std::function<void(int&)> func,int& sum){
    long long beg=clock();
    func(sum);
    long long end=clock();
    printf("cost time: %.1lf ms\n",(double)(end-beg)/CLOCKS_PER_SEC*1000);
}
void mono(int &sum){
    //单线程模拟求操作次数，正确
    for(int i=0;i<G;i++){
        add(N,sum);
    }
}
void polyBad(int&sum){
    //多线程模拟求操作次数，出错，因为多线程访问sum的时候没有加锁
    std::vector<std::thread> arr;
    for(int i=0;i<G;i++){
        arr.push_back(std::thread(add,N,std::ref(sum)));
    }
    for(auto&e:arr) e.join();
}
void polyGood(int& sum){
    //多线程模拟求操作次数，正确，但是耗时比单线程还多，因为每次操作都加锁，导致耗时增多
    std::mutex ex;
    std::vector<std::thread> arr;
    auto add=[](int tot,std::mutex& ex,int& sum)->void{
        for(int i=0;i<tot;i++){
            ex.lock();
            sum++;
            ex.unlock();
        }
    };
    for(int i=0;i<G;i++){
        arr.push_back(std::thread(add,N,std::ref(ex),std::ref(sum)));
    }
    for(auto&e:arr) e.join();   
}

void polyGoodImprove01(int &sum){
    //多线程模拟求操作次数，正确，在合适的地方加锁
    std::mutex ex;
    std::vector<std::thread> arr;
    auto add=[](int tot,std::mutex& ex,int& sum)->void{
        int tempSum=0;
        for(int i=0;i<tot;i++){
            tempSum++;
        }
        ex.lock();
        sum+=tempSum;
        ex.unlock();
    };
    for(int i=0;i<G;i++){
        arr.push_back(std::thread(add,N,std::ref(ex),std::ref(sum)));
    }
    for(auto&e:arr) e.join();   
}
void polyGoodImprove02(int &sum){
    //多线程模拟求操作次数，正确，在合适的地方加锁
    std::mutex ex;
    std::vector<std::thread> arr;
    auto add=[](int tot,std::mutex& ex,int& sum)->void{
        int tempSum=0;
        for(int i=0;i<tot;i++){
            tempSum++;
        }
        std::lock_guard<std::mutex> guard(ex);
        /**
         * 请参考polyGoodImprove01中对ex进行的操作ex.lock(),ex.unlock()
         * 这里使用了lock_guard,他会从生命的地方开始自动加锁，
         * 运行到他的生命周期结束，析构函数会自动解锁
         */
        sum+=tempSum;
    };
    for(int i=0;i<G;i++){
        arr.push_back(std::thread(add,N,std::ref(ex),std::ref(sum)));
    }
    for(auto&e:arr) e.join();   
}
int main(int argv,char* argc[]){
    int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;

    //mono(sum1);
    timeSand(mono,sum1);
    printf("mono's sum = %d\n\n",sum1);
    
    //polyBad(sum2);
    timeSand(polyBad,sum2);
    printf("poly bad's sum = %d\n\n",sum2);
    
    //polyGood(sum3);
    timeSand(polyGood,sum3);
    printf("poly good's sum = %d\n\n",sum3);


    //polyGoodImprove01(sum4);
    timeSand(polyGoodImprove01,sum4);
    printf("poly good improve01's sum = %d\n\n",sum4);

    //polyGoodImprove02(sum5);
    timeSand(polyGoodImprove02,sum5);
    printf("poly good improve02's sum = %d\n\n",sum5);
    return 0;
}


