#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Reverse( List L ){
	List temp=NULL;
	List point=NULL;
	List L1=L;
	while(L1!=NULL){
		temp=point;
		point=L1;
		L1=L1->Next;
		point->Next=temp;
	}
	L1=point;
	return L1;
}
