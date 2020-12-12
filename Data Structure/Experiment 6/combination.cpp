/*
    1、选择排序
    2、直接插入排序
    3、冒泡排序
    4、快速排序
*/

#include <stdio.h>
#include <stdlib.h>

template <typename T>
void selectSort(T* arr,int lower,int upper,bool(*cmp)(T&,T&)){
    //选择排序
    //对[arr+lower,arr+upper)范围进行排序
    int v;
    for(int i=upper-1;i>=lower;i--){
        v=i;
        for(int j=lower;j<i;j++){
            if(cmp(arr[v],arr[j])) v=j;
        }
        std::swap(arr[i],arr[v]);
    }
}

template <typename T>
void insertSort(T* arr,int lower,int upper,bool(*cmp)(T&,T&)){
    //直接插入排序
    //对[arr+lower,arr+upper)范围进行排序
    int low,high,mid,tar;
    T temp;
    for(int i=lower+1;i<upper;i++){
        low=lower,high=i-1,tar=i,temp=arr[i];
        while(high>=low){
            //二分查找查找插入位置
            mid=low+(high-low)/2;
            if(cmp(arr[i],arr[mid])){
                tar=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        for(int j=i-1;j>=tar;j--) arr[j+1]=arr[j];
        arr[tar]=temp;
    }
}

template <typename T>
void bubbleSort(T* arr,int lower,int upper,bool(*cmp)(T&,T&)){
    //冒泡排序
    //对[arr+lower,arr+upper)范围进行排序
    bool flag=true;
    /*
        标识是否已经有序
        如果有序提前退出
    */
    for(int i=upper-1;i>1 && flag;i--){
        flag=false;
        for(int j=0;j<i;j++){
            if(cmp(arr[j+1],arr[j])) std::swap(arr[j+1],arr[j]),flag=true;
        }
    }
}


template <typename T>
void quickSort(T* arr,int lower,int upper,bool(*cmp)(T&,T&)){
    //快速排序
    //排序范围[arr+lower,arr+upper)
    //以arr[lower]作为pivot
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