#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <stdlib.h>
#include <sstream>
#include <unordered_map>
using namespace std;
struct infor{
	string next;
	int data;
};
string begin;
int main(){
	int num,k;
	cin >> begin >> num >> k;
	unordered_map<string, infor> dp;
	string add,next;
	int data;
	for(int i = 0, i < num, i++){
		cin>>add>>data>>next;
		dp[add].next = next;
		dp[add].data = data;
	}
	
	return 0;
}


