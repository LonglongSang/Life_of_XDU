#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
int main(){
	double a,max=-1000,sum=1;
	int index;
	string mem="WTL";
	vector<char> type(3);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>a;
			if(a>max){
				max=a;
				index=j;
			}
		}
		sum*=max;
		type[i]=mem[index];
		max=-1000;
	}
	sum=(double)(int)(((sum*0.65-1)*2)*100+0.5)/100;
	cout<<type[0]<<" "<<type[1]<<" "<<type[2]<<" "<<sum<<endl;
	return 0;
}
