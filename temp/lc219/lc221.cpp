#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using ll = long long;
using namespace std;
int P1(vector<int>& weight, vector<int>& value, int capacity){
    int n = weight.size();
    int inf = 0x80000000;
    int* dp = new int[capacity + 1];
    memset(dp, 0, sizeof(int) * (capacity + 1));
    for(int i = 0; i < n; i++){
        for(int j = capacity; j >= weight[i]; j--){
            dp[j] = max(dp[j - weight[i]] + weight[i], dp[j]);
        }
    }
    return dp[capacity];
}

double P2(vector<int>& cost){
    int n = cost.size();
    if(n == 0) return 0;
    sort(cost.begin(), cost.end());
    int sum = 0;
    int pre = 0;
    for(int i = 0; i < n; i++){
        pre += cost[i];
        sum += pre;
    }
    return (double)sum / n;
}


vector<int> P3(vector<vector<int>>& dist){
    int n = dist.size();
    //source为点0
    int inf = 0x3f3f3f3f;
    vector<int> ans(n, inf);
    vector<bool> vis(n, false);
    struct node{
        int cur;
        int dist;
    };
    struct cmp{
        bool operator()(node& a, node&b){
            return a.dist > b.dist;
        }
    };
    /*
    auto cmp = [&](node& a, node& b){
        return a.dist > b.dist;
    };
    */
    priority_queue<node, vector<node>, cmp> Q;
    node cur;
    cur.cur = 0;
    cur.dist = 0;
    Q.push(cur);
    node temp;
    while(!Q.empty()){
        cur = Q.top();
        if(vis[cur.cur]) continue;
        vis[cur.cur] = true;
        for(int i = 0; i < n; i++){
            if(dist[cur.cur][i] + ans[cur.cur] < ans[i]){
                temp.cur = i;
                ans[i] = dist[cur.cur][i] + ans[cur.cur];
                temp.dist = ans[i];
                Q.push(temp);
            }
        }
    }
    return ans;
}
void P4(vector<vector<int>>& dist){
    int n = dist.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
}
int main(){

}


/*
给定n个任务(n <= 24),每个任务有一个完成时间，利用vector<int> task传入，task[i]表示第i个任务的完成时间。

若我们从n个任务中挑选k个任务，我们称之为任务组
他们的编号分别为x0,x1,...,xk，则这个任务组的完成时间为cost = task[x0]+task[x1]+task[xk]

可知n个任务，可以产生pow(2,n)个不同的任务组，请你返回这pow(2,n)个任务的sum(cost)，并对其取模1000000007

例子：
共3个任务：task={1，2，3};
利用二进制来枚举
000：cost = 0
001：cost = 1
010：cost = 2
011：cost = 1 + 2 = 3
100：cost = 3
101：cost = 1 + 3 = 4
110：cost = 2 + 3 = 5
111：cost = 1 + 2 + 3 = 6
所以sum(cost) = (0 + 1 + 2 + 3 + 3 + 4 + 5 + 6) % 1000000007 = 24

额外挑战：之前我们限制n<=24，如果对n不加以限制呢，比如n = 1000000000时，你是否还可以快速计算出结果
传入函数: C++: int getAns(vector<int>& task)
        C: int getAns(int* task, int n)
        Java int getAns(int[] task)
*/