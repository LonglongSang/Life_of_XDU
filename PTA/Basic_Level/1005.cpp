#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
	int n;
	vector<int> dp(10000,0);
	vector<int> remeber;
	cin>>n;
	int temp;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		remeber.push_back(temp);
		while(temp!=1){
			if(temp%2==1){
				temp=(temp*3+1)/2;
			}else{
				temp/=2;
			}
			dp[temp]++;
		}
	}
	set<int> output;
	for(int i=0;i<remeber.size();i++){
		if(dp[remeber[i]]==0) output.insert(remeber[i]);
	}
	set<int>::reverse_iterator down;
	int count=0;
	for(down=output.rbegin();down!=output.rend();down++){
		if(count){
			cout<<" "<<*down;
		}else{
			cout<<*down;
		}
		count++;
	}
	return 0;
}



