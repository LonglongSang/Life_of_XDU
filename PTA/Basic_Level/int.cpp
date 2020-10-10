#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;
int main(){
	map<string,map<string,int>> a;
	a["ad"]["ad"]++;
	if(a["ad"]["as"]){
		cout<<"adds"<<endl;
	}
	if(a["a"]["ad"]++){
		cout<<"adds"<<endl;
	}else{
		cout<<"as"<<endl;
	}
	vector <int> ab;
	cout<<ab.size()<<endl;
	ab.resize(0);
	return 0;
}
