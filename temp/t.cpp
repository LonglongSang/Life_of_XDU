#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


int n,t,v,a,b,c;
int dp[101][101][101];
bool ok[101];
int main(){
	scanf("%d%d%d",&n,&t,&v);
	//a+c ==t
	//b == v
	int max_num=0,ans=0,dev=1e9+7;
	ok[0]=true;
	for(int x=0;x<n;x++){
		scanf("%d%d%d",&a,&b,&c);
		a+=c;
		if(a>t || b>v) continue;
		dp[a][b][1]=1;
		for(int i=t;i>=a;i--){
			for(int j=v;j>=b;j--){
				
			}
		}
	}
	int index=0;
	for(int i=100;i>=0;i--){
		if(ok[i]){
			index=i;
			break;
		}
	}
	for(int i=0;i<=t;i++){
		for(int j=0;j<=v;j++){
			ans+=dp[i][j][index];
			ans%=dev;
		}
	}
	printf("%d %d\n",index,ans);
	
}
