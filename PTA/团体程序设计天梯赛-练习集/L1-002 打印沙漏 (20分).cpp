/*
L1-002 打印沙漏 (20分)

*****
 ***
  *
 ***
*****
*/
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,level;
char v;
bool good(int a){
    return 2*a*a-1<=n;
}
int getlen(int i){
    return i*2-1;
}
void pri(int a){
    for(int i=0;i<(getlen(level)-getlen(a))/2;i++) putchar(' ');
    for(int i=0;i<getlen(a);i++) putchar(v);
    putchar('\n');
}
int main(){
    scanf("%d %c",&n,&v);
    for(int i=1000;i>=1;i--){
        if(good(i)){
            level=i;
            break;
        }
    }
    for(int i=level;i>=1;i--) pri(i);
    for(int i=2;i<=level;i++) pri(i);
    printf("%d\n",n+1-2*level*level);
}
