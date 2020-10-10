#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;
int n,m,k;
struct edge{
    int next;
    int to;
}arr[200000];
int cnt;
int head[10005];
int from,to;
void add(){
    arr[++cnt].to=to;
    arr[cnt].next=head[from];
    head[from]=cnt;

    arr[++cnt].to=from;
    arr[cnt].next=head[to];
    head[to]=cnt;
}
struct node{
    int to;
    int cost;
};
struct cmp{
    bool operator ()(const node&a,const node&b){
        if(a.cost!=b.cost) return a.cost>b.cost;
        else return a.to<b.to;
    }
};
bool vis[10005];

int help(){
    memset(vis,0,n+1);
    int ans=0;
    priority_queue<node,vector<node>,cmp> Q;
    Q.push({from,0});
    //int max_dist=-1;
    while(!Q.empty()){
        node cur=Q.top();
        Q.pop();
        if(vis[cur.to]) continue;
        vis[cur.to]=true;
        ans=cur.to;
        for(int i=head[cur.to];i;i=arr[i].next){
            if(vis[arr[i].to]) continue;
            Q.push({arr[i].to,cur.cost+1});
        }
    }
    printf("%d\n",ans);
}
int main(){
    scanf("%d %d %d\n",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d %d\n",&from,&to);
        add();
    }
    for(int i=0;i<k;i++){
        scanf("%d",&from);
        help();
    }
    return 0;
}