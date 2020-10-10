#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;
bool small(int now_year,int now_month,int now_day,int com_year,int com_month,int com_day){
	if(now_year<com_year){
		return true;
	}else if(now_year==com_year){
		if(now_month<com_month){
			return true;
		}else if(now_month==com_month){
			if(now_day<=com_day){
				return true;
			}else{
				return false;
			}
		}
	}
	return false;
}
bool great(int now_year,int now_month,int now_day,int com_year,int com_month,int com_day){
	if(now_year>com_year){
		return true;
	}else if(now_year==com_year){
		if(now_month>com_month){
			return true;
		}else if(now_month==com_month){
			if(now_day>=com_day){
				return true;
			}else{
				return false;
			}
		}
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	string young,old,now;
	int cin_year,cin_month,cin_day;
	int young_year=1800,young_month=9,young_day=6;
	int old_year=2015,old_month=9,old_day=6;
	scanf("\n");
	int count=0;
	while(n!=0){
		cin>>now;
		scanf(" %d/%d/%d\n",&cin_year,&cin_month,&cin_day);
		//cout<<cin_year<<"/"<<cin_month<<"/"<<cin_day<<endl;
		if(great(cin_year,cin_month,cin_day,1814,9,6) && small(cin_year,cin_month,cin_day,2014,9,6)){
			//cout<<now<<endl;
			//cout<<cin_year<<"/"<<cin_month<<"/"<<cin_day<<endl;
			count++;
			if(small(cin_year,cin_month,cin_day,old_year,old_month,old_day)){
				old_year=cin_year;
				old_month=cin_month;
				old_day=cin_day;
				old=now;
			}
			if(great(cin_year,cin_month,cin_day,young_year,young_month,young_day)){
				young_year=cin_year;
				young_month=cin_month;
				young_day=cin_day;
				young=now;
			}
		}
		n--;
	}
	if(count!=0){
		cout<<count<<" "<<old<<" "<<young<<endl;		
	}else{
		cout<<0<<endl;
	}

	return 0;
}
