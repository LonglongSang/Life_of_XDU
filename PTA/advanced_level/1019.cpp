#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
bool check(vector<int> &dp){
	int low=0,high=dp.size()-1;
	while(low<high){
		if(dp[low]!=dp[high]) return false;
		low++;
		high--;
	}
	return true;
}
bool to_base(int num,int base,vector<int> &dp){
	while(num!=0){
		dp.push_back(num%base);
		num/=base;
	}
	if(dp.size()==0)dp.push_back(0);
	if(dp[0]==0 && dp.size()!=1){
		return false;
	}else{
		return check(dp);
	}
}
void pr(vector<int> &dp){
	int count=0;
	for(int i=dp.size()-1;i>=0;i--){
		if(count){
			cout<<" "<<dp[i];
		}else{
			cout<<dp[i];
		}
		count++;
	}
}
int main(){
	int num,base;
	cin>>num>>base;
	vector<int> dp;
	if(to_base(num,base,dp)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	pr(dp);
	return 0;
}

