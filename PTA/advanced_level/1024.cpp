#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
using namespace std;
string change(int a){
	string ret;
	if(a==0) return "0";
	while(a!=0){
		ret.push_back(a%10+'0');
		a/=10;
	}
	int count=0;
	while(ret[count]=='0') count++;
	return ret.substr(count);
}
int main(){
	int num,step;
	cin>>num>>step;
	for(int i=0;i<step;i++){
		
	}
	return 0;
}

