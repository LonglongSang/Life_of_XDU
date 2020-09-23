#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int a,b,c,d;
	scanf("%d %d %d %d\n",&a,&b,&c,&d);
	if(a/b==c && a%b==d){
		printf("yes\n");
	}else{
		printf("%d %d\n",a/b,a%b);
	}
    return 0;
}