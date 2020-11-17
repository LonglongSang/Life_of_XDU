#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 10005
int n,line,from,to,head[N],last[N],which_line[N],cnt,m,k,belong[N],path[N];
struct node{
    int to;
    int line;
    int next;
}e[30000];
bool vis[N];
void add(){
    e[++cnt].to=to;
    e[cnt].next=head[from];
    e[cnt].line=line;
    head[from]=cnt;

    e[++cnt].to=from;
    e[cnt].next=head[to];
    e[cnt].line=line;
    head[to]=cnt;
}
struct infor{
    int i;//站点
    int last;
    int c;//经停次数
    int ex;//换乘次数
    int line;//乘坐那一趟班车
};
struct cmp{
    bool operator()(infor&a,infor&b){
        if(a.c!=b.c) return a.c>b.c;
        else return a.ex>b.ex;
    }
};
infor ans;
int cost[N],ex[N];
bool bfs(){
    memset(vis,0,N);
    priority_queue<infor,vector<infor>,cmp> Q;
    Q.push({from,0,0,0,-1});
    memset(cost,0x3f,N*4);
    memset(ex,0x3f,N*4);
    infor cur;
    while(!Q.empty()){
        cur=Q.top();
        Q.pop();
        if(cur.c>cost[cur.i] || cur.ex>ex[cur.i]) continue;
        cost[cur.i]=cur.c;
        ex[cur.i]=cur.ex;
        which_line[cur.i]=cur.line;
        last[cur.i]=cur.last;
        if(cur.i==to){
            ans=cur;
            return true;
        }
        for(int i=head[cur.i];i;i=e[i].next){
            int ex_now=e[i].line==cur.line?cur.ex:(cur.ex+1);
            if(cur.c+1>cost[e[i].to] || ex_now>ex[e[i].to]) continue;
            Q.push({e[i].to,cur.i,cur.c+1,ex_now,e[i].line});
        }
    }
    return false;
}
void printf_ans(){
    printf("%d\n",ans.c);
    if(from==to){
        printf("Go by the line of company #%d from %0.4d to %0.4d.\n",belong[from],from-1,to-1);
        return;
    }
    
    int now=to;
    stack<int> S;
    int cnt=0;
    while(now!=from){
        path[cnt++]=now;
        now=last[now];
    }
    path[cnt++]=from;
    reverse(path,path+cnt);
    int rel=0;
    for(int i=0;i<cnt;i++){
        if(i+1==cnt || which_line[path[i]]!=which_line[path[i+1]]) path[rel++]=path[i];
    }
    for(int i=1;i<rel;i++){
        printf("Go by the line of company #%d from %0.4d to %0.4d.\n",which_line[path[i]],path[i-1]-1,path[i]-1);
    }
}

int main(){
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        line=i;
        scanf("%d",&m);
        getchar();
        if(m==0) continue;
        scanf("%d",&from);
        from++;
        belong[from]=line;
        getchar();
        for(int j=1;j<m;j++){
            scanf("%d",&to);
            to++;
            getchar();
            belong[to]=line;
            add();
            from=to;
        }
    }
    scanf("%d\n",&k);
    for(int i=0;i<k;i++){
        scanf("%d %d\n",&from,&to);
        from++,to++;
        if(!bfs()){
            printf("Sorry, no line is available.\n");
        }else{
            printf_ans();
        }
    }
    return 0;
}
