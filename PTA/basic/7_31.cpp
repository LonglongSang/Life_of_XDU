#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
void reverse(string &s,int low,int high);
int main(){
	string str;
	getline(cin,str);
	int N;
	cin>>N;
	if(str.size()==0 || N%str.size()==0) cout<<str<<endl;
	N=N%str.size();
	reverse(str,0,N-1);
	reverse(str,N,str.size()-1);
	reverse(str,0,str.size()-1);
	cout<<str<<endl;
	return 0;
}
void reverse(string &s,int low,int high){
	while(high>low){
		s[low]+=s[high];
		s[high]=s[low]-s[high];
		s[low]=s[low]-s[high];
		low++;
		high--;
	}
}