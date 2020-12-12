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
using T=int;
int cnt_cmp,cnt_swap;
T arr[N],temp[N];
void mergeSort(T* arr,int lower,int upper,bool (*cmp)(T&,T&b)){
    if(1+lower>=upper) return;
    
    int mid=lower+(upper-lower)/2;
    mergeSort(arr,lower,mid,cmp);
    mergeSort(arr,mid,upper,cmp);
    
    int i=lower,j=mid,k=lower;
    while(i<mid && j<upper){
        if(cmp(arr[i],arr[j])) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
        cnt_cmp++;
    }
    while(i<mid) temp[k++]=arr[i++];
    while(j<upper) temp[k++]=arr[j++];
    memcpy(arr+lower,temp+lower,sizeof(T)*(upper-lower));
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
    mergeSort(arr,0,n,cmp);
    delete []arr;
}
void increTest(int n){
    int* arr=new int[n];
    srand(time(0));
    arr[0]=0x80000000;
    for(int i=1;i<n;i++){
        arr[i]=arr[i-1]+rand()%100;
    }
    mergeSort(arr,0,n,cmp);
    delete []arr;
}
void decTest(int n){
    int* arr=new int[n];
    srand(time(0));
    arr[0]=0x7fffffff;
    for(int i=1;i<n;i++){
        arr[i]=arr[i-1]-rand()%100;
    }
    mergeSort(arr,0,n,cmp);
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
    mergeSort(arr,0,n,cmp);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    delete []arr;
}
int main(){
    int n=10000,m=100;
    if(0){
        orderedTest(100);
    }
    if(1){
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