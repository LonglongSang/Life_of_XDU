#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int n,h,r,g;
int want(){
    return (h-100)*9*2;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&h,&r);
        r*=100;
        g=want();
        if(r>11*g){
            printf("You are tai pang le!\n");
        }else if(r<9*g){
            printf("You are tai shou le!\n");
        }else{
            printf("You are wan mei!\n");
        }
    }
}