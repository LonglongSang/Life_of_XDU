#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <thread>
#include <chrono>
#include <iostream>

template <typename T>
class A
{
    public:
        A(){}

        static void staticPri(T &a)
        {
            std::cout<<"class static pri: "<<a<<std::endl;
        }

        void pri(T &a)
        {
            std::cout<<"class non-static pri: "<<a<<std::endl;
        }
};

template <typename T>
void pri(T& a)
{
    std::cout<<"non-class pri: "<<a<<std::endl;
};

void pri1(int &a)
{
    std::cout<<"non-class pri1: "<<a<<std::endl;
}

int main(int argv,char*argc[])
{
    //特别重要的一点类的非静态函数不能被作为回调函数以及function
    int a=10;
    double b=10.2;

    std::thread t1(A<int>::staticPri,std::ref(a));//模版类的静态函数

    A<double> _A;
    std::thread t2(&A<double>::pri,&_A,std::ref(b));//模版类的非静态函数

    std::thread t3(pri<int>,std::ref(a));//模版函数

    std::thread t4(pri1,std::ref(a));//普通函数

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}