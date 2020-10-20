#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
//模板类
template <class T>
class mystack{
    private:
        vector<T> arr;
        int stack_size;
    public:
        mystack(){
            stack_size=0;
            arr.reserve(2000);
        }
        bool empty(){
            return stack_size==0; 
        }
        T top(){
            return arr.back();
            //return arr[stack_size-1];
        }
        void push(const T& a){
            stack_size++;
            arr.push_back(a);
        }
        void pop(){
            stack_size--;
            arr.pop_back();
        }
        int size(){
            return stack_size;
        }
        int capacity(){
            return arr.capacity();
        }
        
};
struct node{
    int x,y;
};
int main(){
    mystack<short> S;
    mystack<long long> S1;
    mystack<char> S2;
    mystack<node> S3;
    S.push(1);
    S.push(100);
    S.push(12);
    while(!S.empty()){
        cout<<S.top()<<endl;
        S.pop();
    }
    return 0;
}