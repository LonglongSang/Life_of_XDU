#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int a;
    scanf("%d\n",&a);
    printf("%d %d %d %d %d\n",a/10000,a%10000/1000,a%1000/100,a%100/10,a%10);
    return 0;
}