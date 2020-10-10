#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <sstream>
using namespace std;
string string_reve(int a){
	string ret;
	ostringstream h;
	h<<a;
	ret=h.str();
	return ret;
}
bool hellll(int big_int,int small_int){
	string big=string_reve(big_int),small=string_reve(small_int);
	int j=big.length()-1;
	for(int i=small.length()-1;i>=0;i--){
		if(small[i]!=big[j]) return false;
		j--;
	}
	return true;
}
int check(int num){
	for(int i=1;i<10;i++) if(hellll(num*num*i,num)) return i;
	return 0;
}
int main(){
	int n,temp,ret;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		ret=check(temp);
		if(ret){
			printf("%d %d\n",ret,temp*temp*ret);
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}

	
	
