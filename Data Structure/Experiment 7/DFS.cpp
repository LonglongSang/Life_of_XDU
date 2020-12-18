#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#define N 1000
int n,m;
bool vis[N];
template <typename T>
struct Graph{
    int vecnum=0;
    int arcnum=0;
    T arcs[N][N];
    Graph(int v){
        memset(arcs,v,sizeof(T)*N*N);
    }
    T* operator [](int a){
        return arcs[a];
    }
};

void input(Graph<bool>&g){
    scanf("%d %d\n",&g.vecnum,&g.arcnum);
    int from,to;
    for(int i=0;i<m;i++){
        scanf("%d %d\n",&from,&to);
        g[from][to]=true;
    }
}
void dfs(int cur,Graph<bool>&g){
    vis[cur]=true;
    for(int i=0;i<g.vecnum;i++){
        if(vis[i] || !g[cur][i]) continue;
        dfs(i,g);
    }
    vis[cur]=false;
}
int main(){
    Graph<bool> g(0);
    input(g);
    dfs(0,g);
}