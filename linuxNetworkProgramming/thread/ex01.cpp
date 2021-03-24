#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <iostream>

void threadFun(){
    std::cout<<"this is a thread"<<std::endl;
    
}

void badTest(){
    std::thread t(threadFun);

    //可能发生意外的代码段
    int a=10,b;
    scanf("%d",&b);
    printf("will runnig %d/%d\n",a,b);
    a/=b;

    t.join();
}

void goodTest(){
    std::thread t(threadFun);
    try{
        //可能发生意外的代码段
        int a=10,b;
        scanf("%d",&b);
        printf("will runnig %d/%d\n",a,b);
        a/=b;
    }catch(...){
        t.join();
        perror("try failed, coming catch\n");
        throw;
    }
    t.join();
}
int main(){
    if(1) badTest();
    else goodTest();
}