#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define min(a,b) (a>b?b:a)
int main(){
	int start,num,k;
	scanf("%d %d %d\n",&start,&num,&k);
	vector<pair<int,int>> dp(num);
	unordered_map<int,pair<int,int>> order;//data,next;
	int cur,data,next;
	for(int i=0;i<num;i++){
		scanf("%d %d %d\n",&cur,&data,&next);
		order[cur]={data,next};
	}
	cur=start;
	int count=0;
	while(cur!=-1){
		dp[count++]={cur,order[cur].first};
		cur=order[cur].second;
	}
	dp.resize(count);
	order.clear();
	int time=num/k;
	if(num%k!=0) time++;
	for(int i=0;i<time;i++){
		reverse(dp.begin()+i*k,dp.begin()+min((i+1)*k,count));
	}
	reverse(dp.begin(),dp.end());
	for(int i=0;i<count-1;i++){
		printf("%0.5d %d %0.5d\n",dp[i].first,dp[i].second,dp[i+1].first);
	}
	printf("%0.5d %d %d\n",dp[count-1].first,dp[count-1].second,-1);
	return 0;
}
