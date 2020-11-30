#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
char x[10000];
int cnt;
int main(){
    scanf("%[^\n]",x);
    char*s=&x[0];
    while(*s){
        if(*s!='6'){
            putchar(*s);
            s++;
        }else{
            cnt=0;
            while(*s && *s=='6') s++,cnt++;
            if(cnt>9) putchar('2'),putchar('7');
            else if(cnt>3) putchar('9');
            else{
                for(int i=0;i<cnt;i++) putchar('6');
            }
        }
    }

}