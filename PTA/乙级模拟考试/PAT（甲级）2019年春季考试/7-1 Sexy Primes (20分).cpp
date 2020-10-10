#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
bool is_prime(int num){
	int up=sqrt(num);
	for(int i=2;i<=up;i++){
		if(num%i==0) return false;
	}
	return true;
}
void cal(int num){
	num++;
	cout<<"No"<<endl;
	while(1){
		if(is_prime(num)){
			if(is_prime(num-6)){
				printf("%d\n",num);
				break;
			}else if(is_prime(num+6)){
				printf("%d\n",num);
				break;
			}
		}
		num++;
	}
}
int main(){
	int num;
	scanf("%d\n",&num);
	if(is_prime(num)){
		if(is_prime(num-6)){
			cout<<"Yes"<<endl;
			printf("%d\n",num-6);
		}else if(is_prime(num+6)){
			cout<<"Yes"<<endl;
			printf("%d\n",num-6);
		}else{
			cal(num);
		}
	}else{
		cal(num);
	}
	return 0;
}
