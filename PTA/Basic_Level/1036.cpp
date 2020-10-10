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
	double edge;
	char a;
	cin>>edge;
	cin>>a;
	double how=(int)(edge*0.5+0.5)-2;
	for(int i=0;i<edge;i++) cout<<a;
	cout<<endl;
	for(int i=0;i<how;i++){
		cout<<a;
		for(int j=0;j<edge-2;j++) cout<<" ";
		cout<<a<<endl;
	}
	for(int i=0;i<edge;i++) cout<<a;
	cout<<endl;
	return 0;
}

