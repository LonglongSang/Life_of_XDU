#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int hour,min;
	scanf("%d:%d",&hour,&min);
	if(hour<12){
		cout<<hour<<":"<<min<<" AM"<<endl;
	}else if(hour==12){
		cout<<hour<<":"<<min<<" PM"<<endl;
	}else{
		cout<<(hour-12)<<":"<<min<<" PM"<<endl;
	}
	return 0;
}