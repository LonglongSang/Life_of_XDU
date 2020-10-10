#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
using namespace std;
int main(){
	string a;
	getline(cin,a);
	int sum=0;
	for(int i=0;i<a.length();i++){
		if(a[i]>='a' && a[i]<='z'){
			sum+=a[i]-'a'+1;
		}else if(a[i]>='A' && a[i]<='Z'){
			sum+=a[i]-'A'+1;
		}
	}
	if(sum==0){
		cout<<"0 0"<<endl;
		return 0;
	}
	int count_1=1;
	int count_0=0;
	while(sum!=1){
		if(sum%2==1){
			count_1++;
		}else{
			count_0++;
		}
		sum/=2;
	}
	cout<<count_0<<" "<<count_1<<endl;
	return 0;
}	
	
