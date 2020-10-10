#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;
int main(){
	string max="2014/09/06",min="1814/09/06",young="0",old="3",old_name,young_name,date,name;
	date.resize(10);
	name.resize(10);
	int n,count=0;
	scanf("%d\n",&n);
	for(int i=0;i<n;i++){
		scanf("%s %s\n",&name[0],&date[0]);
		if(date>=min && date<=max){
			count++;
			if(date>young){
				young=date;
				young_name=name;
			}
			if(date<old){
				old=date;
				old_name=name;
			}
		}
	}
	if(count!=0)printf("%d %s %s\n",count,old_name.c_str(),young_name.c_str());
	else cout<<"0"<<endl;
    return 0;
}
