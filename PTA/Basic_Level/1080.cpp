#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;
void input(int n,map<string,double> &in,map<string,double> &fir,map<string,double> &sec){
	string name;
	int grade;
	while(n!=0){
		cin>>name>>grade;
		in[name]=grade;
		if(!fir[name]){
			fir[name]=-1;
		}
		if(!sec[name]){
			sec[name]=-1;
		}
		n--;
	}
}
int main(){
	int P,N,K;
	cin>>P>>N>>K;
	map<string,double> Online,Mid,Final;
	input(P,Online,Mid,Final);
	input(N,Mid,Final,Online);
	input(K,Final,Online,Mid);
	multimap<double,string> output;
	double grade;
	double mid_grade,final_grade;
	map<string,double>::iterator it;
	for(it=Online.begin();it!=Online.end();it++){
		//cout<<it->first<<" "<<Online[it->first]<<" "<<Mid[it->first]<<" "<<Final[it->first]<<endl;
		mid_grade=Mid[it->first];
		final_grade=Final[it->first];
		if(mid_grade==-1) mid_grade=0;
		if(final_grade==-1) final_grade=0;
		grade=mid_grade*0.4+final_grade*0.6;
		if(mid_grade>final_grade){
			grade=mid_grade*0.4+final_grade*0.6;
		}else{
			grade=final_grade;
		}
		if(it->second>=200 && grade>=60){
			output.insert(pair<double,string>(grade,it->first));
		}
	}
	int a;
	map<double,string>::reverse_iterator itt;
	for(itt=output.rbegin();itt!=output.rend();itt++){
		cout<<itt->second;
		a=(int)(itt->first+0.5);
		printf(" %.0lf %.0lf %.0lf %d\n",Online[itt->second],Mid[itt->second],Final[itt->second],a);
	}
	return 0;
}	
	
