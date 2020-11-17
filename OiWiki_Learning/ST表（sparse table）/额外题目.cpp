#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
using ll=long long;
int n,m,k,ori[2005],v;
ll dp[2005][2005];
int main(){
    scanf("%d %d %d\n",&n,&m,&k);
    ll ans=0;
    for(int i=0;i<n;i++) scanf("%d",ori+i);
    dp[0][0]=1;
    for(int x=0;x<m;x++){
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=i-k && j>=0;j--){
                if(dp[j][x]==0) continue;
                dp[i][x+1]=max(dp[i][x+1],dp[j][x]);
                
            }
            if(dp[i][x+1]!=0) dp[i][x+1]+=ori[i-1];
        }
    }
    for(int i=n;i>=n-k+1;i--) ans=max(ans,dp[i][m]);
    printf("%lld\n",ans-1);
    return 0;
}
