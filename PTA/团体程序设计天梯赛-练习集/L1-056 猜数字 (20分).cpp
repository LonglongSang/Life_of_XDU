#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
int n,sum;
int ans=-1000;
int abss(int a,int b){
    return a>b?a-b:b-a;
}
struct node{
    char name[20];
    int g;
}a[10005];
int main(){
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        scanf("%s %d\n",a[i].name,&a[i].g);
        sum+=a[i].g;
    }
    sum=(int)((double)sum/2/n);
    int index;
    for(int i=0;i<n;i++){
        if(abss(sum,ans)>abss(a[i].g,sum)){
            ans=a[i].g;
            index=i;
        }
    }
    printf("%d %s\n",sum,a[index].name);
    return 0;
}