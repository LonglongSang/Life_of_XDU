#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int v,mi=127,ma=0;
int i;
int main(){
    scanf("%d\n",&v);
    if(v==0){
        printf("0 0 0\n");
        return 0;
    }
    while(v){
        ma=max(ma,v%10);
        i++;
        mi=min(mi,v%10);
        v/=10;
    }
    printf("%d %d %d\n",i,ma,mi);
    return 0;
}