#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <set>
using namespace std;
void input(vector< set<int> > &dp){
	int n,m,c;
	scanf("%d\n",&n);
	dp.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf(" %d",&c);
			dp[i].insert(c);
		}
		scanf("\n");
	}
}
void output(vector< set<int> > &dp){
	int n,g1,g2,count;
	double c;
	scanf("%d\n",&n);
	set<int>::iterator find1;
	for(int i=0;i<n;i++){
		count=0;
		scanf("%d %d\n",&g1,&g2);
		for(find1=dp[g1-1].begin();find1!=dp[g1-1].end();find1++) if(dp[g2-1].find(*find1)!=dp[g2-1].end()) count++;
		c=100*((double)count/(dp[g1-1].size()+dp[g2-1].size()-count));
		printf("%.1lf%%\n",c);
	}
}
int main(){
	vector< set<int> > dp;
	input(dp);
	output(dp);
	return 0;
}


