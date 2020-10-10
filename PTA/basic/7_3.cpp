using namespace std;
#include <iostream>
int main(){
    int a;
    cin>>a;
    int c=0;
    while(a!=0){
        c=(a%10)+c*10;
        a/=10;
    }
    cout<<c<<endl;
    return 0;
}