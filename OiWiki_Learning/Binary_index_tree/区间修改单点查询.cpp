//https://www.luogu.com.cn/problem/P3368
#include<stdlib.h>
#include <stdio.h>
#define N 5*100005
using namespace std;
int n,m,val,typ,x,y,k;
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
    int last=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&val);
        t[i]+=val-last;
        last=val;//区间修改单点查询利用的是差分数组
        if(i+lowbit(i)<n+1) t[i+lowbit(i)]+=t[i];
    }
    for(int i=0;i<m;i++){
        scanf("%d",&typ);
        if(typ==1){
            scanf("%d%d%d\n",&x,&y,&k);
            add(x,k);
            add(y+1,-k);
        }else{
            //cout<<2<<endl;
            //printf("%d %d %d %d\n",y,sum(y),x-1,sum(x-1));
            scanf("%d\n",&x);
            printf("%lld\n",sum(x));
        }
    }

    return 0;
}