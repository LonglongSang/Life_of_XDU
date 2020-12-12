#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <time.h>
#include <limits.h>
using namespace std;
#define N 10005
int cnt_cmp,cnt_swap;
template <class T>
class heap{
    private:
        bool (*cmp)(T&,T&);
        int tot,capacity;
        T* arr;
    public:
        heap(bool(*cmp)(T&,T&)){
            this->cmp=cmp;
            arr=new T[N];
            tot=0;
            capacity=N;
        }
        heap(int n,bool(*cmp)(T&,T&)){
            this->cmp=cmp;
            arr=new T[n];
            tot=0;
            capacity=n;
        }
        ~heap(){
            delete []arr;
        }
        void clear(){
            tot=0;
        }
        bool full(){
            return tot==capacity-1;
        }
        bool push(T val){
            if(full()) return false;
            arr[++tot]=val;
            int i=tot;
            while(i!=1 && cmp(arr[i/2],arr[i])){
                std::swap(arr[i/2],arr[i]);
                cnt_swap++,cnt_cmp++;
                i/=2;
            }
            return true;
        }
        T& top(){
            return arr[1];
        }
        bool empty(){
            return tot==0;
        }
        int size(){
            return tot;
        }
        void pop(){
            if(empty()) return;
            std::swap(arr[1],arr[tot]);
            tot=max(tot-1,0);
            int i=1;
            while(i*2<=tot){
                i*=2;
                if(i+1<=tot && cmp(arr[i],arr[i+1])) i++,cnt_cmp++;
                if(cmp(arr[i/2],arr[i])) std::swap(arr[i/2],arr[i]),cnt_cmp++,cnt_swap++;
                else break;
            }
        }
};






bool small(int &a,int &b){
    return a<b;
}
bool big(int &a,int &b){
    return a>b;
}

void randTest(int n,heap<int>& Q){
    srand(time(0));
    Q.clear();
    int last=0x7fffffff,v;
    for(int i=0;i<n;i++){
        //Q.push(rand()%INT_MAX);
        v=last-rand()%100;
        last=v;
        Q.push(last);
    }
    while(!Q.empty()){
        Q.pop();
    }
}
void increTest(int n,heap<int>& Q){
    srand(time(0));
    Q.clear();
    int last=0x80000000,v;
    for(int i=0;i<n;i++){
        //Q.push(rand()%INT_MAX);
        v=last+rand()%100;
        last=v;
        Q.push(last);
    }
    while(!Q.empty()){
        Q.pop();
    }
}
void decTest(int n,heap<int>& Q){
    srand(time(0));
    Q.clear();
    int last=0x7fffffff,v;
    for(int i=0;i<n;i++){
        //Q.push(rand()%INT_MAX);
        v=last-rand()%100;
        last=v;
        Q.push(last);
    }
    while(!Q.empty()){
        Q.pop();
    }
}
void testOk(int n,heap<int>& Q){
    srand(time(0));
    Q.clear();
    int v;
    for(int i=0;i<n;i++){
        v=rand()%1000;
        Q.push(v);
        printf("%d ",v);
    }
    putchar('\n');
    putchar('\n');
    while(!Q.empty()){
        printf("%d ",Q.top());
        Q.pop();
        
    }
    putchar('\n');
}
void orderedTest(int n,heap<int>& Q){
    Q.clear();
    for(int i=0;i<n;i++){
        Q.push(i);
    }
    while(!Q.empty()){
        Q.pop();
    }
}
int main(){
    int n=1000005;
    heap<int> Q(n,small);
    for(int i=0;i<1;i++){
        decTest(1000000,Q);
    }
    cout<<cnt_cmp<<" "<<cnt_swap<<endl;
    //testOk(100,Q);
}