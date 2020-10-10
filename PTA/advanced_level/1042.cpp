#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <sstream>
using namespace std;
string tstring(int a){
	ostringstream h;
	h<<a;
	string ret=h.str();
	return ret;
}
int main(){
	string A="SHCD";
	vector<string> dp,dp_sub(54);
	for(int i=0;i<4;i++) for(int j=1;j<=13;j++) dp.push_back(A.substr(i,1)+tstring(j));
	dp.push_back("J1");
	dp.push_back("J2");
	vector<int> pos(54);
	int n;
	cin>>n;
	for(int i=0;i<54;i++) cin>>pos[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<54;j++) dp_sub[pos[j]-1]=dp[j];
		dp.swap(dp_sub);
	}
	cout<<dp[0];
	for(int i=1;i<54;i++) cout<<" "<<dp[i];
	return 0;
}