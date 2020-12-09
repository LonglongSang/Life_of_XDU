#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <unordered_map>
#include <mysql.h>
using namespace std;
using ll=long long;
int main(){

    return 0;
}





bool vis[65536][100][100];
int mp[100][100];
int dist[40][16];
struct temp{
    
}
void build(){
    queue<
}
class Solution {
public:
    struct node{
        int x,y,tag;
        bool take;
    }temp,st,des,cur;
    int r,c;
    node get_axis(char v,vector<string>& maze){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(maze[i][j]==v) return {i,j,0,false};
            }
        }
        return temp;
    }
    int num_of_want(vector<string>& maze){
        int ret=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(maze[i][j]=='M') mp[i][j]=ret++;
            }
        }
        return ret;
    }
    int dir[4][2]={1,0,0,1,-1,0,0,-1};
    int bfs(vector<string>& maze){
        queue<node> Q;
        int tot=num_of_want(maze);
        des.tag=end_tag(tot);
        //printf("%d\n",des.tag);
        Q.push(st);
        node end;
        end.x=-1;
        Q.push(end);
        int cost=0;
        vis[0][st.x][st.y]=true;
        int x,y,tag;
        while(!Q.empty()){
            cur=Q.front();
            Q.pop();
            if(cur.x==-1){
                if(Q.empty()) break;
                cost++;
                Q.push(end);
                continue;
            }
            printf("%d %d %d %d\n",cur.x,cur.y,cur.tag,cost);
            for(int i=0;i<4;i++){
                x=dir[i][0]+cur.x,y=dir[i][1]+cur.y;
                if(x<0 || x>=r || y<0 || y>=c || vis[cur.tag][x][y] || maze[x][y]=='#') continue;
                vis[cur.tag][x][y]=true;
                if(maze[x][y]=='M'){
                    if(cur.tag & (1<<mp[x][y])){
                        Q.push({x,y,cur.tag,cur.take});
                    }else if(cur.take){
                        Q.push({x,y,cur.tag|(1<<mp[x][y]),false});
                    }else{
                        Q.push({x,y,cur.tag,cur.take});
                    }
                }else if(maze[x][y]=='O'){
                    Q.push({x,y,cur.tag,true});
                }else if(maze[x][y]=='T' && cur.tag==des.tag){
                    printf("%d %d\n",cur.tag,cost);
                    return cost;
                }else{
                    Q.push({x,y,cur.tag,cur.take});
                }
            }
        }
        return cost;
    }
    void build(){

    }
    int minimalSteps(vector<string>& maze) {
        r=maze.size(),c=maze[0].length();
        st=get_axis('S',maze);
        des=get_axis('T',maze);
        return bfs(maze);
    }
};








