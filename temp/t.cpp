#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};
typedef node* linkList;
//初始化
void initList(linkList &L)
{
	L = (node *)malloc(sizeof(node));
	L->next = NULL;
	//printf("链表初始化成功\n");
	return;
}

//创建一个单链表（头插法）
void createListHead(linkList &L, int n)
{
	linkList p;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		p = (node*)malloc(sizeof(node));
		//scanf("%d",&p->data);
		//p->next = L->next; //L 的后继指针赋给 p 的后继指针
		//L->next = p; //L 的后继指针指向 p，做到头插法
		p->next=L;
		L=p;
	}
	return;
}

void LinkedListPrint(linkList L)
{
	linkList p;
	p=L->next;
	while(p!=NULL)
	{
	printf("%d ",p->data);
	p=p->next;
	}
}

int main() {
	linkList L;
	initList(L);
	createListHead(L, 3);
	LinkedListPrint(L);
	return 0;
}