#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
#define N 500005
using ll=long long;
int n,k,par[N],from,to,head[N],cnt,dist[N],arr_cnt,des,total_dist[N];
bool zhanyou[N],vis[N];
struct edge{
    int to;
    int next;
}e[2*N];
void add(){
    e[++cnt].to=to;
    e[cnt].next=head[from];
    head[from]=cnt;

    e[++cnt].to=from;
    e[cnt].next=head[to];
    head[to]=cnt;
}
void bfs(){
    queue<int> Q;
    Q.push(1);
    Q.push(-1);
    int level=0;
    vis[1]=true;
    int cur;
    while(!Q.empty()){
        cur=Q.front();
        Q.pop();
        if(cur==-1){
            if(Q.empty()) break;
            level++;
            Q.push(-1);
            continue;
        }
        dist[cur]=level;
        for(int i=head[cur];i;i=e[i].next){
            if(vis[e[i].to]) continue;
            vis[e[i].to]=true;
            par[e[i].to]=cur;
            Q.push(e[i].to);
        }
    }
}
void dfs(int fa,int cur,int level){
    vis[cur]=true;
    par[cur]=fa;
    dist[cur]=level;
    total_dist[cur]=level;
    for(int i=head[cur];i;i=e[i].next){
        if(vis[e[i].to]) continue;
        dfs(cur,e[i].to,level+1);
        total_dist[cur]+=total_dist[e[i].to];
    }
    vis[cur]=false;
}
int arr[N];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&from,&to);
        add();
    }
    for(int i=0;i<k;i++){
        scanf("%d",arr+i);
        zhanyou[arr[i]]=true;
    }
    //bfs();
    //memset(vis,0,n+1);
    dfs(0,1,0);
    sort(arr,arr+k,[&](int& a,int&b){
        if(dist[a]!=dist[b]) return dist[a]<dist[b];
        else return total_dist[a]>total_dist[b];
    });
    ll ans=0;
    for(int i=0;i<k;i++){
        des=arr[i];
        while(par[des] && !zhanyou[par[des]]){
            des=par[des];
        }
        zhanyou[arr[i]]=false;
        zhanyou[des]=true;
        //printf("%d:%d ->%d:%d\n",arr[i],dist[arr[i]],des,dist[des]);
        ans+=dist[des];
    }
    printf("%lld\n",ans);
}


