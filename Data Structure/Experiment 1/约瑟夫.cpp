//实验三、约瑟夫问题
#include<stdlib.h>
#include <stdio.h>
using namespace std;
int password[50];
struct Node
{	
	//链表的结构体定义
	int data;
	Node* next;
};


//一、实验思想：
//1、首先创建一个带头结点的环形链表
//2、模拟约瑟夫问题，并在此过程逐渐删除节点
//3、当环形链表只剩下头结点时，退出模拟


//二、主要函数
void head_insert(Node* root,int val);
//1、头插法实现函数
Node* find_last(Node* root);
//2、寻找链表root的最后一个节点并返回其指针
void yuesefu(Node* root, Node* last, int m);
//3、约瑟夫问题模拟函数


int main()
{
    int n = 7;	
	//人数初始化
    int m = 20;	
	//初始化报数
    Node* root = (Node*)malloc(sizeof(Node));
	root->next=NULL;
	//首先生成带头结点List
	root->data=-1;	
	//data=-1表示为头结点
    password[1] = 3, password[2] = 1, password[3] = 7;
	password[4] = 2, password[5] = 4; 
	password[6] = 8, password[7] = 4;
	//初始化密码
    
    for(int i = n; i >= 1; i--){
		//通过头插法进行链表的生成
        head_insert(root, i);
    }
    Node* last = find_last(root);
	//找到最后一个节点
    last->next = root;
	//构建环形链表，使最后一个节点的next指向root
    yuesefu(root, last, m);
	//模拟
    return 0;
}
void head_insert(Node* root,int val)
{
    Node* temp = root->next;
    root->next = (Node*)malloc(sizeof(Node));
    root->next->data = val;
    root->next->next = temp;
}
Node* find_last(Node* root)
{
    Node* last=root;
    root = root->next;
    while(root)
	{
        last = root;
        root = root->next;
    }
    return last;
}
void yuesefu(Node* root, Node* last, int m){
    Node* now = root;
    int cnt = 0;//报数器
    while(root)
	{
        if(root->data == -1)
		{
			//遇到头结点，不算入循环
            if(root == root->next) return;
			//如果只剩下头结点本身，退出该函数
            last = root;
            root = root->next;
            continue;
        }
        cnt++;
        if(cnt == m)
		{
			//报到m的人出圈
            printf("%d out\n", root->data);
            m = password[root->data];//重置m
            cnt = 0;				//重置报数器
            last->next = root->next;
            root = root->next;
        }else
		{
            last = root;
            root = root->next;
        }
    }
}

//实验三、约瑟夫问题 结束