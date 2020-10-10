#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <set>
using namespace std;
int main(){
	int n;
	int sum=0;
	cin>>n;
	int last=0,temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		if(temp>=last){
			sum+=(temp-last)*6+5;
		}else{
			sum+=(last-temp)*4+5;
		}
		last=temp;
	}
	cout<<sum<<endl;
	return 0;
}
