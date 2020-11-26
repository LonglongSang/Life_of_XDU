//https://www.luogu.com.cn/problem/P1853#sub
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
//完全背包问题
#define N 20000005
int dp[N],s,n,d,cost[10],money[10];
int main(){
    scanf("%d%d%d",&s,&n,&d);
    for(int i=0;i<d;i++){
        scanf("%d%d",cost+i,money+i);
    }
    for(int i=0;i<n;i++){
        memset(dp,0,(s+1)*4);//这句话可要可不要
        for(int i=0;i<d;i++){
            for(int j=cost[i];j<=s;j++) dp[j]=max(dp[j],dp[j-cost[i]]+money[i]);
        }
        s+=dp[s];
    }
    printf("%d\n",s);
}