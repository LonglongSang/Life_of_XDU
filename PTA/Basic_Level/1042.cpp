#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;
int main(){
	string input;
	getline(cin,input);
	vector<int> count(26,0);
	for(int i=0;i<input.length();i++){
		if(input[i]-'a'>=0 && input[i]-'a'<=25){
			count[input[i]-'a']++;
		}else if(input[i]-'A'>=0 && input[i]-'A'<=25){
			count[input[i]-'A']++;
		}
	}
	int max=0;
	int index=-1;
	for(int i=0;i<26;i++){
		if(count[i]>max){
			max=count[i];
			index=i;
		}
	}
	printf("%c %d\n",index+'a',max);
	return 0;
}
