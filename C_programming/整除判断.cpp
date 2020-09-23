#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){
    int a,b;
    scanf("%d %d\n",&a,&b);
    if(a%b==0){
        printf("yes\n");
    }else{
        printf("%d %d\n",a/b,a%b);
    }
    return 0;
}