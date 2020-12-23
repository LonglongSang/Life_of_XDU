#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define N 100000
struct customer{
    //用户信息
    int customerId;
    int arriveTime;
    int costTime;
}c[N];
int n;//n个用户
struct infor{
    //排队客户得到服务的信息
    //customerId客户在getServiceTime时间获得服务，并且在柜台被服务了costTime时间
    int customerId;
    int getServiceTime;
    int costTime;
};
struct counter{
    //柜台
    queue<infor> lineUp;//排队序列
    //排队序列
    int finishTime=0;
    //完成时间
};
void generateData(int n){
    //生成数据函数，生成n个客户的输入
    for(int i=0;i<n;i++){
        //printf("%d")
    }
}
void input(){
    /*输入：第一行一个n
    随后n行，每一行两个数字a，b，t
    表示客户a在b时间到达银行，将要办理一个时间长度为t的业务
    注解：我们不保证输入的用户的到达时间升序排序
    */
    //freopen("E:\\mydata\\input.txt","r+",stdin);
    //如果需要从文件读入数据，将上一行注释掉，改为你的输入文件\要双写
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&c[i].customerId,&c[i].arriveTime,&c[i].costTime);
        getchar();
    }
    //因为不保证输入按到达时间升序，所以我们需要进行排序
    sort(c,c+n,[&](customer&a,customer&b){
        return a.arriveTime<b.arriveTime;
    });
}
void bank(int k){
    //生成一个有k个柜台的银
    counter Q[k];
    int getServieTime;
    for(int i=0;i<n;i++){
        int ok_index=0;
        for(int j=0;j<k;j++){
            if(Q[j].finishTime<Q[ok_index].finishTime) ok_index=j;
        }
        getServieTime=max(c[i].arriveTime,Q[ok_index].finishTime);

        Q[ok_index].lineUp.push({c[i].customerId,getServieTime,c[i].costTime});
        Q[ok_index].finishTime=getServieTime+c[i].costTime;
        printf("##########\n");
        printf("customer %d arrive in time %d, ",c[i].customerId,c[i].arriveTime);
        printf("and in time %d get service in counter %d\n",getServieTime,ok_index+1);
        printf("And cost time %d leave in time %d\n",c[i].costTime,Q[ok_index].finishTime);
    
    }

}
int main(){
    input();
    bank(3);
}
/*
测试数据：
8
1 1 1
2 3 4
3 3 5
4 5 8
5 6 4
5 8 4
6 8 6
7 8 10

*/