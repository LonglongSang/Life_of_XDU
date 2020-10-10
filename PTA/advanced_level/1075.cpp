#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;

int main(){
	int stu,pro,que;
	scanf("%d %d %d\n",&stu,&pro,&que);
	vector< vector <int> > dp(stu+1);
	for(int i=0;i<stu+1;i++) dp[i].resize(pro+1,-1);
	string a;
	getline(cin,a);
	scanf("\n");
	return 0;
}


