#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
#define N 105
int x1,y11,x2,y2,r,c,grid[N][N];
bool vis[N][N][2];
bool issame(int x,int y,int typ){
    if(x==x2 && y==y2) return true;
    int k=(x1-x2)*(y-y11)-(y11-y2)*(x-x1);
    if((k>0 && typ==1) || (k<0 && typ==0)) return true;
    return false;
}
struct node{
    int x,y,typ;
    double c=0.0;
};
struct cmp{
    bool operator()(node& a,node& b){
        return a.c>b.c;
    }
};
int dir1[4][2]={1,0,0,1,-1,0,0,-1};
int dir2[4][2]={1,1,1,-1,-1,1,-1,-1};
double extra=sqrt(2)-1.0;
double getans(){
    priority_queue<node,vector<node>,cmp> Q;
    Q.push({x1,y11,1,(double)grid[x1][y11]});
    Q.push({x1,y11,0,(double)grid[x1][y11]});
    node cur;
    double ans=0.0;
    bool ok[2]={false,false};
    int x,y;
    while(!Q.empty() && (!ok[0] || !ok[1])){
        cur=Q.top();
        Q.pop();
        if(vis[cur.x][cur.y][cur.typ] || ok[cur.typ]) continue;
        vis[cur.x][cur.y][cur.typ]=true;
        if(cur.x==x2 && cur.y==y2){
            ok[cur.typ]=true;
            ans+=cur.c;
            continue;
        }
        for(int i=0;i<4;i++){
            x=dir1[i][0]+cur.x,y=dir1[i][1]+cur.y;
            if(x<0 || x>=r || y<0 || y>=c || vis[x][y][cur.typ] || !issame(x,y,cur.typ)) continue;
            Q.push({x,y,cur.typ,cur.c+(double)grid[x][y]});
        }
        for(int i=0;i<4;i++){
            x=dir2[i][0]+cur.x,y=dir2[i][1]+cur.y;
            if(x<0 || x>=r || y<0 || y>=c || vis[x][y][cur.typ] || !issame(x,y,cur.typ)) continue;
            Q.push({x,y,cur.typ,cur.c+(double)grid[x][y]+((double)grid[cur.x][cur.y]+(double)grid[x][y])*extra});
        }
    }
    ans-=(double)grid[x1][y11]+(double)grid[x2][y2];
    return ans;
}
int main(){
    scanf("%d %d\n",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",grid[i]+j);
            getchar();
        }
    }
    scanf("%d %d %d %d\n",&x1,&y11,&x2,&y2);
    swap(x1,y11);
    swap(x2,y2);
    printf("%.2lf\n",getans());
    return 0;
}
