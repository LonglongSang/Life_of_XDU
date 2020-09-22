#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    double a;
    scanf("%lf\n",&a);
    printf("%.2lf\n",(a-32)*5/9);
    return 0;
}