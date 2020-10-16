#include <stdio.h>
#include <iostream>
#include <vector>
#include  <unordered_set>
#include <set>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <stack>
#include <string>
using namespace std;
int n,m,k,top,want;
int s[10000];
int path[1005];
void out(){
    while(top && s[top-1]==want){
        top--;
        want++;
    }
}
int main(){
    scanf("%d %d %d\n",&n,&m,&k);
    for(int a=0;a<k;a++){
        for(int i=0;i<n;i++){
            scanf("%d",path+i);
            getchar();
        }
        want=1;
        top=0;
        for(int i=0;top<=m && i<n;i++){
            out();
            if(path[i]==want) want++;
            else s[top++]=path[i];
            out();
        }
        if(top>m){
            printf("NO\n");
            continue;
        }
        out();
        if(top) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}