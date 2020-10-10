#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	int time;
	int run_time=0;
	cin>>time;
	int rabbit=0;
	int turtle=0;
	int sleep=0;
	int sleep_time=0;
	while(run_time!=time){
		if(sleep==0 && run_time%10==0 && run_time!=0 && rabbit>turtle){
			//cout<<"i am sleeping"<<endl;
			sleep=1;
		}
		turtle+=3;
		if(sleep==0) rabbit+=9;
		if(sleep==1) sleep_time++;
		if(sleep_time%30==0 && sleep_time!=0) sleep=0;
		run_time++;
	}
	//cout<<rabbit<<" "<<turtle<<endl;
	if(turtle>rabbit){
		cout<<"@_@ "<<turtle<<endl;
	}else if(turtle==rabbit){
		cout<<"-_- "<<turtle<<endl;
	}else{
		cout<<"^_^ "<<rabbit<<endl;
	}
	return 0;
}