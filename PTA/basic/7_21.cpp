#include <iostream>
#include <cstdio>
#include <string>
#include <math.h>
using namespace std;
int main(){
	int target;
	cin>>target;
	int max=sqrt(target/2),a,b;
	int count=0;
	for(int i=1;i<=max;i++){
		a=target-i*i;
		b=sqrt(target-i*i);
		if(a==b*b && a!=0 && b!=0) printf("%d %d\n",i,b),count++;
	}
	if(count==0) cout<<"No Solution"<<endl;
	return 0;
}
