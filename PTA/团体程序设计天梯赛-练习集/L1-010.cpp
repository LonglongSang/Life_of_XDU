#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const string &a, const string &b){
	if(a.length()!=b.length()) return a.length()<b.length();
	else return a<b;
}
int main(){
	vector<string> a(3);
	for(int i=0;i<3;i++) cin>>a[i];
	sort(a.begin(),a.end(),cmp);
	cout<<a[0]<<"->"<<a[1]<<"->"<<a[2]<<endl;
	return 0;
}