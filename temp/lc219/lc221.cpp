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
#include <deque>
using namespace std;

#define N 50000
int uni[N];
int pre[N];
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int low=0,high=100000000,mid,n=apples.size(),sum,now=0,ans=-1;
        while(high>=low){
            mid=(low+high)/2,sum=0;
            for(int i=0;i<n && sum<mid;i++){
                if(apples[i]==0 && days[i]==0) continue;
                now=max(now,i);
                sum+=(days[i]+i-now,apples[i]);
            }
            if(sum>=mid){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};


int main(){

}