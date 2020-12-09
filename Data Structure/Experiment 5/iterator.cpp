#ifndef LINKED_H_
#define LINKED_H_
//---------------------------------------------
//     file:LinkedIterator.h
//     让我的容器具有迭起器, 先来看看迭代器怎么用的, 一般我们这么写:
//     Linked<int> intList1; ...
//     Linked<int>::iterator itr;
//     for(itr = intList1.begin(), itr != intList1.end(), itr++){
//         cout << *itr << endl;
//     }
//     可以发现, 需要的条件:
//     1.Linked<int>::iterator itr  这就是iterator是Linked类的内部类的意思
//     2.begin(),  end() 方法返回iterator
//     3.操作符需要重写的: operator++   operator==  operator!=   operator*脱引用
//        
//--------------------下面是上次练习的代码-------------------------
#include <iostream>
 
using namespace std;
 
template<typename T>
class Linked{
protected:
    struct Node{
    T item;
    Node* next;
    };//每个元素(节点)包含2项:用户指定类型的对象, 指向下一个节点的指针
    Node* head;//头指针
    unsigned long length;//容器元素个数
public:
    // Postcondition(后置条件): 初始化一个空的容器
    Linked()
    {
        head = NULL;
        length = 0;
    } 
    // Postcondition: 返回元素的个数
    unsigned long size() const
    {
        return length;
    } 
    // Postcondition: 在所有元素的前面插入新节点
    void push_front(const T& newItem)
    {   
        Node* newHead = new Node;
        newHead->item = newItem;
        newHead->next = head;
        head = newHead;
        length++;
    }
    // Precondition(前置条件): 容器不是空的
    // Postcondition: 从容器中删除最前面的一个元素
    void pop_front()
    {
    if(NULL != head){
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        length--;
    }
        //这里有一个坑, 如果只有下面2行代码:
        //head = head->next;
        //length--;
        //容器是没问题, 第一个元素丢掉了, 但是丢掉的那个元素, 没有删除, 
        //也不可能再访问的到, 就变野指针了, 存在内存泄露, 所以这里一定要delete掉
    }
    // Postcondition: 这个容器是指定容器的拷贝(
    //  将另一个容器赋值给本容器:Linked<int> intList1; Linked<int> intList2 = intList1;)
    void operator=(const Linked<T>& otherLinked)
    {
        Linked<T> tempLinked;
        Node* tempPtr;
        // 删除容器已有的元素
        while (head != NULL)
            pop_front();
        for (tempPtr = otherLinked.head; tempPtr != NULL; tempPtr = tempPtr -> next)
            tempLinked.push_front (tempPtr -> item);
        for (tempPtr = tempLinked.head; tempPtr != NULL; tempPtr = tempPtr -> next)
            push_front (tempPtr -> item);
    } // 重写操作符 = 
    // Postcondition: 这个容器是指定容器的拷贝
    //  将另一个容器赋值给本容器:Linked<int> intList1; Linked<int> intList2(intList1);
    explicit Linked(const Linked<T>& otherLinked)
    {
        head = NULL;
        length = 0;
        Linked<T> tempLinked;
        Node* tempPtr;
        for (tempPtr = otherLinked.head; tempPtr != NULL; tempPtr = tempPtr->next)
            tempLinked.push_front(tempPtr->item);
        for (tempPtr = tempLinked.head; tempPtr != NULL; tempPtr = tempPtr->next)
            push_front(tempPtr->item);
    } // 拷贝构造函数
     
    // Postcondition: 删除所有元素, 释放占用的空间
    virtual ~Linked()
    {
    cout << "~Linked() called." << endl;
        while (head != NULL)
            pop_front();
    } // 析构函数
public:
    //-------------------------------------------------------------
    //  本次练习添加的代码
    //-------------------------------------------------------------
    class Iterator{
        friend class Linked<T>; //因为在Linked中访问了protected成员
    protected:
        Node* nodePtr;
        Iterator (Node* newPtr)
        {
            nodePtr = newPtr;
        }
    public:
        Iterator()
        {
        }
        bool operator== (const Iterator& itr) const
        {
            return nodePtr == itr.nodePtr;
        } // overloading ==
        bool operator!= (const Iterator& itr) const
        {
            return nodePtr != itr.nodePtr;
        } // overloading !=
        T& operator*() const
        {
            return nodePtr -> item;
        } // overloading *
        Iterator operator++(int)
        {
            Iterator temp = *this;
            nodePtr = nodePtr -> next;
            return temp;
        } // post-increment ++
        Iterator& operator++()
        {
            nodePtr = nodePtr -> next;
            return *this;
        } // pre-increment ++
        bool atEnd()
        {
            return (nodePtr == NULL);
        } 
    };
    //---------------------------------------------
    //  Linked类要添加begin, end方法
    //---------------------------------------------
    Iterator begin()
    {
        return Iterator(head);  //要访问Iterator的protected成员, 要把Linked添加为友元类.
    } 
    Iterator end()
    {
        return Iterator(NULL);  //要访问Iterator的protected成员, 要把Linked添加为友元类.
    } 
};
#endif
 
 
 
 
 
 
//file:main2.cpp
//------------- 测试 ----------------
#include "LinkedIterator.h"
#include <iostream>
#include <numeric>    //accumulate累加算法
 
using namespace std;
 
int main(){
    Linked<int> intList1;
    for(int i=1; i<=100; ++i){
        intList1.push_front(i);
    }
    
    //测试迭代器
    Linked<int>::Iterator itr;
    for(itr = intList1.begin(); itr != intList1.end(); itr++){
        cout << *itr << endl;
    }
 
    //用STL的通用算法试试
    int sum = accumulate(intList1.begin(), intList1.end(),0);
    cout << "sum:" << sum << endl;  //sum:5050
 
    //暂停
    int ch;
    cin >> ch;
    return 0;
}