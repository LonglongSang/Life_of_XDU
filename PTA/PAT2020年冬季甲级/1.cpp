#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <queue>
using namespace std;
using ll=long long;
ll n;
ll fib[100];
ll myabs(ll a,ll b){
    return a>b?a-b:b-a;
}
int main(){
    freopen("C:\\Users\\Administrator\\Desktop\\PAT\\input.txt","r+",stdin);
    fib[0]=0,fib[1]=1;
    scanf("%lld",&n);
    int up=45;
    for(int i=2;i<up;i++) fib[i]=fib[i-1]+fib[i-2];
    for(int i=0;i<up;i++) printf("%d ",fib[i]);
    ll dev=0x7fffffff,ans=0;
    for(int i=0;i<up;i++){
        if(myabs(fib[i],n)<myabs(ans,n)){
            ans=fib[i];
        }
    }
    printf("%lld\n",ans);
}