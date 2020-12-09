//https://www.luogu.com.cn/problem/P3478
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;
#define N 1000005
using ll=long long;
int head[N],tot_pos[N],tot,from,to,n,ans;
ll tot_weight[N];
struct node{
    int to;
    int next;
}e[N*2];
void add(int from,int to){
    e[++tot].to=to;
    e[tot].next=head[from];
    head[from]=tot;

    e[++tot].to=from;
    e[tot].next=head[to];
    head[to]=tot;
}
void dfs(int cur,int fa){
    tot_pos[cur]++;
    for(int i=head[cur];i;i=e[i].next){
        int to=e[i].to;
        if(to==fa) continue;
        dfs(to,cur);
        tot_pos[cur]+=tot_pos[to];
        tot_weight[cur]+=tot_weight[to]+tot_pos[to];
    }
}
void second_dfs(int cur,int fa){
    tot_weight[cur]=tot_weight[fa]+tot_pos[1]-2*tot_pos[cur];
    if(tot_weight[cur]>tot_weight[ans]) ans=cur;
    for(int i=head[cur];i;i=e[i].next){
        if(e[i].to==fa) continue;
        second_dfs(e[i].to,cur);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&from,&to);
        add(from,to);
    }
    dfs(1,0);
    tot_weight[0]=tot_weight[1]+tot_pos[1];
    ans=1;
    second_dfs(1,0);
    printf("%d\n",ans);
}