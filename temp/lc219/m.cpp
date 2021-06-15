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
#include <algorithm>
#include <time.h>
using namespace std;
int cnt1[32];
int cnt2[32];
class Solution {
public:
    void doSome(vector<int>&arr,int* cnt)
    {
        int i;
        for(auto&e:arr)
        {
            i=0;
            while(e)
            {
                cnt[i++]+=e%2;
                e/=2;
            }
        }
    }
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
        doSome(arr1,cnt1);
        doSome(arr2,cnt2);
        int ans=0;
        int k;
        for(int i=0;i<32;i++)
        {
            k=(cnt1[i]%2)*(cnt2[i]%2)%2;
            ans|=1<<k;
        }
        return ans;
    }
};

int main(){

    
    return 0;
}


