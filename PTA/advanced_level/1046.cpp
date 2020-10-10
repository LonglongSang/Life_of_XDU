#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <sstream>
using namespace std;
int main(){
	int n,sum=0,a,b,temp;
	scanf("%d",&n);
	vector<int> dp(n);
	for(int i=0;i<n;i++){
		scanf(" %d",&temp);
		dp[i]=sum;
		sum+=temp;
	}
	scanf("\n");
	scanf("%d\n",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d\n",&a,&b);
		if(b<a) swap(a,b);
		//temp=dp[b-1]-dp[a-1];
		temp=(dp[b-1]-dp[a-1])>(sum-dp[b-1]+dp[a-1])?(sum-dp[b-1]+dp[a-1]):(dp[b-1]-dp[a-1]);
		printf("%d\n",temp);
	}
	return 0;
}