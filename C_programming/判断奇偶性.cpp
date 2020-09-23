#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int a;
    scanf("%d\n",&a);
    if(a%2){
        printf("奇数\n");
    }else{
        printf("偶数\n");
    }
    return 0;
}