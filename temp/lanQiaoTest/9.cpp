#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define N 105
int r,c;
bool ok(int i,int j){
    return i>=0 && j>=0 && i<r && j<c;
}
int a,b,t,now,ans;
bool vis[N][N];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int main(){
    cin>>r>>c;
    cin>>t;
    memset(vis,0,sizeof(vis));
    queue<pair<int,int>> Q;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        Q.push({a-1,b-1});
        vis[a-1][b-1]=true;
    }
    cin>>t;
    Q.push({-1,-1});
    pair<int,int> cur;
    int x,y;
    while(now<t && !Q.empty()){
        cur=Q.front();
        Q.pop();
        if(cur.first==-1){
            if(Q.empty()) break;
            now++;
            Q.push({-1,-1});          
            continue;
        }
        for(int i=0;i<4;i++){
            x=cur.first+dir[i][0],y=cur.second+dir[i][1];
            if(!ok(x,y) || vis[x][y]) continue;
            vis[x][y]=true;
            Q.push({x,y});
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(vis[i][j]) ans++;
        }
    }
    cout<<ans<<endl;
}