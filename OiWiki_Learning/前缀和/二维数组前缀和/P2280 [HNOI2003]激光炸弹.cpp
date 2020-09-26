/*
P2280 [HNOI2003]激光炸弹
https://www.luogu.com.cn/problem/P2280
*/
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
int dp[5005][5005];
int main(void){
    int n,m;
    scanf("%d %d\n",&n,&m);
    int x=0,y=0,x1,y1,price;
    
    for(int i=0;i<n;i++){
        scanf("%d %d %d\n",&x1,&y1,&price);
        dp[x1+1][y1+1]=price;
        x=max(x,x1+1);
        y=max(y,y1+1);
    }
    int ans=0;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            ans=max(ans,dp[i][j]-dp[max(i-m,0)][j]-dp[i][max(j-m,0)]+dp[max(i-m,0)][max(j-m,0)]);    
        }
    }
    printf("%d\n",ans);
    return 0;
}




