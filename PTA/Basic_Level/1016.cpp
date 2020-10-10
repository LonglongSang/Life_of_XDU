#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
bool is_o(int n);
int main(){
	long long A,B,sum_a=0,sum_b=0;
	int a,b;
	cin>>A>>a>>B>>b;
	while(A!=0){
		if(A%10==a){
			sum_a=sum_a*10+a;
		}
		A/=10;
	}
	while(B!=0){
		if(B%10==b){
			sum_b=sum_b*10+b;
		}
		B/=10;
	}
	long long sum=sum_a+sum_b;
	cout<<sum;
	//printf("%lld\n",sum_a+sum_b);
	return 0;
}
