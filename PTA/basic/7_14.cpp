using namespace std;
#include <iostream>
int main(){
	int a,b;
	int c=a;
	cin>>a>>b;
	int count=0;
	int sum=0;
	while(a<=b){
		if(count==5){
			count=0;
			cout<<endl;
		}
		count++;
		sum+=a;
		printf("%5d",a++);
	}
	cout<<endl;
	cout<<"Sum = "<<sum<<endl;
    return 0;
}