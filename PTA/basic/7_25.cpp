#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
string mp[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"}; 
int main(){
	string str;
	cin>>str;
	if(str[0] == '-') cout<<"fu ", str = str.substr(1);
	for(int i = 0; i < str.size(); i++){
		if(i) cout<<" ";
		cout<<mp[str[i]-'0'];
	}
	
	return 0;
}
 