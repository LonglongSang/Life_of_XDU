#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;
struct infor{
	int add,data,next;
};
int get_index(int a,int k){
	if(a<0) return 0;
	if(a>=0 && a<=k) return 1;
	if(a>k) return 2;
	return 10000;
}
int main(){
	vector<infor> dp(100005);
	int begin,temp,add,data,next,num,k,index;
	scanf("%d %d %d\n",&begin,&num,&k);
	for(int i=0;i<num;i++){
		scanf("%d %d %d\n",&add,&data,&next);
		dp[add]={add,data,next};
	}
	vector< vector<infor> > save(3);
	while(1){
		index=get_index(dp[begin].data,k);
		save[index].push_back(dp[begin]);
		begin=dp[begin].next;
		if(begin==-1) break;
	}
	dp.clear();
	dp.insert(dp.end(),save[0].begin(),save[0].end());
	dp.insert(dp.end(),save[1].begin(),save[1].end());
	dp.insert(dp.end(),save[2].begin(),save[2].end());
	save.clear();
	int size=dp.size()-1;
	for(int i=0;i<size;i++) printf("%.5d %d %.5d\n",dp[i].add,dp[i].data,dp[i+1].add);
	printf("%.5d %d %d\n",dp[size].add,dp[size].data,-1);
	return 0;
}


