#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	int N;
	cin>>N;
	int dp[N];
	for(int i=0;i<N;i++) dp[i]=1;
	int turn=0;
	int count=1;
	int die=0;
	while(die!=N-1){
		if(dp[turn]==0){
			turn=(turn+1)%N;
			continue;
		}
		if(count%3==0){
			dp[turn]=0;
			die++;
		}
		count++;
		turn=(turn+1)%N;
	}
	for(int i=0;i<N;i++){
		if(dp[i]==1){
			int a=i+1;
			cout<<a<<endl;
			break;
		}
	}
	return 0;
}