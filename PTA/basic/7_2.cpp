#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	string now;
	int pass;
	cin>>now>>pass;
	int a=0,b=0;
	if(now.size()==3){
		a=(now[0]-'0')*60+(now[1]-'0')*10+(now[2]-'0')+pass;
	}else{
		a=(now[0]-'0')*10*60+(now[1]-'0')*60+(now[2]-'0')*10+(now[3]-'0')+pass;
	}
	int l=a/60;
	int r=a%60;
	if(r<10){
		cout<<l<<"0"<<r<<endl;
	}else{
		cout<<l<<r<<endl;
	}
	
	
	return 0;
}