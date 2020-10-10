#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
void big_add(char *big_value,int many,int key);
int main(){
	int key,time,max;
	cin>>key>>time;
	cout<<"time is"<<time<<endl;
	if(time==0){
		cout<<0<<endl;
		return 0;
	}
	int size=time+10;
	char big_value[size];
	for(int i=0;i<size;i++) big_value[i]='0';
	for(int i=1;i<=time;i++) big_add(big_value,i,key);
	cout<<"max is "<<max<<endl;
	max=size-1;
	while(big_value[max]=='0') max--;
	for(int i=max;i>=0;i--) cout<<big_value[i];
	return 0;
}
void big_add(char *big_value,int many,int key){
	int up=0,count=0,a=0;
	while(many!=0){
		a=(big_value[count]-'0'+up+key)%10;
		up=(big_value[count]-'0'+up+key)/10;
		big_value[count]=a+'0';
		count++;
		many--;
	}
	if(up!=0) big_value[count]=up+'0';
}