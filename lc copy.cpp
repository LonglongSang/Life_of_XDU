#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <queue>
#define N 20005

using ll=long long;
ll a,b,cnt;
int getsum(ll a,int typ){//求数位和
    int ans=0;
    while(a){
        ans+=a%10;
        a/=10;
    }
    return typ==1?ans*ans:ans;
}

void bfs(){
    queue<ll> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    ll cur;
    while(!Q.empty()){
        cur=Q.front();
        if(cur>b) continue;
        if(cur>=a && cur<=b && getsum(cur,1)==getsum(cur*cur,2)) cnt++;
        for(int i=0;i<4;i++){
            Q.push(cur*10+i);
        }
    }
}
int main(){
    scanf("%lld %lld\n",&a,&b);
    bfs();
    printf("%lld\n",cnt);
}



