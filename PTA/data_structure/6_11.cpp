#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
void PreorderPrintLeaves( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Leaf nodes are:");
    PreorderPrintLeaves(BT);
    printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
void t(BinTree BT){
	if(BT->Left==NULL && BT->Right==NULL) printf(" %c",BT->Data);
	if(BT->Left) t(BT->Left);
	if(BT->Right) t(BT->Right);
}
void PreorderPrintLeaves( BinTree BT ){
	printf("Leaf nodes are:");
	if(BT) t(BT);
}
