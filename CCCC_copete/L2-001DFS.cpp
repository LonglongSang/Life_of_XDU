#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
using namespace std;
#define SIZE 1000
int head[SIZE],have[SIZE];
bool vis[SIZE];
int n,m,start,des,from,to,cost,cnt;
int min_dist=0x7fffffff;
int max_people=-1;
int ans[SIZE];
int temp[SIZE];
int path_cnt;
int way_cnt;
int max_path_cnt;
struct{
    int next;
    int to;
    int cost;
}arr[10000];

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
void diaoyong(int now,int dist,int people){
    if(dist<min_dist || people>max_people){
        if(dist<min_dist) way_cnt=1;
        else way_cnt++;
        max_people=people;
        max_path_cnt=path_cnt+1;
        for(int i=0;i<path_cnt;i++) ans[i]=temp[i];
        ans[path_cnt]=des;
    }else{
        way_cnt++;
    }
    min_dist=dist;
}
void dfs(int now,int dist,int people){
    if(dist>min_dist) return;
    if(now==des){
        diaoyong(now,dist,people);
        return;
    }
    temp[path_cnt++]=now;
    vis[now]=true;
    for(int i=head[now];i;i=arr[i].next){
        if(vis[arr[i].to]) continue;
        dfs(arr[i].to,dist+arr[i].cost,people+have[arr[i].to]);
    }
    path_cnt--;
    vis[now]=false;
}
int main() {
    scanf("%d %d %d %d\n",&n,&m,&start,&des);
    start++;
    des++;
    for(int i=1;i<=n;i++) scanf("%d",have+i);
    for(int i=0;i<m;i++){
        scanf("%d %d %d\n",&from,&to,&cost);
        from++;
        to++;
        add();
    }
    dfs(start,0,have[start]);
    printf("%d %d\n",way_cnt,max_people);
    for(int i=0;i<max_path_cnt;i++){
        if(i) printf(" %d",ans[i]-1);
        else printf("%d",ans[i]-1);
    }
    return 0;
}