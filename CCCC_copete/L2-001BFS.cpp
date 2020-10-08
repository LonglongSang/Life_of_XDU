#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;
#define SIZE 100000
int head[SIZE],have[SIZE],dist[SIZE],last[SIZE],way_num[SIZE],can_have[SIZE];
bool vis[SIZE];
int n,m,start,des,from,to,cost,cnt;
struct{
    int next;
    int to;
    int cost;
}arr[100000];

void add(){
    arr[++cnt].to=to;
    arr[cnt].cost=cost;
    arr[cnt].next=head[from];
    head[from]=cnt;
    
    arr[++cnt].to=from;
    arr[cnt].cost=cost;
    arr[cnt].next=head[to];
    head[to]=cnt;
}

struct edge{
    int from;
    int to;
    int cost;
    bool operator < (const edge& b)const{
        if(cost!=b.cost) return cost>b.cost;
        return way_num[from]<way_num[b.from];
    }
};
int main() {
    scanf("%d %d %d %d\n",&n,&m,&start,&des);
    start++;
    des++;
    for(int i=1;i<=n;i++){
        scanf("%d",have+i);
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d\n",&from,&to,&cost);
        from++;
        to++;
        add();
    }
    int inf=0x7fffffff;
    for(int i=0;i<=n;i++) dist[i]=inf;
    dist[0]=0;
    way_num[0]=1;
    //int dist[SIZE],last[SIZE],way_num[SIZE],can_have[SIZE];
    priority_queue<edge,vector<edge>> Q;
    edge cur={0,start,0};
    Q.push(cur);
    while(!Q.empty()){
        cur=Q.top();
        Q.pop();
        if(cur.cost+dist[cur.from]>dist[cur.to]) continue;
        way_num[cur.to]+=way_num[cur.from];
        if(cur.cost+dist[cur.from]==dist[cur.to]) continue;
        dist[cur.to]=dist[cur.from]+cur.cost;
        last[cur.to]=cur.from;
        for(int i=head[cur.to];i;i=arr[i].next){
            int dir=arr[i].to;
            if(dist[cur.to]+arr[i].cost>dist[arr[i].to]) continue;
            Q.push({cur.to,arr[i].to,arr[i].cost});
        }
    }
    int path[SIZE];
    int cnt=0;
    int a=0;
    int b=des;
    while(b){
        path[cnt++]=b;
        a+=have[b];
        a--;
        b=last[b];
    }
    //for(int i=0;i<=n;i++) cout<<i<<" "<<way_num[i]<<endl;
    printf("%d %d\n",way_num[des],a);
    for(int i=0;i<cnt;i++){
        if(i) printf(" %d",path[cnt-i-1]-1);
        else printf("%d",path[cnt-i-1]-1);
    }
    return 0;
}