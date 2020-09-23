#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int a;
	scanf("%d\n",&a);
	if(a%5==0 && a%7==0) printf("yes\n");
	else printf("no\n");
    return 0;
}