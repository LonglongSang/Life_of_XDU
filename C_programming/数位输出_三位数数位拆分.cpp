#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int a;
	scanf("%d\n",&a);
	printf("%d %d %d\n",a/100,a%100/10,a%10);
    return 0;
}