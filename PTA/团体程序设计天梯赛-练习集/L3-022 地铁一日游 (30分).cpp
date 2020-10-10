#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
int n,m,k,from,cost,to,cnt,q;
bool endline=false;
bool is_terminal[205];
int read(){
    int ans=0;
    char a;
    while(1){
        a=getchar();
        if(a=='\n') endline=true;
        if(a==' ' || a=='\n') return ans;
        ans=ans*10+(a-'0');
    }
    return ans;
}
struct node{
    int index;
    int dist;
}dist[205][205];
int main(){
    scanf("%d %d %d\n",&n,&m,&k);
    int inf=1000000000;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j].index=j;
            dist[i][j].dist=inf;
        }
    }
    for(int i=0;i<m;i++){
        endline=false;
        from=read();
        is_terminal[from]=true;
        bool d=1;
        while(!endline){
            if(d){
                cost=read();
            }else{
                to=read();
                dist[from][to].dist=min(dist[from][to].dist,cost);
                dist[to][from].dist=dist[from][to].dist;
                from=to;
            }
            d^=1;
        }
        is_terminal[to]=true;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                dist[i][j].dist=min(dist[i][j].dist,dist[i][k].dist+dist[k][i].dist);
                dist[j][i].dist=dist[i][j].dist;
            }
        }
    }
    scanf("%d\n",&m);
    for(int i=0;i<m;i++){
        scanf("%d\n",&q);
        sort(dist[q]+1,dist[q]+1+n,[](const node&a,const node&b){
            return a.dist>b.dist;
        });
        int j=1;
        while(j<=n && dist[q][j].dist==inf) j++;
        int cnt=0;
        if(j<=n) printf("%d",dist[q][j++].index);
        for(;j<=n;j++){
            if(is_terminal[dist[q][j].index] || ){
            }
        }
    }
}