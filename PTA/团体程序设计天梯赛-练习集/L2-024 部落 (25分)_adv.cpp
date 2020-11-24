#include <stdio.h>
#include <iostream>
#include <vector>
#include  <unordered_set>
#include <set>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <stack>
#include <string>
using namespace std;
#define N 10005
bool vis[N];
int n,q,k,par[N],cnt[N],t,a,b,t_minus;
int find(int a){
    if(a==par[a]) return a;
    else return par[a]=find(par[a]);
}
void merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(cnt[a]>cnt[b]) swap(a,b);
    par[a]=b;
    cnt[b]+=cnt[a];
    t_minus++;
}
void scan(int &a){
    scanf("%d",&a);
    getchar();
    if(!vis[a]) t++;
    vis[a]=true;
}
int main(){
    scanf("%d\n",&n);
    for(int i=0;i<N;i++) par[i]=i,cnt[i]=1;
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        getchar();
        scan(a);
        for(int j=1;j<k;j++){
            scan(b);
            merge(a,b);
        }
    }
    printf("%d %d\n",t,t-t_minus);
    scanf("%d\n",&q);
    for(int i=0;i<q;i++){
        scanf("%d %d\n",&a,&b);
        if(find(a)==find(b)) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}