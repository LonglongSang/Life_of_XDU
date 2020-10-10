#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;
struct infor{
	int add;
	int data;
	int next;
};
int main(){
	vector<infor> dp(100000);
	int begin,temp,add,data,next;
	int num,k;
	scanf("%d %d %d\n",&begin,&num,&k);
	for(int i=0;i<num;i++){
		scanf("%d %d %d\n",&add,&data,&next);
		dp[add]={add,data,next};
	}
	vector<infor> save;
	while(1){
		save.push_back(dp[begin]);
		begin=dp[begin].next;
		if(begin==-1) break;
	}
	dp.resize(0);
	int time=save.size()/k;
	for(int i=0;i<time;i++){
		reverse(save.begin()+i*k,save.begin()+(i+1)*k);
	}
	for(int i=0;i<save.size()-1;i++){
		printf("%.5d %d %.5d\n",save[i].add,save[i].data,save[i+1].add);
	}
	int size=save.size()-1;
	printf("%.5d %d %d\n",save[size].add,save[size].data,-1);
	return 0;
}


