#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <map>
#include<set>
#include <algorithm>
using namespace std;
struct infor{
	string ID,name;
	int grade;
};
bool cmp1(infor a,infor b){ return a.ID < b.ID; }
bool cmp2(infor a,infor b){return a.name <=b.name;}
bool cmp3(infor a,infor b){
	if(a.grade!=b.grade) return a.grade<b.grade;
	else return a.ID<b.ID;
}
int main(){
	int n,m,count=0;
	scanf("%d %d\n",&n,&m);
	vector<infor> dp(n);
	for(int i=0;i<n;i++){cin>>dp[count].ID>>dp[count].name>>dp[count].grade;count++;}
	if(m==1) sort(dp.begin(),dp.end(),cmp1);
	else if(m==2) sort(dp.begin(),dp.end(),cmp2);
	else if(m==3) sort(dp.begin(),dp.end(),cmp3);
	for(int i=0;i<n;i++) cout<<dp[i].ID<<" "<<dp[i].name<<" "<<dp[i].grade<<endl;
	return 0;
}


