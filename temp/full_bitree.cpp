#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
#define N 100
int n,val[N],t[N],cnt;
void pfs(int cur){
    if(cur>n) return;
    pfs(cur*2);
    pfs(cur*2+1);
    t[cur]=val[++cnt];
}
void level_traverse(){
    queue<int> Q;
    Q.push(1);
    int i=0,cur;
    while(!Q.empty()){
        cur=Q.front();
        Q.pop();
        if(i++) putchar(' ');
        printf("%d",t[cur]);
        for(int i=0;i<2;i++) if(cur*2+i<=n) Q.push(cur*2+i);
    }
    putchar('\n');
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",val+i+1);
    pfs(1);
    level_traverse();
    return 0;
}