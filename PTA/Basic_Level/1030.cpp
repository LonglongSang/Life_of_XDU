#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
int main(){
	long n,p;
	scanf("%ld %ld\n",&n,&p);
	vector<long> dp;
	long temp;
	for(int i=0;i<n;i++){
		scanf("%ld",&temp);
		dp.push_back(temp);
	}
	sort(dp.begin(),dp.end());
	long max=0;
	long high=dp.size()-1,low=dp.size()-1;
	while(high>=0 && low>=0 && high>=low){
		temp=high-low+1;
		if(dp[low]*p>=dp[high]){
			if(temp>max) max=temp;
			low--;
		}else{
			high--;
		}
	}
	cout<<max<<endl;
	return 0;
}	
	
