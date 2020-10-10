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
	map<int,double> a,b,c;
	map<int,double>::reverse_iterator up,down;
	input(a);
	input(b);
	for(up=a.rbegin();up!=a.rend();up++){
		for(down=b.rbegin();down!=b.rend();down++){
			c[up->first+down->first]+=up->second*down->second;
		}
	}
	int count=c.size();
	for(up=c.rbegin();up!=c.rend();up++) if(up->second==0) count--;
	cout<<count;
	for(up=c.rbegin();up!=c.rend();up++) if(up->second!=0) printf(" %d %.1lf",up->first,up->second);
	//int count=dp.size();
	
	return 0;
}
