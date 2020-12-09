#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n,v,m,a,b,c;
#define N 101
int dp[N][N];
int main(){
    scanf("%d%d%d",&n,&v,&m);
    while(n--){
        scanf("%d%d%d",&a,&b,&c);
        for(int i=v;i>=a;i--){
            for(int j=m;j>=b;j--){
                dp[i][j]=max(dp[i][j],dp[i-a][j-b]+c);
            }
        }
    }
    printf("%d\n",dp[v][m]);
}