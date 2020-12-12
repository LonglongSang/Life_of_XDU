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
#define M 20
int temp[N],cmp_cnt,swap_cnt;


template <typename T>
void quickSort(T* arr,int lower,int upper,bool(*cmp)(T&,T&)){
    //快速排序
    //排序范围[arr+lower,arr+upper)
    if(lower>=upper) return;
    int low=lower,high=upper-1;
    while(high>low){
        while(high>low && !cmp(arr[high],arr[lower])) high--,cmp_cnt++;
        while(high>low && !cmp(arr[lower],arr[low])) low++,cmp_cnt++;
        swap(arr[low],arr[high]);
        swap_cnt++;
    }
    swap(arr[low],arr[lower]);
    quickSort(arr,lower,low,cmp);
    quickSort(arr,low+1,upper,cmp);
}





bool cmp(int &a,int &b){
    return a<b;
}
void test(int n){
    srand(time(0));
    int* arr=new int[n];
    for(int i=0;i<n;i++) arr[i]=i;
    quickSort(arr,0,n,cmp);
    //printf("%p ",arr);
    delete []arr;
}
void test1(int n){
    srand(time(0));
    int* arr=new int[n];
    for(int i=0;i<n;i++) arr[i]=rand()%100;
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    cout<<endl;
    quickSort(arr,0,n,cmp);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    cout<<endl;
    //printf("%p ",arr);
    delete []arr;    
}
int main(){
    for(int i=0;i<1;i++){
        //test(10000);
    }
    test1(10);
    cout<<cmp_cnt<<" "<<swap_cnt<<endl;
}