#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
using namespace std;
int main(){
	int total,interval,start;
	cin>>total>>interval>>start;
	//cout<<total<<interval<<start<<endl;
	if(start>total){
		cout<<"Keep going..."<<endl;
		return 0;
	}
	map<string,char> dp;
	int count=1;
	string name;
	while(total!=0){
		cin>>name;
		if(count>=start && (count-start)%interval==0){
			if(dp.find(name)==dp.end()){
				cout<<name<<endl;
				dp.insert(pair<string,char>(name,'a'));
				count++;
			}
		}else{
			count++;			
		}
		total--;
	}
	return 0;
}
