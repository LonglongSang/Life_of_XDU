#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
namespace recursion{
    template <typename T>
    T* binary_search(T* begin,T* end,T tar,bool(*cmp)(const T&,const T&)){
        //递归二分查找
        //功能:对以cmp为排序方式的数组数组下标范围[begin,end)内二分查找tar
        //如果查找到，返回一个T*类型地址，如果未查找到，返回NULL
        if(begin==end) return NULL;
        T* mid=begin+(end-begin)/2;
        if(*mid==tar) return mid;
        else if(cmp(tar,*mid)) return recursion::binary_search(begin,mid,tar,cmp);
        else return recursion::binary_search(mid+1,end,tar,cmp);
    }
};
namespace non_recursion{
    template <typename T>
    T* binary_search(T* begin,T* end,T tar,bool(*cmp)(const T&a,const T&b)){
        //非递归二分查找
        T* mid;
        while(begin<end){
            mid=(end-begin)/2+begin;
            if(*mid==tar) return mid;
            else if(cmp(tar,*mid)) end=mid;
            else begin=mid+1;
        }
        return NULL;
    }
};
bool cmp1(const int&a,const int&b){
    return a<b;
}
bool cmp2(const int& a,const int&b){
    return a>b;
}
#define N 100
int main(){
    int arr[N];
    for(int i=0;i<N;i++) arr[i]=i;
    int target=20;
    int* pos1=recursion::binary_search(arr,arr+N,target,cmp1);
    int* pos2=non_recursion::binary_search(arr,arr+N,target,cmp1);
    printf("%d %d\n",pos1?pos1-arr:-1,pos2?pos2-arr:-1);
}