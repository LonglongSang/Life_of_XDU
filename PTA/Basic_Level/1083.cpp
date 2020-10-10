#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
using namespace std;
int main(){
	int n,input;
	cin>>n;
	map<int,int> count;
	int num=1;
	while(n!=0){
		cin>>input;
		input=num-input;
		if(input<0) input=-input;
		count[input]++;
		num++;
		n--;
	}
	for(auto it=count.rbegin();it!=count.rend();it++){
		if(it->second>1)cout<<it->first<<" "<<it->second<<endl;
	}
	
	return 0;
}