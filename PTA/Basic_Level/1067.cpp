#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
int main(){
	string good,temp;
	int time;
	cin>>good>>time;

	bool in=false;
	bool inter=false;
	for(int i=0;i<time;i++){
		getline(cin,temp);
		if(temp.length()==1 && temp[0]=='#'){
			inter=true;
			break;
		}
		if(good==temp){
			in=true;
			break;
		}else{
			cout<<"Wrong password: "<<temp<<endl;
		}
	}
	if(inter) return 0;
	if(in){
		cout<<"Welcome in"<<endl;
	}else{
		cout<<"Account locked"<<endl;
	}
	return 0;
}



