//实验二、单链表上的排序运算
#include<stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[10000];	//排序辅助数组
struct Node
{
	//链表的结构体定义
	int data;
	Node* next;
};


//一、实验思想：
//将链表中的值存入到数组中，在数组中进行排序
//并重新建立链表


//二、主要函数
void head_insert(Node* root, int val);
//1、头插法实现函数
void traverse(Node* root);
//2、遍历函数，对root所指向的链表进行变量
Node* List_sort(Node* root);
//3、排序函数，具体实现见下方函数说明


int main()
{
	Node* root = (Node*)malloc(sizeof(Node));
	//首先生成带头结点List
    root->next = NULL;
    int time = 20;
	//通过变量time控制初始链表的长度
    while(time)
	{
		//通过头插法进行链表的生成
        head_insert(root, rand()%1000);
        time--;
    }
    traverse(root);			//遍历生成的无序链表
    root = List_sort(root);	//对链表排序
    traverse(root);			//对排序后的升序链表进行遍历
    return 0;
}
void head_insert(Node* root,int val)
{
    Node* temp = root->next;
    root->next = (Node*)malloc(sizeof(Node));
    root->next->data = val;
    root->next->next = temp;
}
void traverse(Node* root)
{
    root = root->next;
    printf("\nTraverse begin:\nindex\tval\n");
    if(!root){
        printf("empty list!\n");
        return;
    }
    int cnt = 0;
    while(root){
        printf("%d\t%d\n", cnt, root->data);
        root = root->next;
        cnt++;
    }
}
Node* List_sort(Node* root)
{
	//第一部分:
	//将链表中的数据存储到arr数组中
    int cnt = 0;
    root = root->next;
    while(root)
	{
        arr[cnt++] = root->data;
        root = root->next;
    }
	//第二部分：
	//利用C++ sort函数对arr进行排序
    sort(arr,arr+cnt,[](const int& a,const int& b){
        return a > b;
    });
	
	//第三部分:
	//对数组中排序好的数据进行单链表的创建
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->next = NULL;
    for(int i = 0; i < cnt; i++)
	{
        head_insert(temp, arr[i]);
    }
	//第四部分:
	//返回有序链表的头结点
    return temp;
}
//实验二、单链表上的排序运算 结束