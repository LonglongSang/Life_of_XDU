/*
https://vijos.org/p/1779
国王游戏
本题只得到了60分
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
using namespace std;
struct node{
    double a,b;
}arr[1005];
int main(void){
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n+1;i++){
        scanf("%lf %lf\n",&arr[i].a,&arr[i].b);
        //cout<<arr[i].a<<" "<<arr[i].b<<endl;
    }
    sort(arr+1,arr+n+1,[](const node&x,const node &y){
        return x.a*x.b+y.b < y.a*y.b+x.b;
    });
    double ans=0;
    double mul=arr[0].a;
    for(int i=1;i<=n;i++){
        ans=max(ans,mul/arr[i].b);
        mul*=arr[i].a;
    }
    printf("%d\n",(int)ans);
    return 0;
}


