#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
	string line;
	getline(cin,line);
	int count=0;
	for(int i=0;i<line.length();i++){
		if(line[i]==' ') count++;
	}
	//cout<<count<<endl;
	istringstream h(line);
	int a,b;
	int temp=0;
	for(int i=0;i<(count+1)/2;i++){
		h>>a>>b;
		a=a*b;
		b=b-1;
		if(b==-1){
			a=0;
			b=0;
			if(count!=1) continue;
		}
		if(temp){
			cout<<" "<<a<<" "<<b;
		}else{
			cout<<a<<" "<<b;
		}
		temp++;
	}
	return 0;
}



