#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
#include <iomanip>
using namespace std;
int to_int(string a){
	int hour=0,min=0,sec=0;
	istringstream h(a);
	cout<<a<<endl;
	cout<<h.str()<<endl;
	h>>hour>>min>>sec;
	int ret=hour*60*60+min*60+sec;
	cout<<hour<<" "<<min<<" "<<sec<<endl;
	cout<<"ret is"<<ret<<endl;
	return ret;
}
string being_string(int a){
	ostringstream h;
	int hour,min,sec;
	hour=a/3600;
	min=(a-hour*3600)/60;
	sec=a-hour*3600-min*60;
	h<<setfill('0')<<setw(2)<<hour<<":"<<setfill('0')<<setw(2)<<min<<":"<<setfill('0')<<setw(2)<<sec;
	string ret=h.str();
	cout<<"being string"<<ret<<endl;
	return ret;
}
bool cal_time(map<string,int> &counter,string &arrive_time,int &processing_time,int &sum,string &seventeen){
	map<string,int>::iterator up=counter.begin();
	cout<<"first is "<<up->first<<endl;
	string time=up->first;
	if( seventeen< up->first){
		return false;
	}else{
		int now=to_int(time);
		sum+=now-to_int(arrive_time)+processing_time*60;
		int b=now+processing_time*60;
		cout<<"now is"<<now<<"b is "<<b<<endl;
		string a=being_string(b);
		if(up->second==1){
			counter.erase(time);		
		}else{
			up->second--;
		}
		//cout<<"next"<<a<<endl;
		counter.insert(pair<string,int>(a,to_int(a)));			
		return true;
	}
}
int main(){
	int people,line;
	scanf("%d %d\n",&people,&line);
	//cout<<people<<" "<<line<<endl;
	int sum=0;
	string arrive_time;
	int pro_cessing;
	map<string,int> counter;
	string eight_string="08:00:00";
	string seventeen="17:00:00";
	int people_count=0;
	counter.insert(pair<string,int>(eight_string,line));
	for(int i=0;i<people;i++){
		cin>>arrive_time>>pro_cessing;
		//cout<<"cin"<<arrive_time<<" "<<pro_cessing<<endl;
		if(arrive_time<eight_string){
			sum+=to_int(eight_string)-to_int(arrive_time);
			arrive_time=eight_string;
		}

		if(cal_time(counter,arrive_time,pro_cessing,sum,seventeen)){
			people_count++;
		}else{
			break;
		}
	}
	double a=(double)sum;
	cout<<a<<endl;
	a=a/people_count;
	string cc="17:00:00";
	cout<<to_int(cc)<<endl;
	return 0;
}