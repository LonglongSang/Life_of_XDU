#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <set>
#include <map>
using namespace std;
void to_a(int a,string &p){
	string ret="",temp="1";
	while(a!=0){
		temp[0]=p[a%13];
		ret=temp+ret;
		a/=13;
	}
	if(ret.length()==1){
		ret="0"+ret;
	}else if(ret.length()==0){
		ret="00";
	}
	cout<<ret;
}
int main(){
	int a,b,c;
	string p="0123456789ABC";
	cin>>a>>b>>c;
	cout<<"#";
	to_a(a,p);
	to_a(b,p);
	to_a(c,p);
	return 0;
}
