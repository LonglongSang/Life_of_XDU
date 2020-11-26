//https://www.acwing.com/problem/content/3/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n,v,a,b;
int dp[1001];
int main(){
    scanf("%d%d",&n,&v);
    
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        for(int i=a;i<=v;i++) dp[i]=max(dp[i],dp[i-a]+b);    
    }
    printf("%d\n",dp[v]);
}