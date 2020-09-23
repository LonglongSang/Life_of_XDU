#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int tie,jin;
    double p1=7.86,p2=19.3,pi=3.1415926;
    double a,b;
    scanf("%lf %lf\n",&a,&b);
    a/=20.0;
    b/=20.0;
    printf("%.3lf %.3lf\n",p1*a*a*a*pi*4/3,p2*b*b*b*pi*4/3);
    return 0;
}