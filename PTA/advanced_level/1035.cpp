#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <map>
#include <set>
#include <algorithm>
using namespace std;
bool check(string &password){
	int count=0;
	for(int i=0;i<password.length();i++){
		if(password[i]=='1'){password[i]='@';count++;}
		else if(password[i]=='0'){password[i]='%';count++;}
		else if(password[i]=='l'){password[i]='L';count++;}
		else if(password[i]=='O'){password[i]='o';count++;}
	}
	if(count){
		return true;
	}else{
		return  false;
	}
}
struct infor{string name,password;};
int main(){
	int n,count=0;
	string name,password;
	scanf("%d\n",&n);
	vector<infor> dp;
	for(int i=0;i<n;i++){
		cin>>name>>password;
		if(check(password)){
			count++;
			dp.resize(count);
			dp[count-1].name=name;
			dp[count-1].password=password;
		}
	}
	if(dp.size()==0){
		if(n==1) cout<<"There is 1 account and no account is modified"<<endl;
		else cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
	}else{
		cout<<dp.size()<<endl;
		for(int i=0;i<dp.size();i++) cout<<dp[i].name<<" "<<dp[i].password<<endl;
	}
	return 0;
}


