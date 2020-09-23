#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int main(){
	float a,b,c;
	scanf("%f %f %f\n",&a,&b,&c);
	float p=(a+b+c)/2;
	printf("%.2f\n",sqrt(p*(p-a)*(p-b)*(p-c)));
    return 0;
}