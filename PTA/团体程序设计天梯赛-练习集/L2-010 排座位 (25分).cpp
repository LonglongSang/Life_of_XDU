#include <stdio.h>
#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
int t[101][101];
int n,m,k,a,b,typ;
int par[101];
int find(int a){
    while(par[a]!=0){
        a=par[a];
    }
    return a;
}
void uniona(int a,int b){
    int _a=find(a);
    int _b=find(b);
    if(_a!=_b){
        if(_a>_b) swap(_a,_b);
        par[_a]=_b; 
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d %d %d\n",&a,&b,&typ);
        t[a][b]=typ;
        t[b][a]=typ;
        if(typ==1) uniona(a,b);
    }
    for(int i=0;i<k;i++){
        scanf("%d %d\n",&a,&b);
        if(t[a][b]!=-1 && find(a)==find(b)){
            printf("No problem\n");
        }else if(t[a][b]!=-1){
            printf("OK\n");
        }else if(find(a)==find(b)){
            printf("OK but...\n");
        }else{
            printf("No way\n");
        }
    }
}