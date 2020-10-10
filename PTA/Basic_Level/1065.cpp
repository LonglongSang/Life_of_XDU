#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;
string helll(int a){
	ostringstream h;
	string ret;
	h<<setfill('0')<<setw(5)<<a;
	ret=h.str();
	return ret;
}
int main(){
	int max=100000;
	int unbelieve=92838;
	vector<int> couple(max,unbelieve);
	int a,b,n;
	cin>>n;
	while(n!=0){
		cin>>a>>b;
		couple[a]=b;
		couple[b]=a;
		n--;
	}
	set<string> single;
	cin>>n;
	vector<char> check(max,'0');
	while(n!=0){
		cin>>a;
		check[a]='1';//待检查
		n--;
	}
	string name;
	for(int i=0;i<check.size();i++){
		if(check[i]=='1'){
			if(check[couple[i]]=='1'){
				check[couple[i]]='0';
			}else{
				name=helll(i);
				single.insert(name);
			}
		}
	}
	cout<<single.size()<<endl;
	set<string>::iterator up;
	int count=0;
	for(up=single.begin();up!=single.end();up++){
		if(count){
			cout<<" "<<*up;
		}else{
			cout<<*up;
		}
		count++;
	}
	return 0;
}

