#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<char> out;
	int count=0;
	while(n!=0){
		if(count==0){
			if(n%10!=0) for(int i=n%10;i>=1;i--) out.push_back(i+'0');
		}else if(count==1){
			for(int i=n%10;i>0;i--) out.push_back('S');
		}else{
			for(int i=n%10;i>0;i--) out.push_back('B');
		}
		n/=10;
		count++;
	}
	for(int i=out.size()-1;i>=0;i--) cout<<out[i];
	return 0;
}