#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string.h>
using namespace std;
#define N 80000000

#define I 100000
#define T 10000
#define R 0xffffffff

#define n 10
uint32_t unExist,fakePos,pos,inserted;

uint32_t mod[n]={10000967,8100881,8000899,7679323,6500887,5900813,5000777,4000889,3500891,3000979};
uint32_t sum[n];
char val[8];
char filter[N/8+1];
//bool vis[R];
char* vis;

/**
 * I为预先插入次数
 * T是test次数
 * R为测试数据值的范围
 * 
 * 布尔测试器：
 * unExist,不存在的数
 * pos 存在，真阳性
 * fakePos 不存在但是误报，假阳性
 */ 

void init(){
    sum[0]=0;
    for(int i=1;i<n;i++) sum[i]+=sum[i-1]+mod[i];
    val[0]=1;
    for(int i=1;i<8;i++) val[i]=val[i-1]<<1;
}
void insert(uint32_t & value){
    int mapping;
    for(int i=0;i<n;i++){
        mapping=value%mod[i]+sum[i];
        filter[mapping/8]|=val[mapping%8];
    }
    if((vis[value/8]&val[value%8])==0) inserted++;
    vis[value/8]|=val[value%8];
}
void check(uint32_t& value){
    int mapping;
    bool unDiscovery=false;
    for(int i=0;i<n && !unDiscovery;i++){
        mapping=value%mod[i]+sum[i];
        if((filter[mapping/8]&val[mapping%8])==0) unDiscovery=true;
    }
    if(unDiscovery){
        unExist++;
    }else{
        if(vis[value/8]&val[value%8]) pos++;
        else fakePos++;
    }
}
int main()
{
    vis=new char[R/8+1];
    memset(vis,0,(R/8+1)*sizeof(char));    
    uint64_t beg=clock();
    init();
    srand(time(0));
    uint32_t val;
    for(uint32_t i=0;i<I;i++){
        val=rand()%R;
        insert(val);
    }
    for(uint32_t i=0;i<T;i++){
        val=rand()%R;
        check(val);
    }
    //getchar();
    delete [] vis;
    uint64_t en=clock();
    uint64_t per=CLOCKS_PER_SEC;
    printf("total running time: %lf s\n",(double)(en-beg)/per);
    printf("total existed value: %u\n",inserted);
    printf("total test times: %u\n",T);
    printf("unExist: %d\n",unExist);
    printf("Fake Positive: %d\n",fakePos);
    printf("Positive: %d\n",pos);
    printf("wrong percent: %lf %%\n",(double)fakePos/T*100);
    //getchar();
    return 0;
}