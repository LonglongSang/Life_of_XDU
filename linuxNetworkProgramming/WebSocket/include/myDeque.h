/**
 * Copyright: Open Source
 * Author: Longlong Sang
 * Date: 2021-04-03
 * Email: llsang@foxmail.com
 * Description: 
 * myDeque类是一个类似C++标准模板库中的deque，但是与标准模版括中的queue相比，有以下优点：
 * 1、C++的deque只可以在队尾和队头存入一个元素，但是myDeque可以一次性存放多个元素，以数组指针模式传入你
 * 想要批量存入的数组。内部实现以memcpy实现，相比一个一个存放效率更高
 * 2、C++的deque是访问受限的，仅可以访问头部和尾部的一个元素，myDeque可以访问头部或尾部的数个元素（以数组返回）
 * 3、C++的deque尽可以一次pop_back()和pop_front()一个元素，myDeque提供一次删除多个元素，O(1)时间复杂度完成
 * 4、C++的deque不可以访问除非头部和非尾部的其他元素，myDeque可以访问任意一个元素（但不提供修改功能），这个
 * 功能可以让用户能对队列进行原地检查
 * 5、C++的deque不提供线程访问安全，myDeque专为多线程而生，提供线程安全，可以以阻塞模式或非阻塞模式的访问。
 * 阻塞模式采用条件变量来提醒
 */
#ifndef myDeque_H
#define  myDeque_H
#include <iostream>
#include <string>
#include <mutex>
#include <condition_variable>
#define NON_BLCOK 1
//以非阻塞模式去进行函数调用，如果已上锁，会立刻返回，如果未上锁，会进行上锁，执行操作成功
#define BLOCK 0
//以阻塞模式去进行函数调用，如果已上锁，会阻塞等待知道获取锁，如果未上锁，会等待获取锁
#define FATHER_LOCKED 2
//表示已经获得过锁，可以不进行上锁
template <typename T>
class myDeque
{
    public:
        myDeque();                          //构造函数
        ~myDeque();                         //析构函数
        
        bool push_front(T v,int typ);       //以typ方式头部放入一个元素v
        bool push_front(T* s,int n,int typ);//以typ方式头部放入数组s中的前n个元素
        bool push_front(std::string& s,int typ);//以typ方式将字符串s的元素放入尾部
        
        bool push_back(T v,int typ);        //以typ方式尾部放入一个元素v
        bool push_back(T* s,int n,int typ); //以typ方式尾部放入数组s中的前n个元素
        bool push_back(std::string& s,int typ);//以typ方式将字符串s中的元素放入尾部
        
        

        
        bool back(T& ans,int typ);          //以typ方式返回尾部元素
        bool back(T* ans,int n,int typ);    //以typ方式将尾部的后n个元素存放至ans中

        bool front(T& ans,int typ);         //以typ方式返回头部元素
        bool front(T* ans,int n,int typ);   //以typ方式将头部的前n个元素存放至ans中


        bool pop_back(int typ);             //以typ方式删除尾部的一个元素    
        bool pop_back(T& ans,int typ);      //以typ方式删除1个尾部元素并返回
        bool pop_back(int n,int typ);       //以typ方式删除尾部后n个元素
        bool pop_back(T* ans,int n,int typ);//以typ方式删除尾部n个元素，并放入ans中

        bool pop_front(int typ);            //以typ方式删除头部的一个元素
        bool pop_front(T&ans,int typ);      //以typ方式删除1个头部元素并返回
        bool pop_front(int n,int typ);      //以typ方式删除头部的前n个元素
        bool pop_front(T* ans,int n,int typ);//以typ方式删除头部前n个元素，并放入ans中

        bool getBegin(T* ans,int startPos,int n,int typ);
        bool empty();               //是否为空
        int size();                 //队列中元素个数
        int capacity();             //队列的实际空间
        bool clear(int typ);        //以typ方式将队列清空
        std::mutex& getLock();
        int getRear();              
        int getFront();
        T* getArr();
        int getN();
        T getPos(int i);

        T& operator[](int index);
        void print();
        
    private:
        bool makeLock(std::unique_lock<std::mutex>& lm,int typ);
        T* newMemory(int n);
        void shrink();
        void expand(int n);
        void setZero();
        int cap;        //Number of actual elements in queue
        int head;       //The index of front of queue.
        int rear;       //The next index of rear of queue.
        T* arr;         //The array use in this queue.
        int N;          //Capacity of arr.
        T _temp;        //Temporary varibale.
        std::mutex m;
        std::condition_variable cv;
};

/**
 * Function: myDeque<T>::myDeque()
 * Description: 构造函数
 * Calls: setZero()
 * Input: 无
 * Output: 无
 * Return: 无
 * Other: 无
 */
template <typename T>
myDeque<T>::myDeque()
{
    setZero();
};


/**
 * Function: myDeque<T>::~myDeque()
 * Description: Destructor function, delete the array(memory) allocated before.
 * Calls: 无
 * Input: 无
 * Output: 无
 * Return: 无
 * Other: 无
 */
template <typename T>
myDeque<T>::~myDeque()
{
    if(arr!=nullptr) delete[] arr;
};

/**
 * Function: void myDeque<T>::setZero()
 * Description: Setting class properties's value equal to zero.
 * Calls: None
 * Input: None
 * Output: None
 * Return: None
 * Other: None
 */
template <typename T>
void myDeque<T>::setZero()
{
    N=0;
    head=0;
    cap=0;
    rear=0;
    arr=nullptr;
};

/**
 * Function: T* myDeque<T>::newMemory(int n)
 * Description: new一个类型为T的长度为n的数组，并返回其类型
 * Calls: None
 * Input: 
 *      @n 想要分配的数组长度
 * Output: 无
 * Return: 返回数组的指针
 * Other: 无
 */
template <typename T>
T* myDeque<T>::newMemory(int n)
{
    T* tempArr;
    try{
        tempArr=new T[n];
    }catch(std::bad_alloc& error){
        std::cout<<error.what()<<std::endl;
    }
    return tempArr;
};


/**
 * Function: T myDeque<T>::getPos(int index)
 * Description: 返回arr[index%N]
 * Calls: 无
 * Input: 
 *      @index 你想要访问的数组下标
 * Output: 无
 * Return: arr[index%N]
 * Other: 无
 */
template <typename T>
T myDeque<T>::getPos(int index)
{
    return arr[index%N];
};



/**
 * Function: T myDeque<T>::clear()
 * Description: 清空队列
 * Calls: 无
 * Input: 
 *      @typ:NON_BLCOK 或 BLOCK
 *      如果为NON_BLOCK，检测到有其他线程在访问，就放弃访问，并返回false
 *      如果为BLOCK，则会等待，知道获得队列的所有权
 * Output: 无
 * Return: 执行成功返回true，否则false
 * Other: 无
 */
template <typename T>
bool myDeque<T>::clear(int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ)) return false;
    if(arr!=nullptr) delete[] arr;
    setZero();
    return true;
}


/**
 * Function: bool makeLock(std::unqiue<std::mutex>& lm,int typ)
 * Description: 尝试以typ的方式获取队列的互斥访问权，获得成功返回true
 * Calls: None
 * Input: 
 *      @lm:锁
 *      @typ:操作方式，可以为NON_BLOCK，BLOCK，FATHER_LOCKED
 *          NON_BLOCK表示非阻塞访问，获取失败就立刻结束
 *          BLOCK为阻塞模式，等待知道获得访问权
 *          FATHER_LOCKED，表示已经取得了访问权，可直接返回true
 * Output: 无
 * Return: 执行是否成功，即是否获得了访问权
 * Other: 无
 */
template <typename T>
bool myDeque<T>::makeLock(std::unique_lock<std::mutex>& lm,int typ)
{
    if(typ==FATHER_LOCKED)
    {
        return true;
    }else if(typ==NON_BLCOK)
    {
        lm.try_lock();
        if(!lm.owns_lock()) return false;
        else return true;
    }else
    {
        lm.lock();
        return true;
    }
}

/**
 * Function: void myDeque<T>::expand(int n)
 * Description: 扩展队列的大小，因为队列不足以存放更多元素
 * Calls: None
 * Input: 
 *      @n 想要存放的元素数量
 * Output: 无
 * Return: 无
 * Other: 无
 */
template <typename T>
void myDeque<T>::expand(int n)
{
    if(n==0) return;
    int oriN=N;
    if(N==0) N=1,oriN=0;
    while(N<n) N*=2;//二倍扩容
    
    T* tempArr=newMemory(N);

    int k=std::min(oriN-head,cap);
    if(k) memcpy(tempArr,arr+head,sizeof(T)*k);
    if(cap-k) memcpy(tempArr+k,arr,sizeof(T)*(cap-k));

    this->head=0;
    this->rear=cap;

    if(arr!=nullptr) delete[]arr;
    arr=tempArr;
};



template <typename T>
void myDeque<T>::shrink()
{
    //暂时不考虑收缩问题
    if(N==0 || cap==N) return;
    if(cap==0)
    {

    }else if(N/cap>=2)
    {
        //实际空间是占用空间的两倍
        //可以考虑收缩
    }
};





/**
 * Function: bool myDeque<T>::getBegin(T* ans,int startPos,int n,int typ)
 * Description: 获取队列中，自startPos开始的n个元素，将其存入ans中
 * Calls: None
 * Input: 
 *      @ans:存放结果
 *      @startPos: 起始位置
 *      @n:想要获得的自startPos起始的元素数量
 *      @typ：NON_BLOCK或BLOCK，同之前
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::getBegin(T* ans,int startPos,int n,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ)) return false;

    int k=std::min(n,N-startPos);
    if(k) memcpy(ans,arr+startPos,sizeof(T)*k);
    if(n-k) memcpy(ans+k,arr,sizeof(T)*(n-k));
    return true;
};


/**
 * Function: bool myDeque<T>::push_front(T v,int typ)
 * Description: 将元素V放入队列的队头
 * Calls: None
 * Input: 
 *      @v:需要存放到队尾的元素
 *      @typ:操作方式
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::push_front(T v,int typ)
{
    
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ)) return false;

    if(cap+1>N) expand(1+cap);
    head=(head-1)%N;
    arr[head]=v;
    cap++;
    return true;
};


/**
 * Function: bool myDeque<T>::push_front(T* s,int n,int typ)
 * Description: 将s指向的n个元素以typ方式放入队头
 * Calls: None
 * Input: 
 *      @s:想要放入队头的元素的指针
 *      @n:存放的元素数量
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::push_front(T* s,int n,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ)) return false;

    if(cap+n>N) expand(cap+n);
    int startPos=(head-n+N)%N;
    int k=std::min(n,N-startPos);
    if(k) memcpy(arr+startPos,s,sizeof(T)*k);
    if(n-k) memcpy(arr,s+k,sizeof(T)*(n-k));

    head=(head-n+N)%N;
    cap+=n;
    return true;
};

/**
 * Function: bool myDeque<T>::push_front(std::string& s,int typ)
 * Description: 如果该模板类为char类型，将字符串s放入队头
 * Calls: bool myDeque<T>::push_front(T* s,int n,int typ)
 * Input: 
 *      @s:想要存入队头的字符串
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::push_front(std::string& s,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ)) return false;

    return push_front((char*)s.data(),(int)s.length(),FATHER_LOCKED);
};




/**
 * Function: bool myDeque<T>::push_back(T v,int typ)
 * Description: 将元素v以typ方式放入队尾
 * Calls: None
 * Input: 
 *      @v:想要存入队尾的元素
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::push_back(T v,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ)) return false;

    if(cap+1>N) expand(1+cap);
    arr[rear]=v;
    rear=(rear+1)%N;
    cap++;
    return true;
};

/**
 * Function: bool myDeque<T>::push_back(T* s,int n,int typ)
 * Description: 将s指向地址为起始的前n个元素以typ方式放入队列的尾部
 * Calls: None
 * Input: 
 *      @s:想要存入队列的数组指针
 *      @n:存入的元素数量
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::push_back(T* s,int n,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ)) return false;

    if(cap+n>N) expand(cap+n);
    int k=std::min(N-rear,n);
    if(k) memcpy(arr+rear,s,sizeof(T)*k);
    if(n-k) memcpy(arr,s+k,sizeof(T)*(n-k));
    rear=(rear+n)%N;
    cap+=n;

    return true;
};

/**
 * Function: bool myDeque<T>::push_back(std::string& s,int typ)
 * Description: 将字符串s以typ方式放入队列的尾部
 * Calls: bool myDeque<T>::push_back(T* s,int n,int typ)
 * Input: 
 *      @s:想要存入队列尾部的字符串（当且仅当该模板类被实例化为char类型）
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::push_back(std::string& s,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ)) return false;
    return push_back((char*)s.data(),(int)s.length(),FATHER_LOCKED);
};





/**
 * Function: bool myDeque<T>::back(T& ans,int typ)
 * Description: 将队尾元素以typ方式存入ans中
 * Calls: 无
 * Input: 
 *      @ans:引用，用于存放队尾元素
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::back(T& ans,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ) || cap==0) return false;
    ans=arr[(rear-1+N)%N];
    return true;
};

/**
 * Function: bool myDeque<T>::back(T* ans,int n,int typ)
 * Description: 将队列中队尾的n个元素存入ans指向的数组
 * Calls: bool myDeque<T>::getBegin(T* ans,int startPos,int n,int typ)
 * Input: 
 *      @ans:用于存放队尾n个元素的数组的起始地址
 *      @n:想要返回的队尾的元素数量
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::back(T* ans,int n,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ) || cap<n) return false;
    getBegin(ans,(rear-n+N)%N,n,FATHER_LOCKED);
    return true;
};




/**
 * Function: bool myDeque<T>::front(T& ans,int typ)
 * Description: 将队列的头部元素以typ方式存入ans
 * Calls: 无
 * Input: 
 *      @ans:用于存放头部元素的引用
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::front(T& ans,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ) || cap==0) return false;
    ans=arr[head%N];
    return true;
};

/**
 * Function: bool myDeque<T>::front(T* ans,int n,int typ)
 * Description: 将队列的头部的n个元素存入ans中
 * Calls: 无
 * Input: 
 *      @ans:用于存放队头n个元素的数组的起始地址
 *      @n:需要返回的队头元素数量
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::front(T* ans,int n,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ) || cap<n) return false;
    getBegin(ans,head%N,n,FATHER_LOCKED);
    return true;
};



/**
 * Function: bool myDeque<T>::pop_back(int typ)
 * Description: 以typ方式删除队尾元素
 * Calls: bool myDeque<T>::back(T& ans,int typ)
 * Input: 
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::pop_back(int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ) || cap==0) return false;
    cap--;
    rear=(rear-1+N)%N;
    return true;
};

/**
 * Function: bool myDeque<T>::pop_back(T& ans,int typ)
 * Description: 将队尾元素存入ans中，并删除队尾元素
 * Calls: bool myDeque<T>::back(T& ans,int typ)
 * Input: 
 *      @ans:用于存放队尾元素的引用
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::pop_back(T& ans,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ) || cap==0) return false;
    back(ans,FATHER_LOCKED);
    cap--;
    rear=(rear-1+N)%N;
    return true;
};

/**
 * Function: bool myDeque<T>::pop_back(int n,int typ)
 * Description: 删除队尾的n个元素
 * Calls: 无
 * Input: 
 *      @n:需要删除队尾元素的数量
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::pop_back(int n,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ) || cap<n) return false;
    cap-=n;
    rear=(rear-n+N)%N;
    return true;
};

/**
 * Function: bool myDeque<T>::pop_back(T* ans,int n,int typ)
 * Description: 以typ方式删除队尾的n个元素，并返回这n个元素
 * Calls: 
 *      bool myDeque<T>::back(T* ans,int n,int typ)
 *      bool myDeque<T>::pop_back(int n,int typ)
 * Input: 
 *      @ans:存放删除的n个元素的数组的初始地址
 *      @n:需要删除队尾元素的数量
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::pop_back(T* ans,int n,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ) || cap<n) return false;
    back(ans,n,FATHER_LOCKED);
    pop_back(n,FATHER_LOCKED);
    return true;
};


/**
 * Function: bool myDeque<T>::pop_front(int typ)
 * Description: 以typ方式删除队头元素
 * Calls: 无
 * Input:
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::pop_front(int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ) || cap==0) return false;
    cap--;
    head=(head+1)%N;
    return true;
};

/**
 * Function: bool myDeque<T>::pop_front(T& ans,int typ)
 * Description: 以typ方式删除队尾元素，并存入ans中
 * Calls: 无
 * Input: 
 *      @ans:存放队头元素的引用
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::pop_front(T& ans,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ) || cap==0) return false;
    cap--;
    front(ans,FATHER_LOCKED);
    head=(head+1)%N;
    return true;
};

/**
 * Function: bool myDeque<T>::pop_front(int n,int typ)
 * Description: 以typ方式删除队头的n个元素
 * Calls: 无
 * Input: 
 *      @ans:需要删除队头元素的数量
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::pop_front(int n,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ) || cap<n) return false;
    cap-=n;
    head=(head+n)%N;
    return true;
};

/**
 * Function: bool myDeque<T>::pop_front(T* ans,int n,int typ)
 * Description: 以typ方式删除队头的n个元素，并返回
 * Calls: 
 *      bool myDeque<T>::front(T* ans,int n,int typ)
 *      bool myDeque<T>::pop_front(int n,int typ)
 * Input: 
 *      @ans:存放队头前n个元素的数组的起始地址
 *      @n:需要删除的队头元素的数量
 *      @typ:见之前解释
 * Output: 无
 * Return: 执行是否成功
 * Other: 无
 */
template <typename T>
bool myDeque<T>::pop_front(T* ans,int n,int typ)
{
    std::unique_lock<std::mutex> lm(m,std::defer_lock);
    if(!makeLock(lm,typ) || cap<n) return false;
    front(ans,n,FATHER_LOCKED);
    pop_front(n,FATHER_LOCKED);
    return true;
};




/**
 * Function: bool myDeque<T>::empty()
 * Description: 判断队列是否为空
 * Calls: 无
 * Input: 无
 * Output: 无
 * Return: 队列是否为空
 * Other: 无
 */
template <typename T>
bool myDeque<T>::empty()
{
    return cap==0;
};

/**
 * Function: int myDeque<T>::size()
 * Description: 返回队列大小
 * Calls: 无
 * Input: 无
 * Output: 无
 * Return: 队列元素数量
 * Other: 无
 */
template <typename T>
int myDeque<T>::size()
{
    return cap;
};

/**
 * Function: int myDeque<T>::getRear()
 * Description: 获得队尾元素所在的实际位置的后一个位置 
 * Calls: 无
 * Input: 无
 * Output: 无
 * Return: 队尾元素所在的实际位置的后一个位置
 * Other: 无
 */
template <typename T>
int myDeque<T>::getRear()
{
    return rear;
};

/**
 * Function: int myDeque<T>::getFront()
 * Description: 获得队头元素所在的实际位置
 * Calls: 无
 * Input: 无
 * Output: 无
 * Return: 队头元素实际所在位置
 * Other: 无
 */
template <typename T>
int myDeque<T>::getFront()
{
    return head;
};

/**
 * Function: T* myDeque<T>::getArr()
 * Description: 获得存放队列的数组的指针
 * Calls: 无
 * Input: 无
 * Output: 无
 * Return: 存放队列的数组的指针
 * Other: 无
 */
template <typename T>
T* myDeque<T>::getArr()
{
    return arr;
};

/**
 * Function: int myDeque<T>::getN()
 * Description: 获得存放队列的数组的实际大小
 * Calls: 无
 * Input: 无
 * Output: 无
 * Return: 存放队列的数组的实际大小
 * Other: 无
 */
template <typename T>
int myDeque<T>::getN()
{
    return N;
};

/**
 * Function: int myDeque<T>::print()
 * Description: 从队列头部到尾部一次打印元素
 * Calls: 无
 * Input: 无
 * Output: 无
 * Return: 无
 * Other: 无
 */
template <typename T>
void myDeque<T>::print()
{
    if(cap==0) printf("empty");
    for(int i=0;i<cap;i++)
    {
        if(i) std::cout<<" ";
        std::cout<<getPos(i+head);
    }
    putchar('\n');
};

/**
 * Function: T& myDeque<T>::operator[](int index)
 * Description: 以下标方式访问数组中下标为inddex%N的元素
 * Calls: 无
 * Input: 无
 * Output: 无
 * Return: 数组中下标为inddex%N的元素的引用
 * Other: 无
 */
template <typename T>
T& myDeque<T>::operator[](int index)
{
    return arr[index%N];
};

/**
 * Function: int myDeque<T>::capacity()
 * Description: 获得存放队列的数组的实际大小
 * Calls: 无
 * Input: 无
 * Output: 无
 * Return: 存放队列的数组的实际大小
 * Other: 无
 */
template <typename T>
int myDeque<T>::capacity()
{
    return N;
};

/**
 * Function: std::mutex& myDeque<T>::makeLock()
 * Description: 获取互斥锁，尽管该模板类中提供了默认的互斥访问
 *              但是，有些情况仍可能需要人工去控制互斥访问，所以
 *              你可以通过获得该互斥锁去进行自己编程
 * Calls: 无
 * Input: 无
 * Output: 无
 * Return: 返回控制队列互斥访问的互斥锁
 * Other: 注意，如果你自己获得了本队列的互斥锁，并将它上锁，如果通过
 * NONBLOCK或BLOCK方式去进行一些函数调用，会返回失败，请将typ设为
 * FATHER_LOCKED去访问
 */
template <typename T>
std::mutex& myDeque<T>::getLock()
{
    return m;
}
#endif


