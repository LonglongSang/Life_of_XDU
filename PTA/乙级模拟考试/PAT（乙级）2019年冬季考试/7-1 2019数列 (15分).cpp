#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> dp(n);
    dp[0]=2;
    dp[1]=0;
    dp[2]=1;
    dp[3]=9;
    int sum=12;
    for(int i=4;i<n;i++){
        dp[i]=sum%10;
        sum+=-dp[i-4]+dp[i];
    }
    for(int i=0;i<n;i++) printf("%d",dp[i]);
	return 0;
}
