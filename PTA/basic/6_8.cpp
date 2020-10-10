#include <stdio.h>
int Factorial( const int N );

int main()
{
    int N, NF;
	
    scanf("%d", &N);
    NF = Factorial(N);
    if (NF)  printf("%d! = %d\n", N, NF);
    else printf("Invalid input\n");
    return 0;
}

int Factorial( const int N ){
	int n=N;
	int ret=1;
	if(n<0){
		return ret-1;
	}else if(n==0){
		return ret;
	}else{
		while(n!=0){
			ret*=(n--);
		}
		return ret;
	}
}