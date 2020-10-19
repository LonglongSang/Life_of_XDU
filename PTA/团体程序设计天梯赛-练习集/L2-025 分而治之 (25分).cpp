#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;
int n,m,k,q,from,to;
int par[10005],indeg[10005];
int find(int a){
    while(par[a]!=0 || par[a]!=a){
        a=par[a];
    }
    return a;
}
void uniona(int a,int b){
    int _a=find(a);
    int _b=find(b);
    if(_a!=_b){
        if(_b>_a) swap(_a,_b);
        par[_a]=_b;
    }
}


int main(){
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d\n",&from,&to);
        indeg[from]++;
        indeg[to]++;
        //uniona(from,to);
    }
    
    unordered_map<int,int> dp;
    for(int i=1;i<=n;i++){
        par[i]=find(i);
        dp[par[i]]++;
    }
    scanf("%d\n",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&k);
        unordered_map<int,int> temp;
        getchar();
        for(int j=0;j<k;j++){
            scanf("%d",&from);
            getchar();
            temp[par[from]]++;
        }
        bool good=true;
        for(auto it:temp){
            if(dp[it.first]-it.second>1){
                good=false;
                break;
            }
        }
        if(good) printf("YES\n");
        else printf("NO\n");

        
    }
}