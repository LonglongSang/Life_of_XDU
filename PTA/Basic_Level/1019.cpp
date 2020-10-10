#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
#include <algorithm>
#include <iomanip>//setfill() && setw()
using namespace std;
string hello(string a);
int s_to_i(string a){
	istringstream ii(a);
	int c;
	ii>>c;
	return c;
}
string i_to_string(int a){
	ostringstream h;
	h<<setfill('0')<<setw(4)<<a;
	return h.str();
}
int main(){
	string num;
	cin>>num;
	int temp=s_to_i(num);
	num=i_to_string(temp);
	temp=0;
	while((num!="0000" && num!="6174") || temp==0){
		num=hello(num);
		temp++;
	}
	return 0;
}
string hello(string a){
	multimap<char,int> num;
	string big="",small="",dev;
	int big_n,small_n,flag;
	for(int i=0;i<4;i++){
		num.insert(pair<char,int>(a[i],i));
	}
	multimap<char,int>::iterator up;
	for(up=num.begin();up!=num.end();up++) big=big+up->first;
	small=big;
	reverse(small.begin(),small.end());
	if(small==big){
		cout<<big<<" - "<<big<<" = "<<"0000"<<endl;
		return "0000";
	}else{
		small_n=s_to_i(small)-s_to_i(big);
		dev=i_to_string(small_n);
		cout<<small<<" - "<<big<<" = "<<dev<<endl;
		return dev;
	}

}

