#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){
    double h,m;
    scanf("%lf %lf\n",&h,&m);
    h+=m/60;
    printf("%.2lf\n",h*h*4/(h+2)-20);
    return 0;
}