#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	long n;
	cin>>n;
	int count=0;
	while(n!=1){
		if(n%2==0){
			n/=2;
		}else{
			n=(3*n+1)/2;
		}
		count++;
	}
	cout<<count;
	return 0;
}