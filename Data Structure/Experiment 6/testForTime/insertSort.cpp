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
int cnt_cmp,cnt_swap;


template <typename T>
void insertSort(T* arr,int lower,int upper,bool(*cmp)(T&,T&)){
    //直接插入排序
    //对[arr+lower,arr+upper)范围进行排序
    int low,high,mid,tar;
    T temp;
    for(int i=lower+1;i<upper;i++){
        low=lower,high=i-1,tar=i;
        temp=arr[i];
        while(high>=low){
            mid=low+(high-low)/2;
            cnt_cmp++;
            if(cmp(arr[i],arr[mid])){
                tar=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        for(int j=i-1;j>=tar;j--) arr[j+1]=arr[j],cnt_swap++;
        arr[tar]=temp;
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
    insertSort(arr,0,n,cmp);
    delete []arr;
}
void increTest(int n){
    int* arr=new int[n];
    srand(time(0));
    arr[0]=0x80000000;
    for(int i=1;i<n;i++){
        arr[i]=arr[i-1]+rand()%100;
    }
    insertSort(arr,0,n,cmp);
    delete []arr;
}
void decTest(int n){
    int* arr=new int[n];
    srand(time(0));
    arr[0]=0x7fffffff;
    for(int i=1;i<n;i++){
        arr[i]=arr[i-1]-rand()%100;
    }
    insertSort(arr,0,n,cmp);
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
    insertSort(arr,0,n,cmp);
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
    cout<<cnt_cmp<<" "<<cnt_swap<<endl;
    
}