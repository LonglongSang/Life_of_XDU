#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 20;
int n,good;
vector<int> e[21];
int path[20];
bool vis[21];
void dfs(int cur,int step){
    path[step]=cur;
    vis[cur]=true;
    for(auto &i:e[cur]){
        if(good) return;
        if(vis[i]){
            if(step==n-1 && i==path[]){
                good=1;
            }
            continue;
        }
        dfs(i,step+1);
    }
    vis[cur]=false;
}
int main(){
    scanf("%d\n",&n);
    char v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            v=getchar();
            if(v=='W') e[i+1].push_back(j+1);
            else if(v=='L') e[j+1].push_back(i+1);
        }
        getchar();
    }
    for(int i=1;i<=n;i++) sort(e[i].begin(),e[i].end());
    for(int i=1;i<=n;i++){
        dfs(i,0);
        if(good) break;
    }
    if(!good){
        printf("No Solution\n");
    }else{
        for(int i=0;i<n;i++){
            if(i) printf(" ");
            printf("%d",path[i]);
        }
    }
    return 0;
}
