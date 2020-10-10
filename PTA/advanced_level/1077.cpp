#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;

int main(){
	int query;
	scanf("%d\n",&query);
	vector<string> dp(query);
	for(int i=0;i<query;i++){
		getline(cin,dp[i]);
		reverse(dp[i].begin(),dp[i].end());
		scanf("\n");
	}
	int count=0;
	bool a=true;
	for(int i=0;i<dp[0].size();i++){
		for(int j=1;j<dp.size();j++){
			if(dp[j][i]!=dp[0][i]){
				a=false;
				break;
			}
		}
		if(a){
			count++;
		}else{
			break;
		}
	}
	//cout<<count<<endl;
	if(count==0){
		cout<<"nai"<<endl;
	}else{
		reverse(dp[0].begin(),dp[0].end());
		cout<<dp[0].substr(dp[0].size()-count);
	}
	return 0;
}


