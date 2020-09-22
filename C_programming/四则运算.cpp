#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    //和差积商余
    int a,b;
    char op;
    scanf("%d%c%d\n",&a,&op,&b);
    if(op=='+') printf("%d%c%d=%d",a,op,b,a+b);
    else if(op=='-') printf("%d%c%d=%d",a,op,b,a-b);
    else if(op=='*') printf("%d%c%d=%d",a,op,b,a*b);
    else if(op=='/') printf("%d%c%d=%d",a,op,b,a/b);
    else if(op=='%') printf("%d%c%d=%d",a,op,b,a%b);
    return 0;
}