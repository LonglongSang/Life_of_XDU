//https://www.acwing.com/problem/content/description/2/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n,v,a,b,ans;
int dp[1001];
int main(){
    scanf("%d%d",&n,&v);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        for(int i=v;i>=a;i--) dp[i]=max(dp[i],dp[i-a]+b);
    }
    printf("%d\n",dp[v]);
}
