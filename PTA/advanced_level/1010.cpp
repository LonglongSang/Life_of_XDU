#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;
double change(char a){
	if(a>='0' && a<='9'){
		return a-'0';
	}else{
		return a-'a'+10;
	}
}
double my_pow(int radix,int how){
	double sum=1;
	for(int i=0;i<how;i++) sum*=(double)radix;
	return sum;
}
double cal(string &a,int radix){
	double sum=0;
	int size=a.length();
	for(int i=size-1;i>=0;i--) sum+=change(a[i])*my_pow(radix,size-i-1);
	return sum;
}
double find_max(string &a){
	double max=-1;
	double num;
	int size=a.length();
	for(int i=0;i<size;i++){
		num=change(a[i]);
		if(num>max) max=num;
	}
	return max+1;
}
int main(){
	string a1,a2,a3,temp;
	double n1,n2;
	cin>>a1>>a2>>n1>>n2;
	//n2=cal(a3,10);
	//int n1=change(a3[0]),n2=change(a4[0]);
	if(n1==2){
		temp=a1;
		a1=a2;
		a2=temp;
	}
	double mine=cal(a1,n2);
	//cout<<mine<<endl;
	double other_radix=find_max(a2);
	//cout<<other_radix<<endl;
	if(other_radix==1) other_radix=2;
	for(int i=other_radix;i<=36;i++){
		double now=cal(a2,i);
		//cout<<now<<endl;
		if(now==mine){
			cout<<i<<endl;
			return 0;
		}else if(now>mine){
			break;
		}
	}
	cout<<"Impossible"<<endl;
	return 0;
}



