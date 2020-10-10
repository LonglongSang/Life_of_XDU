#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}

/* 你的代码将被嵌在这里 */
	int Length( List L ){
		int count=0;
		while(L!=NULL){
			L=L->Next;
			count++;
		}
		return count;
	}