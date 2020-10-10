#include <iostream>
#include <vector>
using namespace std;
int main(){
	int num,target;
	scanf("%d %d\n",&num,&target);
	vector<int> dp(num+1,0);
	for(int i=0;i<num;i++){
		scanf("%d",&dp[i+1]);
		dp[i+1]+=dp[i];
	}
	vector<vector<int>> ret;
    int mini=0,sum,mid;
	for(int i=0;i<num;i++){
        int low=i+1,high=num;
		while(high>low){
            mid=(low+high)/2;
			if(dp[mid]-dp[i]>target){
                high=mid;
            }else{
                low=mid;
            }
		}
        if(sum<target){
            while(low<num+1 && dp[low]-dp[i]<target) low++;
            if(low==num+1) continue;
        }
        sum=dp[low]-dp[i];
        if(sum>=target && (mini==0 || sum==mini || sum<mini)){
			if(sum<mini) ret.resize(0);
			mini=sum;
			ret.push_back({i+1,low});
		}
	}
	for(int i=0;i<ret.size();i++) cout<<ret[i][0]<<"-"<<ret[i][1]<<endl;
	return 0;
}
















