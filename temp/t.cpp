#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;



int dp[100000];
int cnt;
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
		int n=nums.size();
		for(int i=0;i<n;i++){
			if(cnt==0){
				dp[cnt++]=nums[i];
			}else if(cnt+(n-i)>k){
				for(int j=max(0,cnt-(n-i));j<cnt;j++){
					if(nums[i]<dp[j]){
						dp[j]=nums[i];
						cnt=j+1;
						break;
					}
				}
			}else{
				dp[cnt++]=nums[i];
			}
		}
		vector<int> ret(k);
		for(int i=0;i<k;i++) ret[i]=dp[i];
		return ret;
    }
};


int main(){

}
