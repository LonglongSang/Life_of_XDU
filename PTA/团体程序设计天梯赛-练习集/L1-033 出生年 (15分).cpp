#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <unordered_map>
using namespace std;
#define N 200005
bool dig[10];
int y,l;
bool isok(int a){
    if(a==0) return a==l;
    int len=0;
    memset(dig,0,10);
    while(a){
        dig[a%10]=true;
        a/=10;
        len++;
    }
    if(len<4) dig[0]=true;
    len=0;
    for(int i=0;i<10;i++) if(dig[i]) len++;
    return len==l;

}
int main(){
    cin>>y>>l;
    int x=y;
    while(1){
        if(isok(x)){
            printf("%d %0.4d\n",x-y,x);
            return 0;
        }
        x++;
    }
}