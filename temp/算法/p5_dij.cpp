#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory>

struct node
{
    int pre;
    int cur;
    int dist;
};
int problem5(std::vector<std::vector<int>>& edges, int n)
{
    int dp[n];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(auto & e : edges)
        {
            dp[e[1]] = std::min(dp[e[1]], dp[e[0]] + e[2]);
            dp[e[0]] = std::min(dp[e[0]], dp[e[1]] + e[2]);
        }
    }
    return dp[n-1];
}

void input(std::vector<std::vector<int>>& edges, int &n)
{
    scanf("%d",&n);
    getchar();
    int from, to, weight;
    for(int i = 0; 1; i++)
    {
        if(scanf("%d %d %d", &from, &to, &weight)==EOF) break;
        edges.push_back({from, to, weight});
        getchar();
    }
}
/*
16
0 1 5
0 2 3
1 3 1
1 4 3
1 5 6
2 4 8
2 5 7
2 6 6
3 7 6
3 8 8
4 7 3
4 8 5
5 8 3
5 9 3
6 8 8
6 9 4
7 10 2
7 11 2
8 11 1
8 12 2
9 11 3
9 12 3
10 13 3
10 14 5
11 13 5
11 14 2
12 13 6
12 14 6
13 15 4
14 15 3

*/
int main()
{
    std::vector<std::vector<int>> edges;
    int n;
    input(edges, n);
    std::cout<<problem5(edges, n);
}