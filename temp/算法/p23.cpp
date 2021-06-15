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
            for(int k = j; k < j + i - 1; j++)
            {
                dp[j][j + i -1] = std::min(dp[j][j + i - 1], dp[j][k] + dp[k+1][j + i - 1]);
            }
        }
    }
    return dp[0][n-1];
}
int problem2(std::string& a,std::string& b)
{
    static int dp[1005][1005];
    memset(dp, 0, sizeof(dp));
    int r = a.length(), c = b.length();
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            dp[i + 1][j + 1] = std::max(std::max(dp[i][j] + (a[i] == b[j] ? 1 : 0), dp[i + 1][j]), dp[i][j + 1]);
        }
    }
    return dp[r][c];

}
int problem3(std::string &a, std::string& b)
{
    static int dp[1005][1005];
    memset(dp, 0, sizeof(dp));
    int r = a.length(), c = b.length();
    int ans = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(a[i] == b[j])
            {
                dp[i + 1][j + 1] = 1 + dp[i][j];
            }else
            {
                dp[i + 1][j + 1] = 0;
            }
            ans = std::max(ans, dp[i + 1][j + 1]);
        }
    }
    return ans;
}

int main()
{
    std::string a = "axxbxxxcxxxdxxexxf";
    std::string b = "axxyybyyyycyyyduueuuuf";
    std::cout<<problem2(a, b)<<std::endl;
    std::cout<<problem3(a, b)<<std::endl;
}