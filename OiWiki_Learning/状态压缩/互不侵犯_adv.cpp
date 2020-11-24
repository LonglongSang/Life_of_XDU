//https://loj.ac/p/2153
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

#define N 1000
using ll=long long;
int val[9][9],n,k,tot,valid[N];
ll dp[10][N][82],ans;
bool ok(int v){
    return (v&(v<<1))==0;
}
int sum(int v){//计算有几个二进制下有几个1
    int cnt=0;
    while(v){
        cnt+=v%2;
        v/=2;
    }
    return cnt;
}
bool good(int a,int b){
    return (a&b)==0 && ((a<<1) & b)==0 && ((a>>1) & b)==0;
}
int main(){
    scanf("%d %d",&n,&k);
    valid[tot++]=0;
    for(int i=1,cap=1<<n;i<cap;i++) if(ok(i)) valid[tot++]=i;
    dp[0][0][0]=1;
    for(int l=0;l<n;l++){
        for(int i=0;i<tot;i++){
            int t=sum(valid[i]);
            for(int j=0;j<tot;j++){
                if(good(valid[i],valid[j])){
                    for(int z=t;z<=k;z++) dp[l+1][i][z]+=dp[l][j][z-t];
                }
            }
        }
    }
    for(int i=0;i<tot;i++) ans+=dp[n][i][k];
    printf("%lld\n",ans);
    return 0;
}


