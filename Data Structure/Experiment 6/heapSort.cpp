/*
    6、堆排序
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define N 100005

template <class T>
class heap{
    private:
        bool (*cmp)(T&,T&);
        //堆排序的比较函数
        int tot,capacity;
        //tot是目前元素个数，capacity是堆排序实际大小
        T* arr;
        bool full(){
            //堆空间是否已满
            return tot==capacity-1;
        }
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
            //清空堆中元素
            tot=0;
        }

        bool push(T val){
            /*
                将val插入到堆中，插入成功返回true
                失败返回false
            */
            if(full()) return false;
            arr[++tot]=val;
            int i=tot;
            while(i!=1 && cmp(arr[i/2],arr[i])){
                std::swap(arr[i/2],arr[i]);
                i/=2;
            }
            return true;
        }
        T& top(){
            //返回堆顶元素
            return arr[1];
        }
        bool empty(){
            //检查堆是否为空
            return tot==0;
        }
        int size(){
            //返回堆大小
            return tot;
        }
        void pop(){
            //删除堆顶元素
            if(empty()) return;
            std::swap(arr[1],arr[tot]);
            tot=max(tot-1,0);
            int i=1;
            while(i*2<=tot){
                i*=2;
                if(i+1<=tot && cmp(arr[i],arr[i+1])) i++;
                if(cmp(arr[i/2],arr[i])) std::swap(arr[i/2],arr[i]);
                else break;
            }
        }
};


bool cmp(int &a,int &b){
    return a<b;
}
void randTest(int n,heap<int>& Q){
    srand(time(0));
    Q.clear();
    printf("insert:\n");
    int v;
    for(int i=0;i<n;i++){
        //建立堆
        v=rand()%INT_MAX;
        printf("%d ",v);
        Q.push(v);
    }
    printf("\n\nheap sorted:\n");
    while(!Q.empty()){
        //弹出元素，堆排序完成
        printf("%d ",Q.top());
        Q.pop();
    }
}
int main(){
    heap<int> Q(10000,cmp);
    //创建一个空间为10000的大顶堆
    randTest(20,Q);
    //测试
}