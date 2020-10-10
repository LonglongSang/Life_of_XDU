#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <map>
using namespace std;
void input(map<int,double> &dp){
	int n,ex;
	cin>>n;
	double co;
	for(int i=0;i<n;i++){
		cin>>ex>>co;
		dp[ex]+=co;
	}
}
int main(){
	map<int,double> dp;
	map<int,double>::reverse_iterator up;
	input(dp);
	input(dp);
	int count=dp.size();
	for(up=dp.rbegin();up!=dp.rend();up++) if(up->second!=0) count--;
	cout<<count;
	for(up=dp.rbegin();up!=dp.rend();up++) if(up->second!=0) printf(" %d %.1lf",up->first,up->second);
	return 0;
}
