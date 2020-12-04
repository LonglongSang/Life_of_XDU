#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;




bool vis[4096][12];
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        memset(vis,0,4096*12);
        queue<pair<int,int>> Q;
        pair<int,int> cur;
        for(int i=0;i<n;i++){
            Q.push({i,1<<i});
            vis[1<<i][i]=true;
        }
        int level=0,tar=(1<<n)-1;
        Q.push({-1,-1});
        while(!Q.empty()){
            cur=Q.front();
            Q.pop();
            if(cur.second==tar) return level;
            if(cur.first==-1){
                if(Q.empty()) break;
                Q.push({-1,-1});
                level++;
                continue;
            }
            for(auto& i:graph[cur.first]){
                int a=cur.second | (1<<i);
                if(vis[a][i]) continue;
                Q.push({i,a});
                vis[a][i]=true;
                if((cur.second | (1<<i))==tar) return level+1;
            }
        }
        return 0;
    }
};