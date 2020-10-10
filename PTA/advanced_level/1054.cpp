#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;
int main(){
	int line,col,input;
	int temp=-1;
	int count=0;
	scanf("%d %d\n",&line,&col);
	for(int i=0;i<line;i++){
		for(int j=0;j<col;j++){
			scanf("%d",&input);
			if(count==0){
				count=1;
				temp=input;
			}else{
				if(temp==input){
					count++;
				}else{
					count--;
				}
			}
		}
		scanf("\n");
	}
	cout<<temp<<endl;
	return 0;
}


