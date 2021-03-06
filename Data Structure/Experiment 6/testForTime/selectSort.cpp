#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <time.h>
#include <limits.h>
using namespace std;
#define N 10005
int arr[N],cnt_cmp,cnt_swap;
template <typename T>
void selectSort(T* arr,int lower,int upper,bool(*cmp)(T&,T&)){
    int v;
    for(int i=upper-1;i>=lower;i--){
        v=i;
        for(int j=lower;j<i;j++){
            if(cmp(arr[v],arr[j])) v=j;
        }
        std::swap(arr[i],arr[v]);
    }
}






bool cmp(int &a,int &b){
    return a<b;
}
void randTest(int n){
    int* arr=new int[n];
    srand(time(0));
    for(int i=0;i<n;i++){
        arr[i]=rand()%INT_MAX;
    }
    selectSort(arr,0,n,cmp);
    delete []arr;
}
void increTest(int n){
    int* arr=new int[n];
    srand(time(0));
    arr[0]=0x80000000;
    for(int i=1;i<n;i++){
        arr[i]=arr[i-1]+rand()%100;
    }
    selectSort(arr,0,n,cmp);
    delete []arr;
}
void decTest(int n){
    int* arr=new int[n];
    srand(time(0));
    arr[0]=0x7fffffff;
    for(int i=1;i<n;i++){
        arr[i]=arr[i-1]-rand()%100;
    }
    selectSort(arr,0,n,cmp);
    delete []arr;
}

void orderedTest(int n){
    int* arr=new int[n];
    srand(time(0));
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
        printf("%d ",arr[i]);
    }
    putchar('\n');
    putchar('\n');
    selectSort(arr,0,n,cmp);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    delete []arr;
}
int main(){
    int n=10000,m=100;
    if(1){
        orderedTest(100);
    }
    if(0){
        for(int i=0;i<m;i++) randTest(n);
    }
    if(0){
        for(int i=0;i<m;i++) increTest(n);
    }
    if(0){
        for(int i=0;i<m;i++) decTest(n);
    }
    cout<<cnt_cmp<<endl;

}