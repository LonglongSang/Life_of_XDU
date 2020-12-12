#include <stdio.h>
#include <stdlib.h>

template <typename T>
void bubbleSort(T* arr,int lower,int upper,bool(*cmp)(T&,T&)){
    bool flag=true;
    for(int i=upper-1;i>1 && flag;i--){
        flag=false;
        for(int j=0;j<i;j++){
            if(cmp(arr[j+1],arr[j])) std::swap(arr[j+1],arr[j]),flag=true;
        }
    }
}

int main(){
}