#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <set>
using namespace std;
void being(int a){
	if(a==0){
		cout<<"0";
		return;
	}
	vector<char> dp;
	int count=0;
	while(a!=0){
		dp.push_back(a%10+'0');
		count++;
		a/=10;
		if(count%3==0 && a!=0) dp.push_back(',');
	}
	for(int i=dp.size()-1;i>=0;i--) cout<<dp[i];
}
int main(){
	int a,b;
	cin>>a>>b;
	a+=b;
	if(a>=0){
		being(a);
	}else{
		cout<<"-";
		a=-a;
		being(a);
		
	}
	return 0;
}
