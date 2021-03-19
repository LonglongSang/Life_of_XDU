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

struct node{
    int val;
    int len;
}lef[100005],righ[100005],temp[100005];
class Solution {
public:
    bool cmp(node&a,node&b){
        return a.val<b.val;
    }
    int maximumScore(vector<int>& nums, int k) {
        int cntLef=0,cntRigh=0;
        lef[cntLef++]={nums[k],1};
        for(int i=k-1;i>=0;i--){
            lef[cntLef++]={min(lef[cntLef-1].val,nums[i]),k-i+1};
        }
        righ[cntRigh++]={nums[k],1};
        for(int i=k+1,n=nums.size();i<n;i++){
            righ[cntRigh++]={min(righ[cntRigh-1].val,nums[i]),i-k+1};
        }
        sort(lef,lef+cntLef,[](node&a,node&b){
            if(a.val==b.val){
                return a.len>b.len;
            }else{
                return a.val<b.val;
            }
        });
        //小到大
        sort(righ,righ+cntRigh,[](node&a,node&b){
            if(a.val==b.val){
                return a.len>b.len;
            }else{
                return a.val<b.val;
            }
        });
        //大到小
        int n=cntLef;
        cntLef=1;
        for(int i=1;i<n;i++){
            if(lef[i].val!=lef[cntLef-1].val){
                lef[cntLef++]=lef[i];
            }
        }
        n=cntRigh;
        cntRigh=1;
        for(int i=1;i<n;i++){
            if(righ[i].val!=righ[cntRigh-1].val) righ[cntRigh++]=righ[i];
        }
        memcpy(temp,righ,sizeof(node)*cntRigh);
        for(int i=cntRigh-2;i>=0;i--){
            temp[i].len=max(temp[i].len,temp[i+1].len);
        }
        int ans=0;
        for(int i=0;i<cntLef;i++){
            int pos=lower_bound(temp,temp+cntRigh,lef[i],cmp)-temp;
            if(pos==cntRigh) continue;
            ans=max(ans,(temp[pos].len+lef[i].len-1)*lef[i].val);
        }

        memcpy(temp,lef,sizeof(node)*cntLef);
        for(int i=cntLef-2;i>=0;i--){
            temp[i].len=max(temp[i].len,temp[i+1].len);
        }
        for(int i=0;i<cntRigh;i++){
            int pos=lower_bound(temp,temp+cntLef,righ[i],cmp)-temp;
            if(pos==cntLef) continue;
            ans=max(ans,(temp[pos].len+righ[i].len-1)*righ[i].val);
        }
        return ans;

    }
};

int main(){

}


