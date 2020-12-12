/*
    5、归并排序
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100005
using T=int;
T arr[N],temp[N];
void mergeSort(T* arr,int lower,int upper,bool (*cmp)(T&,T&b)){
    //归并排序
    //排序范围[arr+lower,arr+upper)
    if(1+lower>=upper) return;
    int mid=lower+(upper-lower)/2;
    mergeSort(arr,lower,mid,cmp);
    mergeSort(arr,mid,upper,cmp);
    int i=lower,j=mid,k=lower;
    while(i<mid && j<upper){
        if(cmp(arr[i],arr[j])) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while(i<mid) temp[k++]=arr[i++];
    while(j<upper) temp[k++]=arr[j++];
    memcpy(arr+lower,temp+lower,sizeof(T)*(upper-lower));
}

int main(){

}