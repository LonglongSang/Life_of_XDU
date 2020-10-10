#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
bool is_o(int n);
int main(){
	int count=0;
	int low,high;
	cin>>low>>high;
	vector<int> oo;
	int o_count=0;
	for(int i=1;i<=10000000000;i++){
		if(is_o(i)){
			oo.push_back(i);
			o_count++;
		}
		if(o_count==high) break;
	}
	for(int i=low-1;i<=high-1;i++){
		if(count){
			cout<<" "<<oo[i];
		}else{
			cout<<oo[i];
		}
		count++;
		if(count==10){
			cout<<endl;
			count=0;
		}
	}
	return 0;
}
bool is_o(int n){
	if(n==1) return false;
	for(int i=2;i<=(int)sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}