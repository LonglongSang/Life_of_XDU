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
	int n;
	cin>>n;
	vector<int> count(100001,0);
	int index;
	int grade;
	int max=-1;
	while(n!=0){
		cin>>index>>grade;
		if(index>max) max=index;
		count[index]+=grade;
		n--;
	}
	grade=-1;
	for(int i=1;i<=max;i++){
		if(count[i]>grade){
			grade=count[i];
			index=i;
		}
	}
	cout<<index<<" "<<grade<<endl;
	return 0;
}

