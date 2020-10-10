#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	int a,b;
	char op;
	cin>>a>>op>>b;
	int ret;
	switch(op){
		case '+':
			ret=a+b;
			break;
		case '-':
			ret=a-b;
			break;
		case '*':
			ret=a*b;
			break;
		case '/':
			ret=a/b;
			break;
		case '%':
			ret=a%b;
			break;
		default:
			cout<<"ERROR"<<endl;
			return 0;
			break;
	}
	cout<<ret<<endl;
	return 0;
}