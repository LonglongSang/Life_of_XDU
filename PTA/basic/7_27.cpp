#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
void pr(int *a,int size);
int main(){
	int num;
	cin>>num;
	int dp[num];
	int count=0,flag=0,target_time;
	cin>>target_time;
	while(count!=num) scanf("%d",&dp[count++]);
	count=1;
	if(num==1){
		pr(dp,num);
		return 0;
	}
	for(int i=0;i<num-1;i++){
		for(int j=0;j<num-i-1;j++){
			if(dp[j]>dp[j+1]){
				flag=1;
				dp[j+1]=dp[j+1]+dp[j];
				dp[j]=dp[j+1]-dp[j];
				dp[j+1]=dp[j+1]-dp[j];
			}
		}
		if(count==target_time || flag==0){
			pr(dp,num);
			return 0;
		}
		count++;
		flag=0;
	}
	return 0;
}
void pr(int *a,int size){
	cout<<a[0];
	for(int i=1;i<size;i++){
		cout<<" "<<a[i];
	}
}

