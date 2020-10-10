#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#define max_t(a,b,c) ((a>b?a:b)>c?(a>b?a:b):c)
using namespace std;
int dp[1001][1001];
int main(){
    int n,m;
    scanf("%d %d\n",&n,&m);
    int a,b,c,d;
    int check[m][4];
	memset(&dp[0][0],0,sizeof(dp));
    for(int i=0;i<m;i++){
		scanf("%d %d %d %d\n",&a,&b,&c,&d);
		for(int k=a;k<=c;k++){
			for(int t=b;t<=d;t++){
				dp[k][t]++;
			}
		}
    }
    int sum=0;
    for(int i=1;i<=n;i++){
		printf("%d",dp[i][1]);
        for(int j=2;j<=n;j++){
			printf(" %d",dp[i][j]);
        }
		printf("\n");
    }
	return 0;
}