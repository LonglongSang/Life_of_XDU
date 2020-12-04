#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

#define N 4096
int n;
int dp[N][12];
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph){
        n=graph.size();
        if(n==1) return 0;
        memset(dp,0x3f,N*12*4);
        //dp[i][j]，假设i的二进制分别表示了第x1，x2，xn位为1
        //dp[i][j]就表示访问过x1，x2，xn这n个点，并且是以第j个点为结尾
        //如i=0x00000003表示访问过第0位与第1位
        int m=1<<n;
        int inf=0x3f3f3f3f,ans=0x3f3f3f3f;
        for(int i=0;i<n;i++) dp[1<<i][i]=0;//初始化，即图中的n个点的访问代价都为0
        for(int state=0,cap=1<<n;state<cap;state++){
            //假设从我们访问了state1中的第i位所代表的点，那么将会跳转到状态state2=state1 | (1<<i)
            //可知state2>=state1
            //1、内部松弛
            //可知目前为止dp[state][i]均是从小于state的状态转化而来
            //同时保证了dp[state][i]均为最小值
            //但是不能忽略了,dp[state][i]可能是从dp[state][j]转化而来
            //所以进行内部松弛
            for(int i=0;i<n;i++){
                for(auto& j:graph[i]){
                    dp[state][i]=min(dp[state][i],dp[state][j]+1);
                }
            }
            //向上松弛
            //更新state|(1<<i)
            for(int i=0;i<n;i++){
                for(auto& j:graph[i]){
                    if(!(state & (1 << j))) continue;
                    dp[state | (1 << i)][i]=min(dp[state | (1 << i)][i],dp[state][j]+1);
                }
            }
        }
        for(int i=0;i<n;i++) ans=min(ans,dp[m-1][i]);
        return ans;
    }
};