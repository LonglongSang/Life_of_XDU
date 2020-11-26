//https://www.acwing.com/problem/content/280/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
//01背包问题变形
int n,m,dp[10001],a;
int main(){
    dp[0]=1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        for(int i=m;i>=a;i--) dp[i]+=dp[i-a];
    }
    printf("%d\n",dp[m]);
    return 0;
}