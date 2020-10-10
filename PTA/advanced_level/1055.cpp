#include <iostream>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <stack>
#include <queue>
#include <string.h>
using namespace std;
struct infor{
	string name;
	int height;
};
bool cmp(infor &a,infor &b){
	if(a.height!=b.height) return a.height>b.height;
	else return a.name<b.name;
}
void pr(int &count,infor &a){
	if(count) printf(" %s",a.name.c_str());
	else printf("%s",a.name.c_str());
	count++;
}
void pr(int &count,stack<infor> &left){
	while(!left.empty()){
		pr(count,left.top());
		left.pop();
	}	
}
void pr(int &count,queue<infor> &left){
	while(!left.empty()){
		pr(count,left.front());
		left.pop();
	}	
}
int main(){
	int num,k;
	scanf("%d %d\n",&num,&k);
	vector<infor> dp(num);
	for(int i=0;i<num;i++){
		dp[i].name.resize(9);
		scanf("%s %d\n",&dp[i].name[0],&dp[i].height);
	}
	sort(dp.begin(),dp.end(),cmp);
	int n=num/k,more=num%k,cur=0;
	for(int i=0;i<k;i++){
		stack<infor> left;
		queue<infor> right;
		int target=i*n+cur;
		for(int j=i*n+1+cur;j<(i+1)*n+more;j++){
			if((j-target)%2==1) left.push(dp[j]);
			else right.push(dp[j]);
		}
		int count=0;
		pr(count,left);	
		pr(count,dp[target]);
		pr(count,right);
		printf("\n");
        cur=more;
	}
	return 0;
}