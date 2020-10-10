#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	int j=a.size()-1;
	int count=0;
	string hello="0123456789JQK";
	for(int i=b.size()-1;i>=0;i--){
		if(j>=0){
			if(count==0){
				b[i]=hello[(b[i]-'0'+a[j]-'0')%13];
			}else{
				if(b[i]-a[j]<0){
					b[i]=b[i]-a[j]+'0'+10;
				}else{
					b[i]=b[i]-a[j]+'0';
				}
			}
			count^=1;
			j--;
		}else{
			break;
		}
	}
	if(a.size()>b.size()){
		for(int i=a.size()-b.size()-1;i>=0;i--){
			if(count==1){
				b=a[i]+b;
			}else{
				if(a[i]=='0') b="0"+b;
				char cc='0'-a[i]+10+'0';
				if(a[i]!='0') b=cc+b;
			}
			count^=1;		
		}
	}
	int begin=0;
	while(b[begin]=='0') begin++;
	for(int i=begin;i<b.size();i++) cout<<b[i];
	return 0;
}


