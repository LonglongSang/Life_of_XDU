#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;
#define N 100005
bool vis[10001];
int n,st,add,nex,v,cur,cnt,rel1,rel2;
struct node{
    int val;
    int next;
}arr[N];
int a[N],b[N];
void pri(int *a,int rel){
    for(int i=0;i<rel-1;i++) printf("%0.5d %d %0.5d\n",a[i],arr[a[i]].val,a[i+1]);
    printf("%0.5d %d %0.5d\n",a[rel-1],arr[a[rel-1]].val,-1);
}
int main(){
    scanf("%d%d",&st,&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&add,&v,&nex);
        arr[add].next=nex;
        arr[add].val=v;
    }
    cur=st;
    while(cur!=-1){
        a[cnt++]=cur;
        cur=arr[cur].next;
    }
    for(int i=0;i<cnt;i++){
        if(!vis[abs(arr[a[i]].val)]) a[rel1++]=a[i];
        else b[rel2++]=a[i];
        vis[abs(arr[a[i]].val)]=true;
    }
    pri(&a[0],rel1);
    pri(&b[0],rel2);
    return 0;
}