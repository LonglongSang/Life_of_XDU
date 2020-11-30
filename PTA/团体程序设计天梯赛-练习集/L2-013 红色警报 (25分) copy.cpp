#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 505
int n,m,k,a,b,par[N],last,up,ans,cnt[N];
int find(int a){
    if(a==par[a]) return a;
    else return par[a]=find(par[a]);
}
bool lost[N],vis[N];
void merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(cnt[a]>cnt[b]) swap(a,b);
    cnt[b]+=cnt[a];
    par[a]=b;
}
int getnum(){
    int ans=0;
    memset(vis,0,n);
    for(int i=0;i<n;i++){
        if(lost[i]) continue;
        if(!vis[find(i)]) ans++;
        vis[find(i)]=true;
    }
    return ans;
}
pair<int,int> e[5005];
void reset(){
    for(int i=0;i<n;i++) par[i]=i,cnt[i]=1;
    for(int i=0;i<m;i++){
        if(lost[e[i].first] || lost[e[i].second]) continue;
        merge(e[i].first,e[i].second);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    reset();
    for(int i=0;i<m;i++){
        scanf("%d%d",&e[i].first,&e[i].second);
    }
    reset();
    last=getnum();
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&a);
        lost[a]=true;
        reset();
        ans=getnum();
        if(ans>last){
            printf("Red Alert: City %d is lost!\n",a);
        }else{
            printf("City %d is lost.\n",a);
        }
        if(i+1==n) printf("Game Over.");
        last=ans;
    }
    
}