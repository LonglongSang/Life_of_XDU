//http://acm.hdu.edu.cn/showproblem.php?pid=1565
#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

#define N 20000
bool check(int v){
    return (v&(v<<1))==0?true:false;
}
int valid[N],tot,n,val[25][25],dp[21][N],t;
int sum(int line,int v){
    int ret=0;
    for(int i=0;i<n;i++) if(v>>i&1) ret+=val[line][i];
    return ret;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        tot=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&val[i][j]);
            }
        }
        for(int i=1,cap=(1<<n);i<cap;i++){
            if(check(i)) valid[tot++]=i;
        }
        int ans=0;
        for(int i=0;i<tot;i++){
            dp[0][i]=sum(0,valid[i]);
        }
        
        for(int x=1;x<n;x++){
            for(int i=0;i<tot;i++){
                t=sum(x,valid[i]);
                dp[x][i]=0;
                for(int j=0;j<tot;j++){
                    if(!(valid[i]&valid[j])){
                        dp[x][i]=max(dp[x][i],t+dp[x-1][j]);
                    }
                }
            }
        }
        for(int i=0;i<tot;i++) ans=max(ans,dp[n-1][i]);
        printf("%d\n",ans);
    }
    return 0;
}