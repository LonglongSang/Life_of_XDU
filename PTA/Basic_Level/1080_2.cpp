#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;
void input(map< string,vector<int> > &name,int order,int count){
	string my_name;
	int grade;
	while(count!=0){
		cin>>my_name>>grade;
		if(!name.count(my_name)) name[my_name].resize(3,-1);
		name[my_name][order]=grade;
		count--;
	}
}xalloc
int main(){
	int P,N,K;
	cin>>P>>N>>K;
	map< string,vector<int> > name;
	map<int,map< string,int > > output;
	input(name,0,P);
	input(name,1,N);
	input(name,2,K);
	double grade;
	int mid_grade,final_grade;
	map< string,vector<int> >::iterator it;
	for(it=name.begin();it!=name.end();it++){
		mid_grade=it->second[1];
		final_grade=it->second[2];
		if(it->second[1]==-1) mid_grade=0;
		if(it->second[2]==-1) final_grade=0;
		grade=final_grade;
		if(mid_grade>final_grade) grade=mid_grade*0.4+final_grade*0.6;
		grade=(double)(int)(grade+0.5);
		if(it->second[0]>=200 && grade>=60){
			 if(output.count(grade)){
				 output[grade].insert(pair< string,int >(it->first,1));
			 }else{
				 map<string,int> out;
				 output.insert(pair< int,map<string,int> >(grade,out));
				 output[grade].insert(pair< string,int >(it->first,1));
			 }
		}
	}
	map<int,map< string,int > >::reverse_iterator itt;
	map< string,int >::iterator hello;
	for(itt=output.rbegin();itt!=output.rend();itt++){
		for(hello=itt->second.begin();hello!=itt->second.end();hello++){
			string my_name=hello->first;
			cout<<my_name;
			printf(" %d %d %d %d\n",name[my_name][0],name[my_name][1],name[my_name][2],itt->first);			
		}
	}
	return 0;
}	
	
