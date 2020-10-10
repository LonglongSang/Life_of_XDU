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
	cin>>n;
	getchar();
	string password;
	int flag_num=0,flag_letter=0,flag_bad=0;
	while(n!=0){
		getline(cin,password);
		//cout<<password<<endl;
		if(password.length()<6){
			printf("Your password is tai duan le.\n");
		}else{
			for(int i=0;i<password.length();i++){
				if((password[i]>='a' && password[i]<='z') || (password[i]>='A' && password[i]<='Z')){
					flag_letter++;
				}else if(password[i]>='0' && password[i]<='9'){
					flag_num++;
				}else if(password[i]!='.'){
					flag_bad++;
					printf("Your password is tai luan le.\n");
					break;					
				}
			}
			if(flag_bad==0){
				if(flag_num && flag_letter){
					printf("Your password is wan mei.\n");
				}else if(flag_letter==0){
					printf("Your password needs zi mu.\n");
				}else{
					printf("Your password needs shu zi.\n");
				}
			}
		}
		flag_num=0;
		flag_bad=0;
		flag_letter=0;
		n--;
	}
	return 0;
}