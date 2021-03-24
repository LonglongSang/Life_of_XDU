#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
using namespace std;

void getSum(int*arr,int l,int r,int& sum){
    sum=0;
    for(int i=l;i<r;i++) sum+=arr[i];
}
int main(int argv,char*argc[]){
    int n=10,sum;
    int* arr=new int[n];
    for(int i=0;i<n;i++) arr[i]=rand()%10;
    for(int i=0;i<n;i++) cout<<"arr"<<"["<<i<<"]="<<arr[i]<<endl;
    thread t=thread(getSum,arr,0,n,ref(sum));
    t.join();
    cout<<"sum is "<<sum<<endl;
    return 0;
}