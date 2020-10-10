#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;
struct infor{
	string name,ID;
};
int main(){
	int n,grade,count=0,min,max;
	vector<infor> dp(101);
	for(int i=0;i<101;i++) dp[i].name="";
	scanf("%d\n",&n);
	string name,ID;
	for(int i=0;i<n;i++){
		cin>>name>>ID>>grade;
		dp[grade].name=name;
		dp[grade].ID=ID;
		scanf("\n");
	}
	scanf("%d %d\n",&min,&max);
	for(int i=max;i>=min;i--){
		if(dp[i].name!=""){
			cout<<dp[i].name<<" "<<dp[i].ID<<endl;
			count++;
		}
	}
	if(count==0) cout<<"NONE"<<endl;
	return 0;
}


