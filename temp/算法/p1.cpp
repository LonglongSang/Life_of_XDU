#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
int problem1(std::vector<std::vector<int>>& m)
{
    static int dp[1005][1005];
    memset(dp, 0, sizeof(dp));
    int n = m.size();
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j <= n - i;j++)
        {
            for(int k = j; k < j + i - 1; k++)
            {
                dp[j][j + i - 1] = std::min(dp[j][j + i - 1], dp[j][k] + dp[k+1][j + i - 1] + m[j][0] * m[k][1] * m[j + i -1][1]);
            }
        }
    }
    return dp[0][n-1];
}
/*
input1:
4
10 100 5 50
output1:
7500

input2:
6 
10 1 50 50 20 5
output2:
3650

*/
int main()
{
    std::vector<std::vector<int>> matrix;
    int n, a = -1, b;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &b);
        if(a != -1) matrix.push_back({a, b});
        a = b;
        getchar();
    }
    std::cout<<problem1(matrix)<<std::endl;
}