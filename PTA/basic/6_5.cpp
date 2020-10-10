#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Max( ElementType S[], int N );

int main ()
{
    ElementType S[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &S[i]);
    printf("%.2f\n", Max(S, N));

    return 0;
}
ElementType Max( ElementType S[], int N ){
	float ret=-12111111111111;
	for(int i=0;i<N;i++){
		if(S[i]>ret) ret=S[i];
	}
	return ret;
}

/* 你的代码将被嵌在这里 */