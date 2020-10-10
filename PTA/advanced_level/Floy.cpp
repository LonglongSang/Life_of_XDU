#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;
void pr(vector< vector<int> > &dp){
	for(int i=0;i<dp.size();i++){
		for(int j=0;j<dp.size();j++){
			cout<<" "<<dp[i][j];
		}
		cout<<endl;
	}
}
int main(){
	int n;
	int a,b,distance;
	cin>>n;
	cout<<n<<endl;
	int size=5;
	vector< vector<int> > dp(size);
	int inf=1000000;
	for(int i=0;i<size;i++) dp[i].resize(size,inf);
	for(int i=0;i<size;i++) dp[i][i]=0;
	for(int i=0;i<n;i++){
		cin>>a>>b>>distance;
		dp[a][b]=distance;
		dp[b][a]=distance;
	}
	pr(dp);
	cout<<"############"<<endl;
	for(int i=0;i<size;i++)
		for(int j=0;j<size;j++)
			for(int c=0;c<size;c++)
				if(dp[i][c]>dp[i][j]+dp[c][j] && i!=c) dp[i][c]=dp[i][j]+dp[c][j];
	pr(dp);
	return 0;
}


