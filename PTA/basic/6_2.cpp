#include <stdio.h>
#define MAXN 10

double f( int n, double a[], double x );

int main()
{
    int n, i;
    double a[MAXN], x;
	
    scanf("%d %lf", &n, &x);
    for ( i=0; i<=n; i++ )
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}


double f( int n, double a[], double x ){
	double dp[n+1];
	dp[0]=1;
	for(int i=1;i<=n;i++) dp[i]=dp[i-1]*x;
	double sum=a[0];
	for(int i=1;i<=n;i++) sum+=dp[i]*a[i];
	return sum;
}