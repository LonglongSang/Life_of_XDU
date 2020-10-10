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
	int n,m,temp;
	scanf("%d %d\n",&n,&m);
	m=m%n;
	vector<int> num;
	while(n!=0){
		cin>>temp;
		num.push_back(temp);
		n--;
	}
	
	if(m!=0){
		reverse(num.begin(),num.end()-m);
		reverse(num.end()-m,num.end());
		reverse(num.begin(),num.end());
	}
	cout<<num[0];
	for(int i=1;i<num.size();i++) cout<<" "<<num[i];
	return 0;
}	
	
