#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <map>
#include<set>
using namespace std;
struct infor{
	string name,ID;
	int grade;
};
void assign(vector<infor> &dp,int index,string &name,string &ID,int &grade){
	dp[index].name=name;
	dp[index].ID=ID;
	dp[index].grade=grade;
}
void pr(vector<infor> &dp,int index){cout<<dp[index].name<<" "<<dp[index].ID<<endl;}
int main(){
	int n,grade;
	scanf("%d\n",&n);
	vector<infor> dp(2);
	dp[0].name="Absent",dp[1].name="Absent";
	dp[0].grade=-1,dp[1].grade=1000;
	string name,ID,gender;
	for(int i=0;i<n;i++){
		cin>>name>>gender>>ID>>grade;
		if(gender[0]=='F' && grade>dp[0].grade) assign(dp,0,name,ID,grade);
		else if(gender[0]=='M' && grade<dp[1].grade)assign(dp,1,name,ID,grade);
	}
	if(dp[0].name=="Absent" || dp[1].name=="Absent"){
		if(dp[0].name=="Absent") cout<<dp[0].name<<endl;
		else pr(dp,0);
		if(dp[1].name=="Absent") cout<<dp[1].name<<endl;
		else pr(dp,1);
		printf("NA\n");
	}else{
		pr(dp,0);
		pr(dp,1);
		int cc=dp[0].grade-dp[1].grade;
		cout<<cc<<endl;
	}
	return 0;
}


