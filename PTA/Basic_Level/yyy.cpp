
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <map>
#include<set>
using namespace std;

int main(){
	set<int> dp;
	dp.insert(10);
	dp.erase(*dp.begin());
	dp.insert(12);
	cout<<*dp.begin()<<endl;
	vector<int> a;
	a={1,2};
	return 0;
}


