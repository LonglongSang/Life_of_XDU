#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
using namespace std;
#define N 55
int n;
char grid[N][N];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int getsum(){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) if(grid[i][j]=='.') ans++;
    }
    return ans;
}
//红X，绿O
struct node{
    int x,y;
};
bool vis[N][N];
bool isok(int x,int y,int num){
    int k=0;
    int r,c;
    for(int i=0;i<4;i++){
        r=x+dir[i][0],c=y+dir[i][1];
        if(r<0 || r>=n || c<0 || c>=n || grid[r][c]=='X') k++;
    }
    return k>=num;
}
int main(){
	scanf("%s",grid[0]);
	n=strlen(grid[0]);
	for(int i=1;i<n;i++) scanf("%s",grid[i]);
    int ans=getsum(),temp,r,c;
    queue<node> Q;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
            if(grid[i][j]=='O' && isok(i,j,3)){
                Q.push({i,j});
            }
        }
    }
    Q.push({-1,-1});
    node cur;
    while(!Q.empty()){
        cur=Q.front();
        Q.pop();
        if(cur.x==-1){
            if(Q.empty()) break;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]=='O' && isok(i,j,3))Q.push({i,j});
                }
            }
            Q.push({-1,-1});
            continue;
        }
        grid[cur.x][cur.y]='.';
        for(int i=0;i<4;i++){
            r=cur.x+dir[i][0],c=cur.y+dir[i][1];
            if(r<0 || r>=n || c<0 || c>=n) continue;
            grid[r][c]='X';
        }
    }
    temp=getsum();
    ans=max(ans,temp);
	printf("%d\n",ans);
  	return 0;
}
