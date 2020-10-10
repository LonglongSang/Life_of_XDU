#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
using namespace std;
bool is_o(int n);
int main(){
	int n,k;
	cin>>n>>k;
	string num;
	cin>>num;
	if(k>n){
		cout<<"404"<<endl;
		return 0;
	}
	int sum=0;
	vector<char> temp;
	for(int i=0;i<n-k+1;i++){
		for(int j=i;j<i+k;j++){
			temp.push_back(num[j]);
			sum=sum*10+num[j]-'0';
		}
		if(is_o(sum)){
			for(int i=0;i<temp.size();i++){
				cout<<temp[i];
			}
			return 0;
		}
		temp.resize(0);
		sum=0;
	}
	cout<<"404"<<endl;
	return 0;
}
bool is_o(int n){
	if(n<=1) return false;
	for(int i=2;i<=(int)sqrt(n);i++){
		if(n%i==0) return false;
	}
	return true;
}
