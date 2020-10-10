#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	int key,time,max,count=0,up=0;
	cin>>key>>time;
	int size=time+4;
	if(time==0){
		cout<<0<<endl;
		return 0;
	}
	char big_value[size];
	for(int i=0;i<size;i++) big_value[i]='0';
	while(count<time || up!=0){
		if(count<time){
			big_value[count]=((time-count)*key+up)%10+'0';
			up=((time-count)*key+up)/10;
		}else{
			big_value[count]=up%10+'0';
			up=up-up%10;
		}
		count++;
	}
	max=size-1;
	while(big_value[max]=='0') max--;
	for(int i=max;i>=0;i--) cout<<big_value[i];
	return 0;
}