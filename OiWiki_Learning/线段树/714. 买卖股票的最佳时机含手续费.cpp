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


#define ls p*2
#define rs p*2+1
#define mid (l+r)/2
#define N 100000
int t[N<<2],uni[N],uni_n,tag[N<<2];
void pushDown(int p,int l,int r){
    if(tag[p]==0x3f3f3f3f || l==r) return;
    t[ls]=std::min(t[ls],tag[p]);
    t[rs]=std::min(t[rs],tag[p]);
    tag[ls]=std::min(tag[ls],tag[p]);
    tag[rs]=std::min(tag[rs],tag[p]);
    tag[p]=0x3f3f3f3f;
}
void update(int p,int l,int r,int lower,int upper,int val){
    if(lower<=l && r<=upper){
        t[p]=std::min(t[p],val);
        tag[p]=std::min(tag[p],val);
        return;
    }
    pushDown(p,l,r);//attention
    if(lower<=mid) update(ls,l,mid,lower,upper,val);
    if(mid<upper) update(rs,mid+1,r,lower,upper,val);
    t[p]=std::min(t[ls],t[rs]);//attention
}

int query(int p,int l,int r,int lower,int upper){
    if(lower<=l && r<=upper){
        return t[p];
    }
    int left=0x3f3f3f3f,right=0x3f3f3f3f;
    pushDown(p,l,r);//attention
    if(lower<=mid) left=query(ls,l,mid,lower,upper);
    if(upper>mid) right=query(rs,mid+1,r,lower,upper);
    return std::min(left,right);
}
void init(){
    memset(t,0x3f,sizeof(int)*N*4);
    memset(tag,0x3f,sizeof(int)*N*4);
    uni_n=0;
}
int temp[N];
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        init();
        int ans=0,val,n=prices.size();
        int k=0;
        for(int i=0;i<n;i++){
            prices[i]++;
            k=max(k,prices[i]);
        }
        int inf=0x3f3f3f3f;
        for(int i=0;i<n;i++){
            val=query(1,1,k,1,prices[i]);
            int z=val;
            val=prices[i]-val;
            ans=max(ans,val);
            update(1,1,k,prices[i],k,prices[i]+fee-ans);
        }
        return ans;
    }
};