#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main(){
	int n;
	cin>>n;
	int count=1;
	long a,b,c;
	while(n!=0){
		cin>>a>>b>>c;
		if(a+b>c){
			cout<<"Case #"<<count<<": true"<<endl;
		}else{
			cout<<"Case #"<<count<<": false"<<endl;
		}
		count++;
		n--;
	}
	return 0;
}