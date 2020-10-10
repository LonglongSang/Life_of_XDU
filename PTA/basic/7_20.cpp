using namespace std;
#include <iostream>
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<j<<"*"<<i<<"=";
			printf("%-4d",i*j);
		}
		cout<<endl;
	}
    return 0;
}