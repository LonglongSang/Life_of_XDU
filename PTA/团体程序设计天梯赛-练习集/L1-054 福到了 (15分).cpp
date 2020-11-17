#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using  namespace std;
int n;
#define N 1000
char g[N][N],v;
/*
$ 9
 @  @@@@@
@@@  @@@ 
 @   @ @ 
@@@  @@@ 
@@@ @@@@@
@@@ @ @ @
@@@ @@@@@
 @  @ @ @
 @  @@@@@

*/
int main(){
    scanf("%c %d",&v,&n);
    getchar();
    
    for(int i=0;i<n;i++){
        scanf("%[ @]",g[i]);
        getchar();
    }
    bool same=true;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(g[i][j]!=g[n-1-i][n-1-j]){
                same=false;
                break;
            }
        }
    }
    if(same) printf("bu yong dao le\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[n-1-i][n-1-j]=='@') putchar(v);
            else putchar(g[n-1-i][n-1-j]);
        }
        putchar('\n');
    }
    return 0;
}
