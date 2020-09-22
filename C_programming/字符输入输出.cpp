#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){
    char a;
    for(int i=0;i<5;i++){
        scanf("%c",&a);
        getchar();
        printf("%c",a-'A'+'a');
    }
    printf("!");
    return 0;
}