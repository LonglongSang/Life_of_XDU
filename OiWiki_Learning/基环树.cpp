//https://ac.nowcoder.com/acm/contest/9977/C
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <string.h>
using namespace std;

int main(){

}




//code below

#define N 5005
struct node{
    int to;
    int next;
}e[N*2];
int tot,head[N],indeg[N];
bool vis[N],ok[N];
void add(int from,int to){
    e[++tot].to=to;
    e[tot].next=head[from];
    head[from]=tot;

    e[++tot].to=from;
    e[tot].next=head[to];
    head[to]=tot;

    indeg[to]++;
    indeg[from]++;
}
void init(int n){
    tot=0;
    memset(head+1,0,sizeof(int)*n);
    memset(indeg+1,0,sizeof(int)*n);
    memset(ok,0,N);
}

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param n int整型 
     * @param u int整型vector 
     * @param v int整型vector 
     * @return int整型
     */
    queue<int> Q;
    void topo(int n){
        for(int i=1;i<=n;i++) if(indeg[i]==1) Q.push(i);
        int cur;
        while(!Q.empty()){
            cur=Q.front();
            Q.pop();
            ok[cur]=true;
            for(int i=head[cur];i;i=e[i].next){
                indeg[e[i].to]--;
                if(indeg[e[i].to]==1) Q.push(e[i].to);
            }
        } 
    }
    int bfs(int cur,int a,int b){
        memset(vis,0,N);
        Q.push(cur);
        int ans; 
        while(!Q.empty()){
            
            cur=Q.front();
            vis[cur]=true;
            Q.pop();
            ans=cur;
            for(int i=head[cur];i;i=e[i].next){
                if(vis[e[i].to] || ((cur==a || cur==b) && (e[i].to==a || e[i].to==b))) continue;
                Q.push(e[i].to);
            }
        }
        return ans;
    }
    int bfs2(int cur,int a,int b){
        memset(vis,0,N);
        Q.push(cur);
        Q.push(-1);
        int level=0;
        while(!Q.empty()){
            cur=Q.front();
            Q.pop();
            if(cur==-1){
                if(Q.empty()) break;
                Q.push(-1);
                level++;
                continue;
            }
            vis[cur]=true;
            for(int i=head[cur];i;i=e[i].next){
                if(vis[e[i].to] || ((cur==a || cur==b) && (e[i].to==a || e[i].to==b))) continue;
                Q.push(e[i].to);
            }
        }
        return level;
    }
    int MaxDiameter(int n, vector<int>& u, vector<int>& v) {
        // write code here
        init(n);
        for(int i=0;i<n;i++) add(u[i],v[i]);
        topo(n);
        int ans=0,x;
        for(int i=0;i<n;i++){
            if(!ok[u[i]] && !ok[v[i]]){
                x=bfs2(bfs(1,u[i],v[i]),u[i],v[i]);
                ans=max(ans,x);
            }
        }
        return ans;
    }
};













