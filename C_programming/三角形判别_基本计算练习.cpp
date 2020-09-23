#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int a,b,c;
	scanf("%d %d %d\n",&a,&b,&c);
	if(a+b>c && a+c>b && b+c>a){
		printf("%d\n",a+b+c);
	}else{
		printf("No\n");
	}
    return 0;
}