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
    cin>>a;
    if(!vis[a]) t++;
    vis[a]=true;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<N;i++) par[i]=i,cnt[i]=1;
    for(int i=0;i<n;i++){
        cin>>k;
        scan(a);
        for(int j=1;j<k;j++){
            scan(b);
            merge(a,b);
        }
    }
    cout<<t<<(t-t_minus)<<endl;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        if(find(a)==find(b)) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}