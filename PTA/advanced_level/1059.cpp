#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int main(){
	long num;
	scanf("%ld\n",&num);
	long ori=num;
	int max=sqrt(num);
	int prime[max];
	int count=0;
	prime[count++]=2;
	for(int i=3;i<=max;i++){
		int up=sqrt(i);
		bool pri=true;
		for(int j=0;j<count && prime[j]<=up;j++){
			if(i%prime[j]==0){
				pri=false;
				break;
			}
		} 
		if(pri) prime[count++]=i;
	}
	vector<int> ret;
	while(1){
		int up=sqrt(num);
		bool pri=true;
		int low=0,high=count-1,mid;
		for(int i=0;prime[i]<=up;i++){
			if(num%prime[i]==0){
				pri=false;
				num/=prime[i];
				ret.push_back(prime[i]);
				break;
			}
		}
		if(pri) break;
	}
	if(num==ori){
		printf("%ld=%ld",num,num);
		return 0;
	}
	if(num!=1) ret.push_back(num);
	map<int,int> dp;
	for(int i=0;i<ret.size();i++) dp[ret[i]]++;
	count=0;
	printf("%ld=",ori);
	for(auto it:dp){
		if(count) printf("*");
		if(it.second!=1) printf("%d^%d",it.first,it.second);
		else printf("%d",it.first);
		count++;
	}
	return 0;
}

