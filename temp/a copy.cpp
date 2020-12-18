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
#define N 100005
int t[N<<2],uni[N],uni_n;
void update(int p,int l,int r,int lower,int upper,int val){
    if(lower<=l && r<=upper){
        t[p]=std::max(t[p],val);
        return;
    }
    if(lower<=mid) update(ls,l,mid,lower,upper,val);
    if(mid<upper) update(rs,mid+1,r,lower,upper,val);
    t[p]=std::max(t[ls],t[rs]);
}
int query(int p,int l,int r,int lower,int upper){
    if(lower<=l && r<=upper){
        return t[p];
    }
    int left=0,right=0;
    if(lower<=mid) left=query(ls,l,mid,lower,upper);
    if(upper>mid) right=query(rs,mid+1,r,lower,upper);
    return std::max(left,right);
}
void init(){
    memset(t,0,sizeof(int)*N*4);
    uni_n=0;
}
int temp[N];
class Solution {
public:
    int p(int i){return std::lower_bound(uni+1,uni+1+uni_n,i)-uni;}
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        init();
        int n=startTime.size(),val,ans;
        for(int i=0;i<n;i++) temp[i]=i;
        sort(temp,temp+n,[&](int a,int b){
            return startTime[a]<startTime[b];
        });
        for(int i=0;i<n;i++) uni[++uni_n]=startTime[i];
        for(int i=0;i<n;i++) uni[++uni_n]=endTime[i];
        std::sort(uni+1,uni+1+n);
        uni_n=std::unique(uni+1,uni+1+n)-uni;
        for(int i=0;i<n;i++){
            val=query(1,1,uni_n,1,p(startTime[temp[i]]));
            val+=profit[temp[i]];
            ans=std::max(ans,val);
            update(1,1,uni_n,p(endTime[temp[i]]),uni_n,val);
        }
        return ans;
    }
};