#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> num(n);
	int count=0;
	while(n!=0){
		cin>>num[count];
		count++;
		n--;
	}
	count=0;
	int sum=0;
	map<int,int> hello;
	for(int i=0;i<num.size()-1;i++){
		for(int j=i+1;j<num.size();j++){
			count=num[i]*10+num[j];
			hello[count]++;
			if(hello[count]==1) sum+=count;
			count=num[j]*10+num[i];
			hello[count]++;
			if(hello[count]==1) sum+=count;
		}
	}
	cout<<sum<<endl;
	return 0;
}
