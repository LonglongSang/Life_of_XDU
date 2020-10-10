#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;
int main(){
	int n;
	string temp;
	scanf("%d\n",&n);
	while(n!=0){
		getline(cin,temp);
		for(int i=0;i<temp.size();i++){
			if(temp[i]=='T'){
				printf("%c",temp[i-2]-'A'+1);
				break;
			}
		}
		n--;
	}

	return 0;
}
	
