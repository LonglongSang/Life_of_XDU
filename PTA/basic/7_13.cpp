#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
void big_add(char *big_value,char *value,int &max,int time);
int main(){
	double Open,High,Low,Close;
	cin>>Open>>High>>Low>>Close;
	int flag1=0;
	if(Close<Open){
		cout<<"BW-Solid";
	}else if(Close>Open){
		cout<<"R-Hollow";
	}else{
		cout<<"R-Cross";
	}
	if(Low<Open && Low<Close){
		cout<<" with Lower Shadow";
		flag1=1;
	}
	if(High>Open && High>Close){
		if(flag1==1){
			cout<<" and Upper Shadow";
		}else{
			cout<<" with Upper Shadow";
		}
	}
	return 0;
}
