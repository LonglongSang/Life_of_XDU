#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm> //sort
#include <sstream>
using namespace std;
string being_s(long a){
	ostringstream h;
	h<<a;
	return h.str();
}
vector<char> big_add(vector<char> &a,vector<char> &b){
	vector<char> ret;
	int up=0;
	int temp;
	for(int i=a.size()-1;i>=0;i--){
		temp=a[i]+b[i]-'0'-'0'+up;
		up=temp/10;
		ret.push_back(temp%10+'0');
	}
	if(up!=0) ret.push_back(up+'0');
	reverse(ret.begin(),ret.end());
	return ret;
}
bool is_palindromic(vector<char> &a){
	bool is=true;
	int low=0,high=a.size()-1;
	while(high>low) if(a[low++]!=a[high--]) return false;
	return true;
}
void pr(vector<char> &a){
	for(int i=0;i<a.size();i++) cout<<a[i];
}
int main(){
	char in;
	vector<char> up;
	while(1){
		in=getchar();
		if(in==10) break;
		up.push_back(in);
	}
	vector<char> down;
	//reverse(down.begin(),down.end());
	//for(int i=0;i<down.size();i++) cout<<down[i];
	bool good=false;
	for(int i=0;i<10;i++){
		down.assign(up.begin(),up.end());
		reverse(down.begin(),down.end());
		if(is_palindromic(up)){
			good=true;
			break;
		}else{
			pr(up);
			
			cout<<" + ";
			pr(down);
			cout<<" = ";
			up=big_add(up,down);
			pr(up);
			cout<<endl;
		}
	}
	if(good){
		pr(up);
		cout<<" is a palindromic number."<<endl;
	}else{
		cout<<"Not found in 10 iterations."<<endl;
	}
	return 0;
}



