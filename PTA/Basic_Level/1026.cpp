#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;
void say(int a){
	if(a<10)
		cout<<"0"<<a;
	else
		cout<<a;
}
int main(){
	double c1,c2;
	cin>>c1>>c2;
	c1=(c2-c1)/100;
	int time=(int)(c1+0.5);
	int hour=time/3600;
	time%=3600;
	int minute=time/60;
	time%=60;
	say(hour);
	cout<<":";
	say(minute);
	cout<<":";
	say(time);
	//cout<<hour<<":"<<minute<<":"<<time<<endl;
	return 0;
}
