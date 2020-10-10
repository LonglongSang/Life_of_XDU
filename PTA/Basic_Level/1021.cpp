#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
bool is_o(int n);
int main(){
	string in;
	cin>>in;
	vector<int> count(10,0);
	for(int i=0;i<in.length();i++) count[in[i]-'0']++;
	for(int i=0;i<10;i++){
		if(count[i]!=0) cout<<i<<":"<<count[i]<<endl;
	}
	return 0;
}
