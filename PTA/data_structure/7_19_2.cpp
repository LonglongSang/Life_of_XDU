#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <algorithm>
#include <sstream>
using namespace std;
int main(){
	int n;
	cin>>n;
	scanf(" ");
	string a;
	getline(cin,a);
	//reverse(a.begin(),a.end());
	int num;
	int count=0;
	int begin=-1;
	//cout<<a<<endl;
	for(int i=0;i<a.length();i++){
		if(a[i]!=' ' && begin==-1){
			begin=i;
		}else if(a[i]==' '){
			reverse(a.begin()+begin,a.begin()+i);
			begin=-1;
		}
	}
	//cout<<begin<<endl;
	reverse(a.begin()+begin,a.end());
	reverse(a.begin(),a.end());
	//cout<<a<<endl;
	istringstream line(a);
	while(!line.eof()){
		line>>num;
		//cout<<num<<" "<<count<<endl;
		if(count==n) break;
		count++;
	}
	if(count!=n || num==-1){
		cout<<"NULL"<<endl;
	}else{
		cout<<num<<endl;
	}
	return 0;
}



