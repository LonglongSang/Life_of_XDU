#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct infor{
	int address;
	int next;
	int data;
};
int main(){
	vector<infor> dp(100000);
	int b1,b2,n;
	int add,data,next;
	cin>>b1>>b2>>n;
	for(int i=0;i<n;i++){
		cin>>add>>data>>next;
		dp[add].address=add;
		dp[add].next=next;
		dp[add].data=data;
	}
	vector<infor> A,B;
	while(1){
		A.push_back(dp[b1]);
		b1=dp[b1].next;
		if(b1==-1) break;
	}
	while(1){
		B.push_back(dp[b2]);
		b2=dp[b2].next;
		if(b2==-1) break;
	}
	dp.clear();
	if(A.size()<B.size()){
		A.swap(B);
	}
	//cout<<A.size()<<" "<<B.size()<<endl;
	reverse(B.begin(),B.end());
	vector<infor> D;
	int count=0;
	int j=0;
	for(int i=0;i<A.size();i++){
		D.push_back(A[i]);
		count++;
		if(count!=0 && count%2==0 && j<B.size()) D.push_back(B[j++]);
	}
	for(int i=0;i<D.size()-1;i++){
		printf("%.5d %d %.5d\n",D[i].address,D[i].data,D[i+1].address);
	}
	printf("%.5d %d %d\n",D[D.size()-1].address,D[D.size()-1].data,-1);
	return 0;
}