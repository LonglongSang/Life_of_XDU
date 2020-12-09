#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cassert>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long LL;
const int N = 1e5 + 7;
const int INF = 0x3f3f3f3f;

// dp[i][0] : i向下最长距离
// dp[i][1] : i向下次长距离
// dp[i][2] : i向上距离

int n, m;
int dp[N][3], fa[N];
vector<pair<int,int> > mp[N];

void dfs1(int u,int Fa){
  int len = mp[u].size();
  for(int i = 0; i < len; ++i){
    int v = mp[u][i].fi;
    if(v == Fa)continue;
    dfs1(v, u);
    if(dp[v][0] + mp[u][i].se > dp[u][0]){
      fa[u] = v;
      dp[u][1] = dp[u][0];
      dp[u][0] = dp[v][0] + mp[u][i].se;
    }else if(dp[v][0] + mp[u][i].se > dp[u][1]){
      dp[u][1] = (dp[v][0] + mp[u][i].se);
    }
  }
}
void dfs2(int u, int Fa){
  int len = mp[u].size();
  for(int i = 0; i < len; ++i){
    int v = mp[u][i].fi;
    if(v == Fa)continue;
    if(fa[u] == v){
      dp[v][2] = max(dp[u][2], dp[u][1])+mp[u][i].se;
    }else{
      dp[v][2] = max(dp[u][2], dp[u][0])+mp[u][i].se;
    }
    dfs2(v, u);
  }
}
void init(){
  for(int i = 0; i <= n; ++i){
    mp[i].clear();
  }
  memset(dp, 0, sizeof(dp));
  memset(fa, 0, sizeof(fa));
}
int main(){
  while(~scanf("%d", &n)){
    init();
    for(int i = 2, u, v; i <= n; ++i){
      scanf("%d%d", &u, &v);
      int a = i, b = u;
      mp[a].pb(make_pair(b, v));mp[b].pb(make_pair(a, v));
    }
    dfs1(1,-1);
    /*for(int i = 1; i <= n; ++i){
      printf("%d %d %d\n", dp[i][0], dp[i][1], dp[i][2]);
    }
    printf("******\n");*/
    dfs2(1, -1);
    for(int i = 1; i <= n; ++i){
      printf("%d\n", max(dp[i][0], dp[i][2]));
    }
  }
  return 0;
}