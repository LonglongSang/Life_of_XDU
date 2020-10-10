#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	int key;
	cin>>key;
	if(key==0){
		cout<<"a";
		return 0;
	}
	string num="abcdefghij";
	string  sign="nSBQWSBQY";
	int count_out=0;
	int count=0;
	int flag=0;
	char top[100];
	int len=0;
	while(key!=0){
		if(key%10==0){
			if(count==4) top[len++]=sign[count];
			if(count_out!=0 && flag==0){
				flag=1;
				top[len++]=num[0];
				count_out++;
			}
		}else{
			count_out++;
			flag=0;
			if(sign[count]!='n'){
				if(key%10==1 && sign[count]=='S' && key/10==0){
					top[len++]='S';
				}else{
					top[len++]=sign[count];
					top[len++]=num[key%10];
				}
			}else{
				top[len++]=num[key%10];
			}
		}
		key/=10;
		count++;
	}
	for(int i=len-1;i>=0;i--){
		cout<<top[i];
	}
	return 0;
	
}
