#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <unordered_map>
#include <mysql.h>
#include <string.h>
using namespace std;
using ll=long long;
int main(){

    return 0;
}




#define N 58
bool vis[N][100][100];
bool vis2[N][N];
int mp[100][100];
int m[100][100];
int dist[N][N];
int o,st,des,inf=0x3f3f3f3f,cnt;
struct node1{
    int x,y,index;
}dp[58];
struct node2{
    int index,tag,dist;
};
struct cmp{
    bool operator ()(node2 a,node2 &b){
        return a.dist>b.dist;
    }
};
class Solution {
public:
    int r,c;

    int dir[4][2]={0,1,1,0,-1,0,0,-1};
    void build(vector<string>& maze){
        memset(vis,0,N*100*100);
        memset(dist,0x3f,58*58*4);
        queue<node1> Q;
        cnt=0;
        int x=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(maze[i][j]!='#' && maze[i][j]!='.'){
                    if(maze[i][j]=='M') m[i][j]=x++;
                    else if(maze[i][j]=='S') st=cnt;
                    else if(maze[i][j]=='T') des=cnt;
                    mp[i][j]=cnt;
                    dp[cnt]={i,j,1};
                    vis[cnt][i][j]=true;
                    Q.push({i,j,cnt++});
                }
            }
        }
        int cost=1,x,y;
        node1 cur;
        node1 level_end={-1,-1,-1};
        while(!Q.empty()){
            cur=Q.front();
            Q.pop();
            if(cur.x==-1){
                if(Q.empty()) break;
                cost++;
                Q.push(level_end);
                continue;
            }
            for(int i=0;i<4;i++){
                x=cur.x+dir[i][0],y=cur.y+dir[i][1];
                if(x<0 || x>=r || y<0 || y>=c || maze[x][y]=='#' || vis[cur.index][x][y]) continue;
                if(maze[x][y]!='.') dist[cur.index][mp[x][y]]=cost;
                vis[cur.index][x][y]=true;
            }
        }
    }
    int des_tag(){
        int ret=0;
        for(int i=0;i<o;i++) ret|=1<<i;
        return ret;
    }
    void O2M(priority_queue<node2,vector<node2>,cmp> &Q,vector<string>& maze,node2& cur,char want){
        for(int i=0;i<cnt;i++){
            if(maze[dp[i].x][dp[i].y]==want && dist[cur.index][i]!=inf){
                if(want=='M') Q.push({i,cur.tag|(1<<m[dp[i].x][dp[i].y]),cur.dist+dist[cur.index][i]});
                else Q.push({i,cur.tag,cur.dist+dist[cur.index][i]});
            }
        }
    }
    int bfs(vector<string>& maze){
        priority_queue<node2,vector<node2>,cmp> Q;
        //for(int i=0;i<cnt;i++) if(maze[dp[i].x][dp[i].y]=='O' && dist[st][i]!=inf) Q.push({i,0,dist[st][i]});
        Q.push({st,0,0});
        node2 cur;
        //index tag dist
        int end_tag=des_tag();
        while(Q.empty()){
            cur=Q.top();
            Q.pop();
            if(cur.tag==end_tag && cur.index==des) return cur.dist;
            char v=maze[dp[cur.index].x][dp[cur.index].y];
            if(v=='S') O2M(Q,maze,cur,'O');
            else if(v=='O') O2M(Q,maze,cur,'M');
            else if(v=='M' && cur.tag==end_tag) O2M(Q,maze,cur,'T');
            else O2M(Q,maze,cur,'O');
        }
        return 0;
    }
    int minimalSteps(vector<string>& maze) {
        r=maze.size(),c=maze[0].length();
        build(maze);
        return bfs(maze);
    }
};








