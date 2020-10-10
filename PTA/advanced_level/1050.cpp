#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
int main(){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	vector<int> dp(256,0);
	for(int i=0;i<s2.length();i++) dp[s2[i]]++;
	for(int i=0;i<s1.length();i++) if(dp[s1[i]]==0) printf("%c",s1[i]);
	return 0;
}


