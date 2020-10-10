#include <stdio.h>
#include <math.h>
int Count_Digit ( const int N, const int D );
int main()
{
    int N, D;
	
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

/* 你的代码将被嵌在这里 */
int Count_Digit ( const int N, const int D ){
	int n=N;
	int d=D;
	int count=0;
	if(N==0 && D==0) return 1;
	while(n!=0){
		if(n%10==d || n%10==-d) count++;
		n/=10;
	}
	return count;
}
