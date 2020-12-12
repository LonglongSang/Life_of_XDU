#include <stdio.h>
#include <stdlib.h>

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

int main(){

}