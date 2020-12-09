#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;
int n,ans;
int dp[100000];
int p,l,d;
struct node{
    int p,l,d;
}e[100];
int main(){
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&e[i].p,&e[i].l,&e[i].d);
        getchar();
    }
    sort(e,e+n,[](node&a,node&b){
        return a.d<b.d;
    });
    for(int j=0;j<n;j++){
        for(int i=e[j].d-e[j].l+1;i>=e[j].l;i--){
            dp[i]=max(dp[i],dp[i-e[j].l]+e[j].p);
            ans=max(ans,dp[i]);
        }
    }
    printf("%d\n",ans);
}