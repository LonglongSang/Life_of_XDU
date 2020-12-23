int dp[105][21][105];
//颜色，街区数
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        //m个房子，n种颜色
        memset(dp,0x3f,sizeof(dp));
        dp[0][0][0]=0;
        for(int i=0;i<m;i++){
            if(houses[m]==0){
                for(int j=1;j<=n;j++){
                    for(int k=1;k<j;k++){
                        for(int a=0;a<target;a++){
                            dp[i+1][j][a+1]=min(dp[i+1][j][a+1],dp[i][k][a]+cost[i][j-1]);
                        }
                    }
                    for(int a=0;a<=target;a++){
                        dp[i+1][j][a]=min(dp[i+1][j][a],dp[i][j][a]);
                    }
                    for(int k=j+1;k<=n;k++){
                        for(int a=0;a<target;a++){
                            dp[i+1][j][a+1]=min(dp[i+1][j][a+1],dp[i][k][a]+cost[i][j-1]);
                        }                        
                    }
                }
            }else{
                //memcpy(dp[i+1],dp[i],sizeof(dp[i]));
                memset(dp[i+1],0x3f,sizeof(dp[i+1]));
                for(int j=0;j<houses[m];j++){
                    for(int k=target-1;k>=0;k--){
                        dp[i+1][houses[i]][k+1]=dp[i+1][j][k];
                    }
                }
                for(int k=target;k>=0;k--) dp[i+1][houses[i]][k]=dp[i][houses[i]][k];
                for(int j=houses[m]+1;j<=n;j++){
                    for(int k=target-1;k>=0;k--){
                        dp[i+1][houses[i]][k+1]=dp[i+1][j][k];
                    }
                }
            }
        }
        int ans=0x3f3f3f3f;
        for(int i=1;i<=n;i++) ans=min(ans,dp[m][i][target]);
        return ans;
    }
};