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
using namespace std;


class Solution {
public:
    int k,ans;
    bool vis[16];
    vector<int> temp;
    void choose(vector<vector<int>> ans,int step,vector<int>& nums){
        if(step==nums.size()/k){
            ans.push_back(temp);
            return;
        }
        for(int i=0,n=nums.size();i<n;i++){
            if(vis[i]) continue;
            bool good=true;
            for(auto& v:temp) if(nums[v]==nums[i]) good=false;
            if(!good) continue;
            vis[i]=true;
            temp.push_back(i);
            choose(ans,step+1,nums);
            temp.pop_back();
            vis[i]=false;
        }
    }
    int get_dev(vector<int>& temp,vector<int>& nums){
        int ma=0x80000000,mi=0x7fffffff;
        for(auto& v:temp){
            ma=max(ma,nums[v]);
            mi=min(mi,nums[v]);
        }
        return ma-mi;
    }
    void dfs(int step,int sum,vector<int>& nums){
        if(sum>=ans) return;
        if(step==k){
            ans=sum;
            return;
        }
        vector<vector<int>> can;
        choose(can,0,nums);
        for(auto& v:can){
            for(auto& c:v) vis[c]=true;
            dfs(step+1,sum+get_dev(v,nums),nums);
            for(auto& c:v) vis[c]=false;
        }
    }
    int minimumIncompatibility(vector<int>& nums, int k) {
        this->k=k;
        ans=0x7fffffff;
        dfs(0,0,nums);
        return ans==0x7fffffff?-1:ans;
    }
};





int dp[100000],cnt;
bool isok(int v,int k,int n){
    int cnt=0;
    int ans=0;
    while(cnt<n && v){
        cnt++;
        ans+=v%2;
    }
    return ans==n/k;
}
void get(int n,int k){
    for(int i=0,cap=1<<n;i<cap;i++){
        if(isok(i,k,n)) dp[cnt++]=i;
    }
}






int cnt[20];
class Solution {
public:
    vector<pair<int,int>> dp;
    int minimumIncompatibility(vector<int>& nums, int k) {
        int ans=0,n=nums.size();
        for(auto&v:nums) cnt[v]++;
        for(int i=1;i<=n;i++){
            if(cnt[i]==0) continue;
            for(int j=i+1;j<=n && cnt[i];j++){
                if(cnt[j]!=0){
                    int temp=min(cnt[i],cnt[j]);
                    ans+=temp*(j-i);
                    cnt[j]-=temp;
                    cnt[i]-=temp;
                    if(temp) dp.push_back({i,j});
                }
            }
            if(cnt[i]!=0) return -1;
        }
        int m=dp.size();
        bool change=true;
        while(change){
            bool change=false;
            for(int i=0;i<m;i++){
                for(int j=0;j<m;j++){
                    if(i==j) continue;
                    int v=abs(dp[i].second-dp[i].first)+abs(dp[j].second-dp[j].first);
                    int v1=abs(dp[i].first-dp[j].first)+abs(dp[i].second-dp[j].second);
                    int v2=abs(dp[i].first-dp[j].second)+abs(dp[i].second-dp[j].first);
                    bool ok1=false,ok2=false;
                    if(dp[i].first!=dp[j].first && dp[i].second!=dp[j].second && v1<v){
                        ok1=true;
                    }
                    if(dp[i].first!=dp[j].second && dp[i].second!=dp[j].first && v2<v){
                        ok2=true;
                    }
                    if(!ok1 && !ok2) continue;
                    if(v1<v2){
                        swap(dp[j].first,dp[i].second);
                    }else{
                        swap(dp[j].second,dp[i].second);
                    }
                    change=true;
                }
            }
        }
        ans=0;
        for(int i=0;i<m;i++) ans+=abs(dp[i].first-dp[i].second);
        return ans;
    }
};

















int main(){

}