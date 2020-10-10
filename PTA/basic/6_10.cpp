#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
void Print_Factorial ( const int N );

int main()
{
    int N;
	
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

/* 你的代码将被嵌在这里 */
void Print_Factorial ( const int N ){
	if(N<0){
		cout<<"Invalid input";
		return;
	}else if(N==0){
		cout<<0;
		return;
	}
	int time=N,size=N*10,count,up,max=1;
	char p[size],temp;
	for(int i=0;i<size;i++) p[i]='0';
	p[0]='1';
	while(time!=1){
		count=0,up=0;
		while(count<max || up!=0){
			if(count<max){
				temp=((p[count]-'0')*time+up)%10;
				up=((p[count]-'0')*time+up)/10;
				p[count]=temp+'0';
			}else{
				p[count]=up%10+'0';
				up=(up-up%10)/10;
			}
			count++;
		}
		if(count>max) max=count;
		time--;
	}
	for(int i=max-1;i>=0;i--) cout<<p[i];
}