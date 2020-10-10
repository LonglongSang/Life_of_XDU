#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;
int get(int a);
void say(double my,double a);
int main(){
	int m,x,y;
	cin>>m>>x>>y;
	double a=0,b;
	double c;
	int temp;
	for(int i=10;i<=99;i++){
		temp=get(i);
		if((double)abs(i-temp)/x==(double)temp/y){
			a=i;
			b=temp;
			c=(double)abs(i-temp)/x;
		}
	}
	if(a==0){
		cout<<"No Solution"<<endl;
	}else{
		cout<<a;
		say(m,a);
		say(m,b);
		say(m,c);
	}
	return 0;
}
void say(double my,double a){
	if(my>a){
		cout<<" Gai";
	}else if(my==a){
		cout<<" Ping";
	}else{
		cout<<" Cong";
	}
}
int get(int a){
	int sum=0;
	while(a!=0){
		sum=sum*10+a%10;
		a/=10;
	}
	return sum;
}