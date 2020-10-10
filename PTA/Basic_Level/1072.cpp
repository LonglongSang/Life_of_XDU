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
	int stu,type,temp;
	vector<int> dp(10000,0);
	cin>>stu>>type;
	for(int i=0;i<type;i++){
		cin>>temp;
		dp[temp]++;
	}
	string name;
	int count_student=0,count_thing=0,already;
	for(int i=0;i<stu;i++){
		cin>>name>>type;
		already=0;
		for(int i=0;i<type;i++){
			cin>>temp;
			if(dp[temp]!=0){
				if(already==0){
					cout<<name<<":";
					already=1;
					count_student++;
				}
				count_thing++;
				printf(" %.4d",temp);
			}
		}
		if(already==1) printf("\n");
	}
	cout<<count_student<<" "<<count_thing<<endl;
	return 0;
}



