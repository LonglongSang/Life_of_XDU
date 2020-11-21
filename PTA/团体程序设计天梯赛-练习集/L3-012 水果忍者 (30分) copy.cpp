#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define N 20005
using ll=long long;
int n,cnt;
struct node{
    ll x,y1,y2;//y1>y2;
}e[10005];
struct k{
    ll y,x;
    k(ll _y,ll _x):y(_y),x(_x){}
    k(){}
};
ll k_cmp(k &a,k &b){
    return a.y*b.x-a.x*b.y;
}
int main(){
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%lld %lld %lld\n",&e[i].x,&e[i].y1,&e[i].y2);
    }
    sort(e,e+n,[&](node&a,node&b){
        return a.x<b.x;
    });
    int cnt=1;
    for(int i=1;i<n;i++){
        if(e[i].x==e[cnt-1].x){
            if(e[i].y1<e[cnt-1].y1) e[cnt-1].y1=e[i].y1;
            if(e[i].y2>e[cnt-1].y2) e[cnt-1].y2=e[i].y2;
        }else{
            e[cnt++]=e[i];
        }
    }
    n=cnt;
    if(n==1){
        printf("%lld %lld %lld %lld\n",e[0].x,e[0].y1,e[0].x+1,e[0].y1);
        return 0;
    }
    k upper,lower,now;
    for(int i=0;i<n;i++){
        upper={100000,0};
        lower={-100000,0};
        for(int j=0;j<i;j++){
            now={e[j].y2-e[i].y1,e[i].x-e[j].x};
            if(k_cmp(upper,now)>0) upper=now;
            now={e[j].y1-e[i].y2,e[i].x-e[j].x};
            if(k_cmp(lower,now)<0) lower=now;
        }
        for(int j=i+1;j<n;j++){
            now={e[j].y2-e[i].y1,e[j].x-e[i].x};
            if(k_cmp(upper,now)>0) upper=now;
            now={e[j].y1-e[i].y2,e[j].x-e[i].x};
            if(k_cmp(lower,now)<0) lower=now;
        }
        if(k_cmp(upper,lower)>0){
            printf("%lld %lld %lld %lld\n",e[i].x,e[i].y2,e[i].x+lower.x,e[i].y2+lower.y);
            return 0;
        }
    }
    return 0;

}