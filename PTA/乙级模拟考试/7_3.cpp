#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;
int main(){
	int min,max;
	cin>>min>>max;
	int count=0;
	int sum,sqrt_a,kai;
	for(int i=min;i<=max;i++){
		sum=3*i*i-3*i+1;
		sqrt_a=sqrt(sum);
		if(sqrt_a*sqrt_a==sum){
			int sqrt_n=sqrt(sqrt_a);
			for(int j=0;j<=sqrt_n;j++){
				if(2*j*j+2*j+1==sqrt_a){
					count++;
					cout<<i<<" "<<(j+1)<<endl;
				}
			}
		}
	}
	if(count==0){
		cout<<"No Solution"<<endl;
	}
	return 0;
}