#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//我的命名空间mylib，为了和std::vector区别开
namespace mylib{
    template <class T>
    class vector{
        private:
            T *arr;
            unsigned cap;
            unsigned cnt;
            unsigned add=100;//额外扩充空间
            void expand(){
                //接口不对外
                //双倍扩充
                cap= cap==0?1:cap;
                arr=(T*)realloc(arr,cap*2*sizeof(T));
                cap*=2;
            }
        public:
            //三种构造函数
            vector(unsigned _size){
                cap=_size+add;
                arr=(T*)malloc(sizeof(T)*cap);   
                cnt=_size;             
            }
            vector(unsigned _size,T val){//初始化vector，大小为_size，值初始化为val
                cap=_size+add;
                arr=(T*)malloc(sizeof(T)*cap);   
                cnt=_size;  
                for(int i=0;i<_size;i++) arr[i]=val;   
            }
            vector(){
                cnt=0;
                cap=0;
                arr=NULL;
            }


            T& operator [](unsigned index){
                //重载[],可以使用arr[i]访问
                return arr[index];
            }
            T& at(unsigned index){
                //和arr[i]一样
                return arr[index];
            }
            void resize(int _size){
                cap=_size+add;
                arr=(T*)realloc(arr,cap*sizeof(T));
                cnt=_size;
            }
            void resize(int _size,T val){
                resize(_size);
                for(int i=0;i<cnt;i++) arr[i]=val;
            }

            void push_back(T val){
                if(cnt+1>=cap) expand();
                arr[cnt++]=val;
            }
            void pop_back(){
                cnt -= cnt == 0 ? 0 : 1;
            }
            T& front(){
                //访问第一个元素
                return arr[0];
            }
            T& back(){
                //访问最后一个元素
                return arr[cnt-1];
            }
            unsigned size(){
                //获得大小，实际存储元素的大小
                return cnt; 
            }
            unsigned capacity(){
                //获得实际大小
                return cap;
            }
            void clear(){
                //清除数据
                free(arr);
                cnt=0;
                cap=0;
            }
            ~vector(){
                clear();
            }
    };
} 
struct node{
    int x,y;
};
int main(){
    mylib::vector<int> A(10,0);
    cout<<A.size()<<endl;
    for(int i=0;i<10;i++) A.push_back(i);
    for(int i=0;i<A.size();i++) cout<<A[i]<<endl;

    mylib::vector<node> B(10,{1,0});
    for(int i=1;i<B.size();i++) B[i]={rand()%1000,rand()%1000};
    cout<<B.size();
    for(int i=0;i<B.size();i++) cout<<B[i].x<<" "<<B[i].y<<endl;

}