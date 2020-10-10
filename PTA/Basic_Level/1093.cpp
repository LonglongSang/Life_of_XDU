#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
using namespace std;
bool is_o(int n);
int main(){
	string a,b;
	getline(cin,a);
	getline(cin,b);
	vector<int> dp(256,0);
	for(int i=0;i<a.size();i++){
		dp[a[i]]++;
		if(dp[a[i]]==1) printf("%c",a[i]);
	}
	for(int i=0;i<b.size();i++){
		dp[b[i]]++;
		if(dp[b[i]]==1) printf("%c",b[i]);
	}
	return 0;
}
