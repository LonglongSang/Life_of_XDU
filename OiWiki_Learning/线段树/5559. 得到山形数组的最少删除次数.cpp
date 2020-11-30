//https://leetcode-cn.com/problems/minimum-number-of-removals-to-make-mountain-array/comments/
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <unordered_map>
using namespace std;
#define N 100000
#define ls p*2
#define rs (p*2+1)
#define mid (l+r)/2
int t[N<<2],tag[N<<2],temp[N],dp[N];
int n,m;
void push_down(int p,int l,int r){
    if(tag[p]==0 || l==r) return;
    if(tag[p]>t[ls]){
        t[ls]=max(t[ls],tag[p]);
        tag[ls]=max(tag[ls],tag[p]);
    }
    if(tag[p]>t[rs]){
        t[rs]=max(t[rs],tag[p]);
        tag[rs]=max(tag[rs],tag[p]);
    }    
    tag[p]=0;
}
void update(int p,int l,int r,int lower,int upper,int v){
    if(lower<=l && r<=upper){
        if(v>t[p]){
            t[p]=max(t[p],v);
            tag[p]=max(tag[p],v);
        }
        return;
    }
    //push_down(p,l,r);
    if(pos<=mid) update(ls,l,mid,lower,upper,v);
    if(pos>mid) update(rs,mid+1,r,lower,upper,v);
    t[p]=max(t[ls],t[rs]);
}
int query(int p,int l,int r,int lower,int upper){
    if(upper<lower) return 0;
    if(lower<=l && r<=upper) return t[p];
    push_down(p,l,r);
    int ret=0;
    if(lower<=mid) ret=max(ret,query(ls,l,mid,lower,upper));
    if(upper>mid) ret=max(ret,query(rs,mid+1,r,lower,upper));
    return ret;
}
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        n=nums.size(),m=nums.size();
        memcpy(temp+1,nums.data(),n*4);
        sort(temp+1,temp+1+n);
        n=unique(temp+1,temp+1+n)-1-temp;
        unordered_map<int,int> mp;
        for(int i=1;i<=n;i++) mp[temp[i]]=i;
        for(int i=0;i<m;i++){
            dp[i]=query(1,1,n,1,mp[nums[i]]-1);
            update(1,1,n,1,mp[nums[i]],dp[i]+1);
        }
        int ans=0,v;
        memset(t,0,n*16);
        memset(tag,0,n*16);
        for(int i=m-1;i>=0;i--){
            v=query(1,1,n,1,mp[nums[i]]-1);
            printf("%d %d %d\n",i,v,dp[i]);
            if(dp[i] && v){
                ans=max(ans,v+dp[i]+1);
            }
            update(1,1,n,1,mp[nums[i]],v+1);
        }
        return m-ans;
    }
};
int main(){

}