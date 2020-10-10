#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
int main(){
	int length;
	string line;
	getline(cin,line);
	length=line.length();
	double n1;
	int n1_int,n2;
	for(int i=3;i<=length;i++){
		n1=(double)(length+2-i)/2;
		n1_int=(length+2-i)/2;
		if(n1==n1_int && n1_int>0){
			n2=i;
		}
	}
	cout<<n1<<" "<<n2<<endl;
	return 0;
}


