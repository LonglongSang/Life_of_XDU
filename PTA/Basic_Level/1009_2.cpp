#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
using namespace std;

int main(){
	string a,temp;
	a.resize(30);
	vector< vector<char> > dp(100);
	for(int i=0;i<100;i++) dp[i].resize(100);
	int num=0;
	while(scanf("%s",dp[num])!=EOF){
		num++;
	}
	for(int i=dp.size()-2;i>=0;i++) cout<<" "<<dp[i];
	return 0;
}


