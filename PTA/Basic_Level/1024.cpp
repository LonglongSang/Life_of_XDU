#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <set>
#include <unordered_map>
using namespace std;
int get_index(string &line,char c,int count){
	int sum=0;
	for(int i=0;i<line.length();i++){
		if(line[i]==c){
			sum++;
			if(sum==count) return i;
		}
	}
	return -1;
}
int main(){
	string line;
	getline(cin,line);
	int 
	return 0;
}
