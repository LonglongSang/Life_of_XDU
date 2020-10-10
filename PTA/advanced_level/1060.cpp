#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;
int is_dot(string &a){
	if(a[0]=='0' && a[1]=='.'){
		return 0;
	}
	for(int i=0;i<a.length();i++) if(a[i]=='.') return  i;
	return -2;
}
void change(string &a,int digit,int &time){
	int pos=is_dot(a);
	if(pos==0){
		a=a.substr(0,digit+2);
		time=pos;
	}else if(pos==-2){
		time=a.length();
		a="0."+a.substr(0,digit);
	}else{
		a="0."+a.substr(0,pos)+a.substr(pos+1);
		a=a.substr(0,digit+2);
		time=pos;
	}
}
int main(){
	int digit,a_time,b_time;
	string a,b;
	cin>>digit>>a>>b;
	change(a,digit,a_time);
	change(b,digit,b_time);
	//cout<<a<<endl;
	//cout<<b<<endl;
	if(a==b && a_time==b_time){
		if(a_time!=0) cout<<"YES"<<" "<<a<<"*10^"<<a_time<<endl;
		else cout<<"YES"<<" "<<a<<endl;
	}else{
		if(a_time!=0 && b_time!=0){
			cout<<"NO"<<" "<<a<<"*10^"<<a_time<<" "<<b<<"*10^"<<b_time<<endl;
		}else if(a_time!=0 && b_time==0){
			cout<<"NO"<<" "<<a<<"*10^"<<a_time<<" "<<b<<endl;
		}else if(a_time==0 && b_time!=0){
			cout<<"NO"<<" "<<a<<" "<<b<<"*10^"<<b_time<<endl;
		}else{
			cout<<"NO"<<" "<<a<<" "<<b<<endl;
		}
	}
	return 0;
}



