#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct infor{
	int cur;
	int key;
	int next;
};
bool cmp(infor &a,infor &b){
	return a.key<b.key;
}
int main(){
	vector<infor> address;
	int num,begin,key,cur,next;
	scanf("%d %d\n",&num,&begin);
	vector<pair<int,int>> dp(100001);
	if(num==0){
		printf("%d %d\n",0,-1);
		return 0;
	}
	for(int i=0;i<num;i++){
		scanf("%d %d %d\n",&cur,&key,&next);
		dp[cur]={key,next};
	}
	cur=begin;
	while(cur!=-1){
		address.push_back({cur,dp[cur].first,dp[cur].second});
		cur=dp[cur].second;
	}
	sort(address.begin(),address.end(),cmp);
	printf("%d %0.5d\n",num,address[0].cur);
	for(int i=0;i<address.size()-1;i++) printf("%0.5d %d %0.5d\n",address[i].cur,address[i].key,address[i+1].cur);
	printf("%0.5d %d %d\n",address[address.size()-1].cur,address[address.size()-1].key,-1);
	return 0;
}