#include <iostream>
#include <vector>
using namespace std;
int main(){
	int num,target;
	scanf("%d %d\n",&num,&target);
	vector<int> dp(num,0);
	for(int i=0;i<num;i++) scanf("%d",&dp[i]);
	vector<vector<int>> ret;
    int mini=0x7fffffff,sum=0;
	int low=0,high=0;
	while(high<num){
		while(high<num && sum<target) sum+=dp[high++];
		while(sum>=target && low<=high){
			if(mini>=sum){
				if(mini>sum) ret.resize(0);
				mini=sum;
				ret.push_back({low,high});
			}
			sum-=dp[low++];
		}
	}
	for(int i=0;i<ret.size();i++) cout<<ret[i][0]<<"-"<<ret[i][1]<<endl;
	return 0;
}
















