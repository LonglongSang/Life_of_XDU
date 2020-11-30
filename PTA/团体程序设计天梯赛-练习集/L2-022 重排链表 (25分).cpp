#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define N 100005
int a,d,b,n,st,v;
struct node{
    int val;
    int next;
}arr1[N];
int arr2[N],arr3[N];
int main(){
    scanf("%d%d",&st,&n);
    
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a,&v,&b);
        arr1[a].next=b;
        arr1[a].val=v;
    }
    int cur=st,cnt=0;
    while(cur!=-1){
        arr2[cnt++]=cur;
        cur=arr1[cur].next;
    }
    int low=0,high=cnt-1,typ=1;
    cnt=0;
    while(high>=low){
        if(typ){
            arr3[cnt++]=arr2[high--];
        }else{
            arr3[cnt++]=arr2[low++];
        }
        typ^=1;
    }
    for(int i=0;i<n-1;i++){
        printf("%0.5d %d %0.5d\n",arr3[i],arr1[arr3[i]].val,arr3[i+1]);
    }
    printf("%0.5d %d -1\n",arr3[n-1],arr1[arr3[n-1]].val,-1);
}