#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
int main(){
	multimap<char,int> num;
	int n=0;
	int count=0;
	int a;
	while(n!=10){
		cin>>a;
		if(n==0){
			count=a;
		}else{
			for(int i=0;i<a;i++) num.insert(pair<char,int>(n+'0',i));
		}
		n++;
	}
	string out="";
	multimap<char,int>::iterator up;
	for(up=num.begin();up!=num.end();up++){
		out+=up->first;
	}
	if(out.length()!=0){
		cout<<out[0];
		for(int i=0;i<count;i++) cout<<"0";
		for(int i=1;i<out.length();i++) cout<<out[i];
	}else{
		if(count==0) cout<<"0";
	}
	return 0;
}	
	
