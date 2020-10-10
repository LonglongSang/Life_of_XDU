#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;
void input( vector< vector<string> > &dp ){
	string name;
	int num,temp;
	cin>>name>>num;
	for(int i=0;i<num;i++){
		cin>>temp;
		dp[temp-1].push_back(name);
	}
	scanf("\n");
}
void output(vector< vector<string> > &dp){
	int temp;
	for(int i=0;i<dp.size();i++){
		temp=dp[i].size();
		printf("%d %d\n",i+1,temp);
		sort(dp[i].begin(),dp[i].end());
		for(int j=0;j<dp[i].size();j++){
			printf("%s\n",dp[i][j].c_str());
		}
	}
}
int main(){
	int stu,cou;
	scanf("%d %d\n",&stu,&cou);
	vector< vector<string> > dp(cou);
	for(int i=0;i<stu;i++) input(dp);
	output(dp);
	return 0;
}


