#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;
struct infor{
	int id,A,B;
};
//A
int get_index(int &A,int &B,int &L,int &H){
	if(A>=H && B>=H) return 0;
	else if(A>=H && B<H) return 1;
	else if(A<H && B<H && A>=B) return 2;
	else return 3;
}
bool cmp(const infor &a,const infor &b){
	if(a.A+a.B!=b.A+b.B) return a.A+a.B>b.A+b.B;
	else{
		if(a.A!=b.A) return a.A>b.A;
		else return a.id<b.id;
	}
}
int main(){
	int n,L,H,id,A,B,index,count=0;
	scanf("%d %d %d\n",&n,&L,&H);
	vector< vector<infor> > dp(4);
	for(int i=0;i<n;i++){
		scanf("%d %d %d\n",&id,&A,&B);
		if(A>=L && B>=L){
			count++;
			index=get_index(A,B,L,H);
			dp[index].push_back({id,A,B});
		}
	}
	for(int i=0;i<4;i++) sort(dp[i].begin(),dp[i].end(),cmp);
	cout<<count<<endl;
	for(int i=0;i<4;i++){
		for(int j=0;j<dp[i].size();j++){
			printf("%.8d %d %d\n",dp[i][j].id,dp[i][j].A,dp[i][j].B);
		}
	}
	return 0;
}
