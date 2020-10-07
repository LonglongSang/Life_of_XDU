#include <stdio.h>
#include <iostream>
using namespace std;
namespace HELLO{
    int main(){
        cout<<"hello"<<endl;
        return 0;
    }
}
int main(){
    HELLO::main();
	int n;
	scanf("%d\n",&n);
	int arr[n];
	for(int i=0;i<n;i++) scanf("%d",arr+i);
	for(int i=0;i<n;i++) printf("%d#####\n",arr[i]);
    return 0;
}