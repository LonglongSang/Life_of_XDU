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
	map<int,int> temp;
	for(int i=1;i<=n;i++){
		temp[i/2+i/3+i/5]++;
	}
	cout<<temp.size()<<endl;
	return 0;
}	
	
	
