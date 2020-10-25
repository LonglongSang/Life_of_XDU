#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
int n,m;
char grid[1000][1000];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
unordered_map<char,int> mp;
bool vis[1000][1000];
bool canreach(int ori_x,int ori_y,int x,int y){
    if(x>=1 && x<=n && y>=1 && y<=m && !vis[x][y] && dir[grid[x][y]][0]+x==ori_x && dir[grid[x][y]][1]+y==ori_y) return true;
    return false;
}
struct node{
    int x,y;
};
int main() {
    mp['W']=2;
    mp['A']=3;
    mp['S']=0;
    mp['D']=1;
    scanf("%d %d\n",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s\n",grid[i]+1);
        for(int j=1;j<=m;j++){
            grid[i][j]=mp[grid[i][j]];
        }
    }
    queue<node> Q;
    for(int i=1;i<=m;i++){
        Q.push({0,i});
        Q.push({n+1,i});
    }
    for(int i=1;i<=n;i++){
        Q.push({i,0});
        Q.push({i,m+1});
    }
    while(!Q.empty()){
        node cur=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            if(canreach(cur.x,cur.y,cur.x+dir[i][0],cur.y+dir[i][1])){
                vis[cur.x+dir[i][0]][cur.y+dir[i][1]]=true;
                Q.push({cur.x+dir[i][0],cur.y+dir[i][1]});
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j]) ans++;
        }
    }
    cout<<ans<<endl;
	return 0;
}