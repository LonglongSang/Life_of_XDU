//https://loj.ac/problem/133
#include<stdlib.h>
#include <stdio.h>
using namespace std;

#define N (1<<12)+1
//1加2查询
int n,m;
using ll=long long;
ll t[N][N];
int lowbit(int x){return x&(-x);}
void add(int x,int y,int v){
    int _y;
    while(x<n+1){
        _y=y;
        while(_y<m+1) t[x][_y]+=v,_y+=lowbit(_y);
        x+=lowbit(x);
    }
}
ll sum(int x,int y){
    ll ans=0;
    int _y;
    while(x){
        _y=y;
        while(_y) ans+=t[x][_y],_y-=lowbit(_y);
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    scanf("%d %d\n",&n,&m);
    int typ,v,a,b,c,d;
    while(scanf("%d%d%d%d",&typ,&a,&b,&c)!=EOF){
        if(typ==1){
            add(a,b,c);
        }else{
            scanf("%d",&d);
            printf("%lld\n",sum(c,d)-sum(c,b-1)-sum(a-1,d)+sum(a-1,b-1));
        }
    }
    return 0;
}