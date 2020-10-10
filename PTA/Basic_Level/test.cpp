#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;

int main(){
	
	map<string,vector<int>> name;
	name["a"];
	name["a"].resize(3,-1);
	for(int i=0;i<name["a"].size();i++){
		cout<<name["a"][i]<<endl;
	}
	vector<int> aa;
	//aa[100]=100;
	//for(int i=0;i<aa.size();i++) cout<<aa[i]<<endl;
	return 0;
}	
	
