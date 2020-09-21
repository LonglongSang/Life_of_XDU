//实验四、一元多项式相加、减运算器
#include<stdlib.h>
#include <stdio.h>
using namespace std;
struct Node
{
	//多项式链表节点的定义
	float x;		//系数
	int e;			//指数
	Node* next;
};


//一、实验思想：
//1、首先创建两个带头结点的链表分别表示两个多项式a，b
//2、对两个链表进行合并如a±b就将a和b合并到新链表中


//二、主要函数
void insert(Node* root, float x, int e, float typ);
//1、插入函数，将(x,e)表示的一项合并到多项式链表root中
//其中typ=1.0或-1.0，表示是相加或相减
Node* input();
//2、输入函数，通过标准输入构建两个多项式
Node* op(Node* a, Node* b, float typ);
//3、相加相减运算器，如果typ=1.0表示多项式a+b-
//如果typ=-1.0表示多项式a-b
void traverse(Node* root);
//4、遍历函数


int main()
{
    Node* a = input();	//创建a多项式
    traverse(a);		//遍历a多项式
    Node* b = input();	//创建b多项式
    traverse(b);		//遍历b多项式
	Node* add = op(a, b, 1.0);
	//add = a + b，多项式a+b
    traverse(add);		//遍历(a+b)
	Node* sub = op(a, b, -1.0);
	//sub = a - b,多项式(a-b)
	traverse(sub);		//遍历(a-b)
    return 0;
}
void insert(Node* root, float x, int e, float typ)
{
    Node* last=root;
    root = root->next;
    while(root)
	{
        if(root->e == e)
		{
			//如果root中存在指数相同的节点，那么直接相加即可
            root->x += typ * x;
            return;
        }
        last=root;
        root=root->next;
    }
	//root中不存在指数为e的节点，在多项式末尾创建节点即可
    Node* temp=(Node*)malloc(sizeof(Node));
	temp->next = NULL;
    temp->e = e;
    temp->x = x;
    last->next=temp;
}
Node* input()
{
	//创建多项式链表
	//输入格式
	//第一行输入多项式项数n
	//随后n行，每行形如"x e"，表示系数与指数
    Node* a = (Node*)malloc(sizeof(Node));
    a->next = NULL;
    int n, e;
	float x;
    scanf("%d\n", &n);
    for(int i = 0;i < n; i++)
	{
        scanf("%f %d\n", &x, &e);
        insert(a, x, e, 1.0);
    }
    return a;
}
Node* op(Node* a, Node* b, float typ){
	Node* root= (Node*)malloc(sizeof(Node));
	root->next=NULL;
	for(Node* i=a->next; i; i = i->next)
	{
		insert(root, i->x, i->e, 1.0);
	}
	for(Node* i=b->next; i; i = i->next)
	{
		insert(root, i->x, i->e, typ);
	}
	return root;
}
void traverse(Node* root)
{
    root = root->next;
    printf("\nTraverse begin:\ncoefficient\texponent\n");
    if(!root)
	{
        printf("empty list!\n");
        return;
    }
    while(root)
	{
        if(root->x != 0.0)printf("%f\tx**%d\n", root->x, root->e);
        root = root->next;
    }
}
//实验四、一元多项式相加、减运算器 结束