#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
	vector<int> dp(1);
	dp[0]=2;
	bool right=false;
	for(int i=3;i<50000;i++){
		right=false;
		for(int j=0;j<dp.size();j++){
			if(i%dp[j]==0){
				right=true;
				break;
			}
		}
		if(right==false) dp.push_back(i);
	}
	//cout<<dp.size();
	int n;
	cin>>n;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		right=false;
		for(int j=0;j<dp.size() && dp[j]<=sqrt(temp);j++){
			if(temp%dp[j]==0){
				right=true;
				break;
			}
		}
		if(right==false && temp!=1){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}