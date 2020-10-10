#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm> //sort
#include <sstream>
using namespace std;
int main(){
	string line;
	getline(cin,line);
	vector<int> P(line.length(),0);
	vector<int> T(line.length(),0);
	long sum=0,remainder=1000000007;
	for(int i=0;i<line.length();i++){
		if(line[i]=='P'){
			sum++;
		}else if(line[i]=='A'){
			P[i]=sum;
		}
	}
	sum=0;
	for(int i=line.length()-1;i>=0;i--){
		if(line[i]=='T'){
			sum++;
		}else if(line[i]=='A'){
			T[i]=sum;
		}
	}
	sum=0;
	for(int i=0;i<line.length();i++){
		if(line[i]=='A'){
			sum+=P[i]*T[i];
			if(sum>remainder) sum=sum%remainder;
		}
	}
	cout<<sum<<endl;
	return 0;
}


