#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define N 500000
#define M 51
bool vis[M][N];
int uni[N],n,v,m,cnt,k,num[M],a,b;
int temp[M][10000];
int main(){
    scanf("%d\n",&n);
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        for(int j=0;j<num[i];j++) scanf("%d",&temp[i][j]),uni[cnt++]=temp[i][j];
    }
    sort(uni,uni+cnt);
    cnt=unique(uni,uni+cnt)-uni;
    for(int i=0;i<cnt;i++) mp[uni[i]]=k++;
    for(int i=0;i<n;i++){
        for(int j=0;j<num[i];j++) vis[i+1][mp[temp[i][j]]]=true;
    }
    scanf("%d",&n);
    for(int c=0;c<n;c++){
        scanf("%d%d",&a,&b);
        int total=0,same=0;
        for(int i=0;i<cnt;i++){
            if(vis[a][i] || vis[b][i]) total++;
            if(vis[a][i] && vis[b][i]) same++;
        }
        double ans=100*(double)same/total;
        printf("%.2f%%\n",ans);
    }
}