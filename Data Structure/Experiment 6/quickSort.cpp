#include <stdio.h>
#include <stdlib.h>

template <typename T>
void quickSort(T* arr,int lower,int upper,bool(*cmp)(T&,T&)){
    //快速排序
    //排序范围[arr+lower,arr+upper)
    if(lower>=upper) return;
    int low=lower,high=upper-1;
    while(high>low){
        while(high>low && !cmp(arr[high],arr[lower])) high--;
        while(high>low && !cmp(arr[lower],arr[low])) low++;
        std::swap(arr[low],arr[high]);
    }
    std::swap(arr[low],arr[lower]);
    quickSort(arr,lower,low,cmp);
    quickSort(arr,low+1,upper,cmp);
}


int main(){

}