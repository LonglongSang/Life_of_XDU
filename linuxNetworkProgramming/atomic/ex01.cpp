#include <atomic>
#include <stdio.h>
#include <iostream>
#include <thread>
#define N 100000000
#define G 10
template <typename T>
void add(T& cnt)
{
    for(int i=0;i<N;i++) cnt++;
};

template <typename T>
void Test()
{
    T cnt;
    cnt=0;
    std::thread arr[G];
    for(int i=0;i<10;i++)
    {
        arr[i]=std::thread(add<T>,std::ref(cnt));
    }
    for(int i=0;i<10;i++)
    {
        arr[i].join();
    }
    std::cout<<"cnt is "<<cnt<<std::endl;
};

int main()
{
    Test<int>();
    Test<std::atomic<int>>();
}