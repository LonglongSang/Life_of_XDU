//https://www.luogu.com.cn/problem/P2986
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cassert>
#include <iostream>
#include <string.h>
using namespace std;
#define N 100005
using ll=long long;
int n,from,to,weight,p[N],head[N],tot,ans=1;
ll w[N];
struct node{
    int to;
    ll w;
    int next;
}e[N*2];
void add(){
    e[++tot].to=to;
    e[tot].next=head[from];
    e[tot].w=weight;
    head[from]=tot;
    
    e[++tot].to=from;
    e[tot].next=head[to];
    e[tot].w=weight;
    head[to]=tot;
}
void dfs(int cur,int fa){
    for(int i=head[cur];i;i=e[i].next){
        if(fa==e[i].to) continue;
        dfs(e[i].to,cur);
        p[cur]+=p[e[i].to];
        w[cur]+=w[e[i].to]+p[e[i].to]*e[i].w;
    }
}
void second_dfs(int cur,int fa){
    for(int i=head[cur];i;i=e[i].next){
        if(fa==e[i].to) continue;
        w[e[i].to]=w[cur]-p[e[i].to]*e[i].w+(p[1]-p[e[i].to])*e[i].w;
        if(w[e[i].to]<w[ans]) ans=e[i].to;
        second_dfs(e[i].to,cur);
    }
}
int main(){
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        scanf("%d",p+i);
        getchar();
    }
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&from,&to,&weight);
        getchar();
        add();
    }
    dfs(1,0);
    second_dfs(1,0);
    printf("%lld\n",w[ans]);
}