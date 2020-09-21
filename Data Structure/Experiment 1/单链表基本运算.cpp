//实验一、单链表基本运算
#include<stdlib.h>
#include <stdio.h>
using namespace std;
struct Node
{
	//链表的结构体定义
	int data;
	Node* next;
};


//一、实验思想：
//模拟


//二、主要函数
void head_insert(Node* root, int val);
//1、头插法实现函数
void traverse(Node* root);
//2、遍历函数，对root所指向的链表进行变量
void insert_element(Node* root, int index, int val);
//3、插入函数，对root所指向的链表，将值val插入到下标为index的位置
Node* insert_element_help(Node* last, Node* now, int val);
//4、插入函数的辅助函数
void del_element(Node* root, int index);
//5、删除函数，对root所指向的链表，删除下标为index的节点


int main()
{
	Node* root = (Node*)malloc(sizeof(Node));
	//首先生成带头结点List
    root->next = NULL;
    int time = 20;
	//通过变量time控制初始链表的长度
    while(time){
		//通过头插法进行链表的生成
        head_insert(root, rand()%1000);
        time--;
    }
    traverse(root);					//遍历初始链表
    insert_element(root, 2, 100);	//测试1
	insert_element(root, -1, 100);	//测试2
	insert_element(root, 100, 100);	//测试3
	//测试1：向下标为2的节点插入100
	//测试2：边界测试，边界测试，向下标为-1的地方插入
	//测试3，向下标100的地方插入100
	//超过链表长度，会插在链表尾部
	
    del_element(root, 1);		//测试4
	del_element(root, -1);		//测试5
	del_element(root, 100);		//测试6
    traverse(root);				//遍历链表
	//测试4：删除合理下标1
	//测试5：删除不合理下标-1
	//测试6：删除不合理下标100
    return 0;
}
void head_insert(Node* root, int val)
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
    if(!root)
	{
        printf("empty list!\n");
        return;
    }
    int cnt = 0;
    while(root)
	{
        printf("%d\t%d\n", cnt, root->data);
        root = root->next;
        cnt++;
    }
}
Node* insert_element_help(Node* last, Node* now, int val)
{
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data = val;
    last->next = temp;
    temp->next= now;
    return temp;
}
void insert_element(Node* root, int index, int val)
{
	if(index<0)
	{
		 printf("\ninsert to %d failed,out of boundary\n", index);
		 return;
	}
    Node* last = root;
    Node* now = root->next;
    Node* temp;
    int cnt = 0;
    while(now)
	{
        if(cnt == index)
		{
            insert_element_help(last, now, val);
			printf("\ninsert to %d success\n", index);
            return;
        }
        cnt++;
        last = now;
        now = now->next;
    }
    insert_element_help(last, now, val);
	printf("\ninsert to %d success,insert to the last\n", index);
}
void del_element(Node* root, int index)
{
	if(index < 0)
	{
		printf("\ndelete %d failed,out of boundary\n", index);
		return;
	}
    Node* last = root;
    Node* now = root->next;
    int cnt = 0;
    while(now)
	{
        if(cnt == index)
		{
            printf("\ndelete %d success\n", index);
            last->next = now->next;
            free(now);
            return;
        }
        cnt++;
        last = now;
        now = now->next;
    }
    printf("\ndelete %d failed,out of boundary\n", index);
}
//实验一、单链表基本运算   结束