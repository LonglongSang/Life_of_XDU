/*
P1387 最大正方形
https://www.luogu.com.cn/problem/P1387
在一个n*m的只包含0和1的矩阵里找出一个不包含0的最大正方形，输出边长。
输入格式：输入文件第一行为两个整数n,m（1<=n,m<=100），接下来n行，每行m个数字，用空格隔开，0或1.
输出格式：一个整数，最大正方形的边长
样例：
4 4
0 1 1 1
1 1 1 0
0 1 1 0
1 1 0 1
输出：2
*/
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
//用二维数组前缀和来做
int main(void){
    int n,m;
    scanf("%d %d\n",&n,&m);
    int dp[n+1][m+1];
    for(int i=0;i<=m;i++) dp[0][i]=0;
    for(int i=0;i<=n;i++) dp[i][0]=0;
    int ans=0,temp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&temp);
            getchar();
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+temp;
            for(int k=1;k<=min(i,j);k++){
                int b=dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k];
                if(b==k*k) ans=max(ans,k);
                else break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}


