#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;


int head[100005],cnt;//初始都为0，head[i]=0，cnt=0
//head[i]表示点i的第一个节点的下标，初始为0表示null
struct edge{
    int to;
    int cost;
    int next;
}e[20000];

void add1(int from,int to,int cost){
    //构建邻接链表
    //from到to之间有一条权值为cost的边
    e[++cnt].to=to;
    e[cnt].cost=cost;
    e[cnt].next=head[from];
    head[from]=cnt;//对head[from]进行头插法
}





struct link_edge{
    int to;
    int cost;
    link_edge* next;
    link_edge(int t,int c):to(t),cost(c),next(NULL){}
};

link_edge* head1[100005];
//head[i]表示点i的第一个节点的下标，初始为0表示null

void add2(int from,int to,int cost){
    //构建邻接链表
    //from到to之间有一条权值为cost的边
    link_edge* temp=new link_edge(to,cost);
    temp->next=head1[from];
    head1[from]=temp;//对head[from]进行头插法
}




int main(){

}



#define N 1000
int can_reach[N][N];
bool vis[N];

void bfs(int cur){
    //从点cur开始广度优先访问图
    memset(vis,0,N);
    queue<int> Q;
    Q.push(cur);
    Q.push(-1);//作为层标记
    while(!Q.empty()){
        cur=Q.front();
        Q.pop();
        if(cur==-1){
            if(Q.empty()) break;//队列空了
            Q.push(-1);//再重新打入层标记
            cout<<"this is new level"<<endl;
            continue;
        }
        if(vis[cur]) continue;
        vis[cur]=true;
        cout<<"vis in "<<cur<<endl;
        for(int i=0;i<N;i++){
            if(vis[i] || !can_reach[cur][i]) continue;
            Q.push(i);
        }
    }
}


void dfs(int cur){
    vis[cur]=true;
    cout<<"vis in "<<cur<<endl;
    for(int i=0;i<N;i++){
        if(vis[i] || !can_reach[cur][i]) continue;
        dfs(i);
    }
    vis[cur]=false;
}