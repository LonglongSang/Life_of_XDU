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
	int max;
	cin>>max;
	vector<int> dp(1,2);
	int n=3;
	int flag=0;
	int count=0;
	while(n<=max){
		for(int i=0;i<dp.size();i++){
			if(n%dp[i]==0){
				flag=1;
				break;
			}
		}
		if(flag==0){
			dp.push_back(n);
			if(dp[dp.size()-1]-dp[dp.size()-2]==2) count++;
		}
		flag=0;
		n++;
	}
	cout<<count<<endl;
	return 0;
}	
	
