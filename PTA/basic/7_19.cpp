#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	int n,f;
	cin>>n;
	double com_f;
	int count=0;
	for(int i=0;i<100;i++){
		com_f=(double)(199*i+n)/98;
		f=(int)com_f;
		if(com_f==f && f<100) cout<<i<<"."<<f<<endl,count++;
	}
	if(count==0) cout<<"No Solution"<<endl;
	return 0;
}
2 3.08 -2.04 5.06

(2.0+3.1i) + (-2.0+5.1i) = 8.1i
(2.0+3.1i) - (-2.0+5.1i) = 4.0-2.0i
(2.0+3.1i) * (-2.0+5.1i) = -19.7+3.8i
(2.0+3.1i) / (-2.0+5.1i) = 0.4-0.6i

