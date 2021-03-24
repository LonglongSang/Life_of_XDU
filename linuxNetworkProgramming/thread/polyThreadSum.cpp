#include<stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <string.h>
#include <thread>
#include <time.h>
int N=10000;
#define INF 0x7fffffff
int G;
int* arr;
using ll=long long;
void getSum(int* arr,int l,int r,ll& sum){
    sum=0;
    for(int i=l;i<r;i++) sum+=arr[i];
}
void monoThread(){
    ll beg=clock();
    std::cout<<"This is mono thread test"<<std::endl;
    int l,r;
    int group=G>N?N:G;
    int num=N/group;
    int dev=N%group;
    ll sum=0,temp;
    for(int i=0;i<group && 0;i++){
        l=num*i;
        r=num*(i+1)+(i+1<=dev?1:0);
        getSum(arr,l,r,temp);
        sum+=temp;
        std::cout<<"group "<<i<<" left: "<<l<<" right: "<<r<<" sum: "<<temp<<std::endl;
    }
    getSum(arr,0,N,sum);
    std::cout<<"mono thread sum is "<<sum<<std::endl;
    ll end=clock();
    std::cout<<"totaly running time: "<<(double)(end-beg)/CLOCKS_PER_SEC*1000<<" ms"<<std::endl;
    std::cout<<std::endl;
}
void polyThread(){
    ll beg=clock();
    std::cout<<"This is poly thread test, will use "<<(G>N?N:G)<<" thread to run"<<std::endl;
    int l,r;
    int group=G>N?N:G;
    int num=N/group;
    int dev=N%group;
    ll sum=0;
    std::vector<ll> groupSum(group);
    std::vector<std::thread> ts;
    for(int i=0;i<group;i++){
        l=num*i;
        r=num*(i+1)+(i+1<=dev?1:0);
        ts.push_back(std::thread(getSum,arr,l,r,std::ref(groupSum[i])));
    }
    for(int i=0;i<group;i++){
        ts[i].join();
        l=num*i+(i<dev?i:dev);
        r=num*(i+1)+(i<dev?i+1:dev);
        std::cout<<"group "<<i<<" left: "<<l<<" right: "<<r<<" sum: "<<groupSum[i]<<std::endl;
        sum+=groupSum[i];
    }
    std::cout<<"poly thread sum is "<<sum<<std::endl;
    ll end=clock();
    std::cout<<"totaly running time: "<<(double)(end-beg)/CLOCKS_PER_SEC*1000<<" ms"<<std::endl;
    std::cout<<std::endl;
}
void initData(){
    
    //G=10;
    printf("your computer's hardware concurrency is: %d\n",std::thread::hardware_concurrency());
    printf("will new a %d size int array\n",N);
   
    srand(time(0));
    arr=new int[N];
    if(arr==nullptr) exit(1);
    for(int i=0;i<N;i++) arr[i]=rand()%INF;
    putchar('\n');
}
int main(int argc,char* argv[]){
    G=std::thread::hardware_concurrency();
    if(argc>=2) N=atoi(argv[1]);
    if(argc==3) G=atoi(argv[2]);
    initData();

    monoThread();

    polyThread();

    getchar();

    delete [] arr;
    return 0;

}