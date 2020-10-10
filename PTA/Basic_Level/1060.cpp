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
	int n,n_temp;
	cin>>n;
	n_temp=n;
	double a,b,temp=0,max=-1;
	while(n_temp!=0){
		cin>>a>>b;
		temp=sqrt(a*a+b*b);
		if(temp>max) max=temp;
		n_temp--;
	}
	max=(double)(int)(max*100+0.5)/100;
	printf("%.2lf\n",max);
	return 0;
}	
	
