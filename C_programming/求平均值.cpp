#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int a,b,c;
	scanf("%d %d %d\n",&a,&b,&c);
	printf("%.2f\n",(float)(a+b+c)/3);
    return 0;
}