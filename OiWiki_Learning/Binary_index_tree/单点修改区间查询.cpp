//https://www.luogu.com.cn/problem/P3374
#include<stdlib.h>
#include <stdio.h>
#define N 5*100005
using namespace std;
int n,m,val,typ,x,y;
long long t[N];
int lowbit(int x){ return x&(-x);}
void add(int x,int val){ for(;x<n+1;x+=lowbit(x)) t[x]+=val;}
long long sum(int x){
    long long ans=0;
    for(;x>0;x-=lowbit(x)) ans+=t[x];
    return ans;
}
int main(){
    scanf("%d %d\n",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&val);
        t[i]+=val;
        if(i+lowbit(i)<n+1) t[i+lowbit(i)]+=t[i];//O(n)建树
    }
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&typ,&x,&y);
        if(typ==1){
            add(x,y);
        }else{
            printf("%lld\n",sum(y)-sum(x-1));
        }
    }

    return 0;
}