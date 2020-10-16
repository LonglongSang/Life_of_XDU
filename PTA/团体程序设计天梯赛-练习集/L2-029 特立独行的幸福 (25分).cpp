#include <stdio.h>
#include <iostream>
#include <vector>
#include  <unordered_set>
#include <set>
#include <map>
#include <math.h>
using namespace std;
int dp[10005],par[10005],path[1000];
int cnt;
int getnext(int a){
    int ans=0;
    while(a){
        ans+=(a%10)*(a%10);
        a/=10;
    }
    return ans;
}
int isok(int a){
    for(int i=2;i<=(int)sqrt(a);i++){
        if(a%i==0) return 1;
    }
    return 2;
}
int main(){
    int a,b;
    scanf("%d %d\n",&a,&b);
    for(int i=b;i>=a;i--){
        if(dp[i]) continue;
        unordered_set<int> vis;
        int a=i;
        cnt=0;
        while(!vis.count(a)){
            path[cnt++]=a;
            vis.insert(a);
            a=getnext(a);
        }
        if(path[cnt-1]==1){
            for(int j=cnt-1;j>=0;j--){
                dp[path[j]]=cnt-1-j;
            }
            for(int j=1;j<cnt;j++) par[path[j]]=path[j-1];
        }
    }
    bool good=false;
    for(int i=a;i<=b;i++){
        if(dp[i]==0 || par[i]) continue;
        printf("%d %d\n",i,dp[i]*isok(i));
        good=true;
    }
    if(good) return 0;
    printf("SAD\n");
    return 0;
}