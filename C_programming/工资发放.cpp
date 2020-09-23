#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	//100、50、20、10、5、1
	int a;
	scanf("%d\n",&a);
	int d[6]={100,50,20,10,5,1};
	for(int i=0;i<6;i++){
		if(i) printf(" ");
		printf("%d",a/d[i]);
		a%=d[i];
	}
	printf("\n");
    return 0;
}