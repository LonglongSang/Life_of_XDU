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
	int n;
	cin>>n;
	vector<double> dp(n);
	int count=0;
	while(n!=0){
		cin>>dp[count++];
		n--;
	}
	sort(dp.begin(),dp.end());
	//for(int i=0;i<dp.size();i++) cout<<dp[i]<<endl;
	double sum=dp[0];
	for(int i=1;i<dp.size();i++){
		sum=(sum+dp[i])/2;
	}
	sum=(int)sum;
	printf("%.0lf\n",sum);
	return 0;
}
