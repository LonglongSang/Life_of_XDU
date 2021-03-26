#include <stdio.h>
#include <iostream>
#include <functional>
using namespace std;
int sum(int a,int b){
    return a+b;
}
int getSum(function<int(int,int)> s,int a,int b){
    return s(a,b);
}
int getSum1(int(*s)(int,int),int a,int b){
    return s(a,b);
}
int main(){
    cout<<getSum(sum,10,12)<<endl;
    cout<<getSum1(sum,10,12)<<endl;
}