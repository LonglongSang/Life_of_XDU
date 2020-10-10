#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
bool is_prime(int a){
	if(a<2) return false;
    //cout<<sqrt(a)<<endl;
	for(int i=2;i<=(int)sqrt(a);i++) if(a%i==0) return false;
    //cout<<a<<endl;
	return true;
}
int get_num(char* num,int start,int len,int tar){
	int ret=0;
	if(start+tar-1>=len) return -1;
	for(int i=start;i<start+tar;i++){
		ret=ret*10+num[i]-'0';
	}
	return ret;
}
int main(){
	int len,tar,k;
	scanf("%d %d\n",&len,&tar);
	char num[1000];
	scanf("%s",num);
	for(int i=0;i<len;i++){
		if((k=get_num(num,i,len,tar))==-1) break;
		if(is_prime(k)){
			for(int j=i;j<i+tar;j++) printf("%c",num[j]);
            printf("\n");
			return 0;
		}
	}
	printf("404\n");
	return 0;
}
