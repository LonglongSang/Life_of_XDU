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







int cnt[20];
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        for(auto& v:nums) cnt[v]++;
        for(int i=1;i<=nums.size();i++) if(cnt[i]>k) return -1;

    }
};






bool vis[16];
class Solution {
public:
    int k,ans;
    
    vector<int> temp;
    void choose(vector<vector<int>>& ans,int step,vector<int>& nums){
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
            cout<<ans<<endl;
            return;
        }
        vector<vector<int>> can;
        choose(can,0,nums);
        sort(can.begin(),can.end(),[&](vector<int>&a,vector<int>&b){
            return get_dev(a,nums)<get_dev(b,nums);
        });
        for(auto& v:can){
            for(auto& c:v) vis[c]=true;
            dfs(step+1,sum+get_dev(v,nums),nums);
            for(auto& c:v) vis[c]=false;
        }
    }
    int cnt[20];
    int minimumIncompatibility(vector<int>& nums, int k) {
        cout<<"#"<<endl;
        sort(nums.begin(),nums.end());
        memset(cnt,0,80);
        for(auto& v:nums) cnt[v]++;
        for(int i=1;i<=nums.size();i++) if(cnt[i]>k) return -1;
        
        this->k=k;
        ans=0x7fffffff;
        dfs(0,0,nums);
        return ans==0x7fffffff?-1:ans;
    }
};


int main(){

}



int dp[100000];
int cnt;
class Solution {
public:
    int path[20],n;
    bool isok(int v,vector<int>& nums){
        int cnt=0;
        int i=0;
        while(v && i<n){
            if(v%2) path[cnt]=i;
            cnt+=v%2;
            v/=2;
            i++;
        }
        if(cnt!=)
    }
    int minimumIncompatibility(vector<int>& nums, int k) {

    }
};