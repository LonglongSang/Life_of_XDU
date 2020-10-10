#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
	double a,b,c,d,e,f,g,h,i,j;
	cin>>e>>f>>g>>h;
	a=e*cos(f);
	b=e*sin(f);
	c=g*cos(h);
	d=g*sin(h);
	i=a*c-b*d;
	j=a*d+c*b;
	if(i>0){
		i=(double)(int)(i*100+0.5)/100;		
	}else{
		i=(double)(int)(i*100-0.5)/100;
	}
	if(i>0){
		j=(double)(int)(j*100+0.5)/100;		
	}else{
		j=(double)(int)(j*100-0.5)/100;
	}


	printf("%.2lf",i);
	if(j<0){
		printf("%.2lfi",j);
	}else{
		printf("+%.2lfi",j);
	}
	
	return 0;
}



