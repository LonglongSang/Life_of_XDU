#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <map>
#include <algorithm>
using namespace std;
int main(){
	string a,b,temp="";
	getline(cin,a);
	b=a;
	reverse(b.begin(),b.end());
	int last=-1;
	bool right=false;
	cout<<b<<endl;
	for(int i=0;i<a.length();i++){
		if(a[i]==b[i] && right==false){
			right=true;
			last=i;
		}else if(a[i]!=b[i] && right==true){
			right=false;
			temp=a.substr(last,i-last);
		}
	}
	cout<<temp<<endl;
	return 0;
}


