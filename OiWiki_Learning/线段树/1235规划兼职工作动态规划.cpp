//https://leetcode-cn.com/problems/maximum-profit-in-job-scheduling/
#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;


#define N 100000
int v[N],dp[N];
class Solution {
public:
    int getVal(vector<int>& endTime,int high,int val){
        int low=0,mid,ans=-1;
        while(high>=low){
            mid=(low+high)/2;
            if(endTime[v[mid]]<=val){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans==-1?0:dp[ans];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        for(int i=0;i<n;i++) v[i]=i;
        sort(v,v+n,[&](int a,int b){
            return endTime[a]<endTime[b];
        });
        dp[0]=profit[v[0]];
        for(int i=0;i<n;i++){
            dp[i]=profit[v[i]]+getVal(endTime,i-1,startTime[v[i]]);
            if(i) dp[i]=std::max(dp[i],dp[i-1]);
        }
        return dp[n-1];
    }
};