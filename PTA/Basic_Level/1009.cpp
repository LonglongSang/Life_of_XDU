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
	string a;
	getline(cin,a);
	int last=-1;
	for(int i=0;i<a.length();i++){
		if(a[i]==' '){
			reverse(a.begin()+last+1,a.begin()+i);
			last=i;
		}
	}
	reverse(a.begin()+last+1,a.end());
	reverse(a.begin(),a.end());
	cout<<a<<endl;
	return 0;
}
int main(){
	string a;
	vector<string> dp;
	cin>>a;
	while(a!=""){
		dp.push_back(a);
		cin>>a;
	}
	cout<<*dp.end();
	cout<<a<<endl;
	return 0;
}


