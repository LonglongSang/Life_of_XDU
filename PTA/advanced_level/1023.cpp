#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
int main(){
	string line;
	getline(cin,line);
	vector<int> count(10,0);
	for(int i=0;i<line.length();i++) count[line[i]-'0']++;
	vector<char> dp;
	int up=0,temp;
	for(int i=line.length()-1;i>=0;i--){
		temp=up+(line[i]-'0')*2;
		up=temp/10;
		dp.push_back(temp%10+'0');
	}
	if(up!=0) dp.push_back(up+'0');
	for(int i=0;i<dp.size();i++) count[dp[i]-'0']--;
	bool good=true;
	for(int i=0;i<count.size();i++){
		if(count[i]!=0){
			good=false;
			break;
		}
	}
	if(good){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	for(int i=dp.size()-1;i>=0;i--) cout<<dp[i];
	return 0;
}
