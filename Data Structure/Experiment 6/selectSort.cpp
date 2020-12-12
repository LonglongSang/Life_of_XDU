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

int main(){
}