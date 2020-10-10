using namespace std;
#include <iostream>
int main(){
    double cm;
    cin>>cm;
    double d_foot=cm/100/0.3048;
    int foot,inch;
    foot=(int)d_foot;
    inch=(d_foot-foot)*12;
    cout<<foot<<" "<<inch<<endl;
    return 0;
}