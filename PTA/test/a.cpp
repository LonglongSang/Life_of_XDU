#include<stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define N 1000005
//1加2查询
int n,q;
using ll=long long;
ll t[N];
int lowbit(int x){return x&(-x);}
void add(int i,int v){
    for(;i<n+1;i+=lowbit(i)) t[i]+=v;
}
ll sum(int i){
    ll ans=0;
    for(;i;i-=lowbit(i)) ans+=t[i];
    return ans;
}
int main(){
    scanf("%d %d\n",&n,&q);
    int j=0,v,typ,l,r;
    for(int i=1;i<=n;i++){
        scanf("%d",&v);
        t[i]+=v;
        j=i+lowbit(i);
        if(j<n+1) t[j]+=t[i];
    }
    for(int i=0;i<q;i++){
        scanf("%d%d%d",&typ,&l,&r);
        if(typ==1){
            add(l,r);
        }else{
            printf("%lld\n",sum(r)-sum(l-1));
        }
    }

    return 0;
}