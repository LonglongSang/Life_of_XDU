#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <set>
using namespace std;

int main(){
	int n;
	cin>>n;
	string early_name,late_name,early="23:59:59",late="00:00:00",temp_name,temp_sign_in,temp_sign_out;
	for(int i=0;i<n;i++){
		cin>>temp_name>>temp_sign_in>>temp_sign_out;
		if(temp_sign_in<early){
			early=temp_sign_in;
			early_name=temp_name;
		}
		if(temp_sign_out>late){
			late=temp_sign_out;
			late_name=temp_name;
		}
	}
	cout<<early_name<<" "<<late_name<<endl;
	return 0;
}
