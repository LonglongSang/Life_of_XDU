//https://loj.ac/problem/132
#include<stdlib.h>
#include <stdio.h>
#include <iostream>
#define N 1000005
using namespace std;
int n,q,l,r;
using ll=long long;
ll t[N],b[N];
//t[i]=a[i]-a[i-1];
//b[i]=(i-1)*(a[i]-a[i-1]);
int lowbit(int x){return x&(-x);};
void t_add(int i,ll v){
    for(;i<n+1;i+=lowbit(i)) t[i]+=v;
}
void b_add(int i,ll v){
    v=(1-i)*v;
    if(v==0) return;
    for(;i<n+1;i+=lowbit(i)) b[i]+=v;
}
ll sum(int i,ll* a){
    ll ans=0;
    for(;i;i-=lowbit(i)) ans+=a[i];
    return ans;
}

int main(){
    //freopen("G:\\Life_of_XDU\\OiWiki_Learning\\Binary_index_tree\\2.in","r+",stdin);
    //freopen("G:\\Life_of_XDU\\OiWiki_Learning\\Binary_index_tree\\2.out","w",stdout);

    scanf("%d %d\n",&n,&q);
    int j,typ;
    ll last=0,now,v;
    for(int i=1;i<=n;i++){
        scanf("%lld",&now);
        //cout<<now-last<<endl;
        j=i+lowbit(i);
        t[i]+=now-last;
        b[i]+=(now-last)*(1-i);
        if(j<=n) t[j]+=t[i],b[j]+=b[i];
        last=now;
    }

    for(int x=0;x<q;x++){
        scanf("%d%d%d",&typ,&l,&r);
        if(typ==1){
            scanf("%lld",&v);
            t_add(l,v);
            t_add(r+1,-v);
            b_add(l,v);
            b_add(r+1,-v);
        }else{
            //公式
            printf("%lld\n",r*sum(r,t)+sum(r,b)-(l-1)*sum(l-1,t)-sum(l-1,b));
        }
    }
    return 0;
}