using namespace std;
#include <iostream>
int main(){
    int a;
    cin>>a;
	if(a<=60){
		cout<<"Speed: "<<a<<" - OK"<<endl;
	}else{
		cout<<"Speed: "<<a<<" - Speeding"<<endl;
	}
    return 0;
}