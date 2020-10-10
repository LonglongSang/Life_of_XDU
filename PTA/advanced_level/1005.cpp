#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <set>
using namespace std;
int cal_sum(string &a){
	int sum=0;
	for(int i=0;i<a.length();i++) sum+=a[i]-'0';
	return sum;
}
int main(){
	string input;
	getline(cin,input);
	int sum=cal_sum(input);
	string conversion[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	vector<string> dp;
	if(sum==0){
		cout<<"zero";
		return 0;
	}
	while(sum!=0){
		dp.push_back(conversion[sum%10]);
		sum/=10;
	}
	cout<<dp[dp.size()-1];
	for(int i=dp.size()-2;i>=0;i--) cout<<" "<<dp[i];
	return 0;
}
