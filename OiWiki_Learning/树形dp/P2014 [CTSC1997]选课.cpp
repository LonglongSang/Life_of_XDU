//https://www.luogu.com.cn/problem/P2014
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cassert>
#include <string.h>
#include <queue>
using namespace std;
#define N 305
int n,m,indeg[N],head[N],tot,grade[N],par;
int dp[N][N];
int cap[N];
int tot_dp[N];
struct node{
    int to;
    int next;
}e[N];
void add(int from,int to){
    e[++tot].to=to;
    e[tot].next=head[from];
    head[from]=tot;
}
int temp[N];
void dfs(int cur){
    dp[cur][1]=grade[cur];
    int to;
    for(int i=head[cur];i;i=e[i].next){
        to=e[i].to;
        dfs(to);
        memcpy(temp,dp[cur],sizeof(int)*(m+1));
        for(int i=1;i<=m;i++){
            if(!dp[to][i]) break;
            for(int j=1;j+i<=m && temp[j];j++){
                if(dp[to][i]+temp[j]>dp[cur][i+j]) dp[cur][i+j]=dp[to][i]+temp[j];
            }
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++){
        scanf("%d %d",&par,grade+i);
        getchar();
        if(par!=0){
            add(par,i);
            indeg[i]++;
        }
    }
    for(int x=1;x<=n;x++){
        if(indeg[x]!=0) continue;
        dfs(x);
        memcpy(temp,tot_dp,sizeof(int)*(m+1));
        for(int i=m;i>=1;i--){
            if(dp[x][i]==0) continue;
            for(int j=m;j>=i;j--){
                if((j-i) && temp[j-i]==0) continue;
                if(dp[x][i]+temp[j-i]>tot_dp[j]) tot_dp[j]=dp[x][i]+temp[j-i];
            }
        }
    }

    printf("%d\n",tot_dp[m]);
}