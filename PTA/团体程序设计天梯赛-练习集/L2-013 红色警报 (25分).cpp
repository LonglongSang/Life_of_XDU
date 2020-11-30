#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 10000
int n,m,k,a,b,par[N],last,up,ans;
int find(int a){
    if(a==par[a]) return a;
    else return par[a]=find(par[a]);
}
bool lost[N],vis[N];
void merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return;
    par[a]=b;
}
int getnum(){
    int ans=0;
    memset(vis,0,2*n);
    for(int i=0;i<n;i++){
        if(lost[i]) continue;
        if(!vis[find(i)]) ans++;
        vis[find(i)]=true;
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    up=2*n;
    for(int i=0;i<n;i++) par[i]=i+n;
    for(int i=n;i<N;i++) par[i]=i;
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        merge(a,b);
    }
    last=getnum();
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&a);
        par[a]=up++;
        ans=getnum();
        cout<<last<<" "<<ans<<endl;
        if(ans>last){
            printf("Red Alert: City %d is lost!\n",a);
        }else{
            printf("City %d is lost.\n",a);
        }
        if(i+1==n) printf("Game Over.");
        last=ans;
    }
    
}