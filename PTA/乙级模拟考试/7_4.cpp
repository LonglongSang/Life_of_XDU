#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct infor{
	int n;
	int A;
};
void cal(int last,vector<int> &dp,int count,int K,int sum){
	int small=9>sum?sum:9;
	if(count==0){
		small=9>sum?sum:9;
		for(int i=1;i<=small;i++){
			cal(last*10+i,dp,count+1,K,sum-i);
		}
	}else if(count<K-1){
		for(int i=0;i<=small;i++){
			cal(last*10+i,dp,count+1,K,sum-i);		
		}
	}else if(count==K-1){
		for(int i=0;i<=small;i++){
			if(sum-i==0) dp.push_back(last*10+i);
		}
		//if(sum==0) dp.push_back(last*10);
	}
}
int cal_digit(int a){
	int sum=0;
	while(a!=0){
		sum+=a%10;
		a/=10;
	}
	return sum;
}
bool is_prime(int a){
	if(a<3) return false;
	int sqrt_a=sqrt(a);
	for(int i=2;i<=sqrt_a;i++){
		if(a%i==0) return false;
	}
	return true;
}
bool is_big(int m,int n){
	int small=m>n?n:m;
	int big_a;
	for(int i=small;i>=1;i--){
		if(m%i==0 && n%i==0){
			big_a=i;
			break;
		}
	}
	//cout<<
	return is_prime(big_a);
}
int check(int a,int n){
	int m=cal_digit(a+1);
	//cout<<"m is"<<m<<endl;
	if(is_big(m,n)){
		return m;
	}else{
		return -1;
	}
}
bool cmp(const infor &a,const infor &b){
	if(a.n!=b.n) return a.n<b.n;
	else return a.A<b.A;
}
int main(){
	int n,digit,sum,temp,count;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>digit>>sum;
		vector<int> dp;
		cal(0,dp,0,digit,sum);
		printf("Case %d\n",i);
		vector<infor> save;
		for(int i=0;i<dp.size();i++){
			temp=check(dp[i],sum);
			if(temp!=-1){
				save.push_back({temp,dp[i]});
				//cout<<temp<<" "<<dp[i]<<endl;
			}
		}
		if(save.size()==0){
			cout<<"No Solution"<<endl;
		}else{
			sort(save.begin(),save.end(),cmp);
			for(int i=0;i<save.size();i++) 
				printf("%d %d\n",save[i].n,save[i].A);
		}
	}
	//check(120,3);
	return 0;
}