#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm> //sort
using namespace std;
int main(){
	string a="PATest";
	vector<int> count(6,0);
	string input;
	getline(cin,input);
	int total=0;
	for(int i=0;i<input.length();i++){
		for(int j=0;j<6;j++){
			if(input[i]==a[j]){
				count[j]++;
				total++;
				break;
			}
		}
	}
	while(total!=0){
		for(int i=0;i<6;i++){
			if(count[i]>0){
				cout<<a[i];
				count[i]--;
				total--;
			}
		}
	}
	return 0;
}

