#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
bool is_prime(int a){
	if(a<=1) return false;
	int max=(int)sqrt(a);
	for(int i=2;i<=max;i++) if(a%i==0) return false;
	return true;
}
bool test_main(int n,int radix){
	//cout<<n<<" "<<radix<<endl;
	if(is_prime(n)){
		//cout<<"i am"<<endl;
		vector<int> temp;
		while(n!=0){
			temp.push_back(n%radix);
			n=n/radix;
		}
		int sum=0,size=0,count=0;
		while(size<temp.size() && temp[size]==0) size++;
		for(int i=temp.size()-1;i>=size;i--){
			sum+=temp[i]*pow(radix,count);
			count++;
		}
		//cout<<sum<<endl;
		if(is_prime(sum)){
			return true;
		}else{
			return false;
		}
	}
	return false;
}
int main(){
	int n,radix;
	cin>>n;
	while(n>0){
		cin>>radix;
		if(test_main(n,radix)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
		cin>>n;
	}
	return 0;
}
