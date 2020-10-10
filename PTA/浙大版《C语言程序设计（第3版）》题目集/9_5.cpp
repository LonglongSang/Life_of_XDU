#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <set>
#include <map>
using namespace std;
void input(map< string,vector<string> > &dp){
	string name,date,phone;
	cin>>name>>date>>phone;
	map< string,vector<string> >::iterator up;
	up=dp.find(date);
	if(up==dp.end()){
		dp[date].resize(2);
	}
	dp[date][0]=name;
	dp[date][1]=phone;
}
int main(){
	int n;
	scanf("%d\n",&n);
	map< string,vector<string> > dp;
	for(int i=0;i<n;i++) input(dp);
	map< string,vector<string> >::iterator up;
	for(up=dp.begin();up!=dp.end();up++){
		cout<<up->second[0]<<" "<<up->first<<" "<<up->second[1]<<endl;
	}
	return 0;
}
