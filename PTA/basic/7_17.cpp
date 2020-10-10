#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int deep,a[2];
	cin>>deep>>a[0]>>a[1];
	int turn=0;
	int count=0;
	while(deep>0){
		deep-=pow(-1,turn)*a[turn];
		turn=turn^1;
		count++;
	}
	cout<<count<<endl;
	return 0;
}