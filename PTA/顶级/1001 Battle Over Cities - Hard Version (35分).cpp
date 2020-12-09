#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int n,m,par[505],cnt,par_copy[505];
int max_cost=0,ans[505],ans_cnt,inf=0x7fffffff;
struct node{
    int x,y,cost,ok;
}e[1000000];
int find(int a){
    if(a==par[a]) return a;
    else return par[a]=find(par[a]);
}
bool merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return false;
    par[a]=b;
    cnt--;
    return true;
}
void assign(){
    memcpy(par+1,par_copy+1,n*sizeof(int));
}
int func(int index){
    int cost=0;
    cnt=n-1;
    assign();
    for(int i=0;i<m && cnt!=1;i++){
        if(e[i].x==index || e[i].y==index) continue;
        if(merge(e[i].x,e[i].y)){
            if(!e[i].ok) cost+=e[i].cost;
        }
    }
    return cnt==1?cost:inf;
}

int main(){
    scanf("%d %d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++) par_copy[i]=i;
    for(int i=0;i<m;i++){
        scanf("%d %d %d %d",&e[i].x,&e[i].y,&e[i].cost,&e[i].ok);
        getchar();
    }
    sort(e,e+m,[](node&a,node&b){
        if(a.ok!=b.ok) return a.ok>b.ok;
        else return a.cost<b.cost;
    });
    for(int i=1;i<=n;i++){
        int cost=func(i);
        //cout<<i<<" "<<cost<<endl;
        if(cost>max_cost){
            max_cost=cost;
            ans_cnt=0;
            ans[ans_cnt++]=i;
        }else if(cost==max_cost){
            ans[ans_cnt++]=i;
        }
    }
    if(max_cost==0){
        printf("0\n");
    }else{
        for(int i=0;i<ans_cnt;i++){
            if(i) putchar(' ');
            printf("%d",ans[i]);
        }
        putchar('\n');
    }
    return 0;
}   