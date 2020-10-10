#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	a=a*b;
	int sum=0;
	while(a!=0){
		sum=sum*10+a%10;
		a/=10;
	}
	cout<<sum<<endl;
	return 0;
}