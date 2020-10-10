#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int main(){
	string temp;
	string a="String";
	vector<int> count(6,0);
	
	getline(cin,temp);
	int total=0;
	for(int i=0;i<temp.length();i++){
		for(int j=0;j<6;j++){
			if(temp[i]==a[j]){
				count[j]++;
				total++;
				break;
			}
		}
	}
	while(total!=0){
		for(int i=0;i<6;i++){
			if(count[i]>0){
				printf("%c",a[i]);
				count[i]--;
				total--;
			}
		}
	}
	return 0;
}
