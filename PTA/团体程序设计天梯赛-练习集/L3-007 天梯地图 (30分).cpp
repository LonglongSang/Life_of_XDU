#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
int n,m,cnt,dist,timee,from,to;
int head[505];
struct edge{
    int to;
    int next;
    int dist;
    int time;
}arr[300000];//刚开始开的数组太小了
void add(int from,int to){
    arr[++cnt].to=to;
    arr[cnt].next=head[from];
    arr[cnt].dist=dist;
    arr[cnt].time=timee;
    head[from]=cnt;
}
struct node{
    int from;
    int to;
    int dist;
    int time;
};
struct cmp1{
    bool operator ()(const node&a, const node&b) const{
        if(a.time!=b.time) return a.time>b.time;
        else return a.dist>b.dist;
    }
};
int last[505],time_path[505],dist_path[505];
int time_cnt,dist_cnt;
void get_time(int* path,int* now_cnt,int *val){
    priority_queue<node,vector<node>,cmp1> Q;
    //cout<<from<<" "<<to<<endl;
    Q.push({0,from,0,0});
    for(int i=0;i<=n;i++) last[i]=-1;
    while(!Q.empty()){
        node cur=Q.top();
        Q.pop();
        if(last[cur.to]!=-1) continue;
        last[cur.to]=cur.from;
        if(cur.to==to){
            *val=cur.time;
            break;
        }
        for(int i=head[cur.to];i;i=arr[i].next){
            if(last[arr[i].to]!=-1) continue;
            Q.push({cur.to,arr[i].to,cur.dist+arr[i].dist,cur.time+arr[i].time});
        }
    }
    //Time = T; Distance = D: 起点 => 节点1 => ... => 终点
    //return;
    int a=to;
    while(a!=0){
        path[(*now_cnt)++]=a;
        a=last[a];
    }
}
struct pos{
    int from;
    int to;
    int dist;
    int passed;
};
struct cmp2{
    bool operator ()(const pos&a, const pos&b) const{
        if(a.dist!=b.dist) return a.dist>b.dist;
        else return a.passed>b.passed;
    }
};
void get_dist(int* path,int* now_cnt,int *val){
    priority_queue<pos,vector<pos>,cmp2> Q;
    //cout<<from<<" "<<to<<endl;
    Q.push({0,from,0,0});
    for(int i=0;i<=n;i++) last[i]=-1;
    while(!Q.empty()){
        pos cur=Q.top();
        Q.pop();
        if(last[cur.to]!=-1) continue;
        last[cur.to]=cur.from;
        if(cur.to==to){
            *val=cur.dist;
            break;
        }
        for(int i=head[cur.to];i;i=arr[i].next){
            if(last[arr[i].to]!=-1) continue;
            Q.push({cur.to,arr[i].to,cur.dist+arr[i].dist,cur.passed+1});
        }
    }
    int a=to;
    while(a!=0){
        path[(*now_cnt)++]=a;
        a=last[a];
    }
}
bool is_good(){
    if(time_cnt!=dist_cnt) return false;
    for(int i=0;i<time_cnt;i++) if(time_path[i]!=dist_path[i]) return false;
    return true;
}
void pri(int *path,int cnt){
    cnt--;
    printf(" %d",path[cnt--]-1);
    while(cnt!=-1) printf(" => %d",path[cnt--]-1);
    printf("\n");
}
int main(){
    int typ;
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<m;i++){
        //V1 V2 one-way length time
        scanf("%d %d %d %d %d\n",&from,&to,&typ,&dist,&timee);
        from++;
        to++;
        add(from,to);
        if(typ!=1) add(to,from);
    }
    scanf("%d %d\n",&from,&to);
    if(from==to){
        printf("Time = 0; Distance = 0: %d => %d\n",to,to);
        return 0;
    }
    //cout<<from<<" "<<to<<endl;
    from++;
    to++;
    //void get_dist(int* path,int* now_cnt,int *val){
    int time_cost,dist_cost;
    get_time(time_path,&time_cnt,&time_cost);
    get_dist(dist_path,&dist_cnt,&dist_cost);
    if(is_good()){
        printf("Time = %d; Distance = %d:",time_cost,dist_cost);
        pri(time_path,time_cnt);
        return 0;
    }
    printf("Time = %d:",time_cost);
    pri(time_path,time_cnt);
    printf("Distance = %d:",dist_cost);
    pri(dist_path,dist_cnt);
}