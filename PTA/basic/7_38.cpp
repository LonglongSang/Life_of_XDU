#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
void big_add(char *big_value,char *value,int &max,int time);
int main(){
	int key,time;
	cin>>key>>time;
	//cout<<"key is "<<key<<endl;
	//cout<<"time is "<<time<<endl;
	if(time==0){
		cout<<0<<endl;
		return 0;
	}
	char dp[time][time];
	for(int i=0;i<time;i++)
		for(int j=0;j<time;j++)
			dp[i][j]='0';
	dp[0][0]=key+'0';
	int size=time+10;
	char big_value[size];
	for(int i=0;i<size;i++) big_value[i]='0';
	int max=0;
	big_add(big_value,dp[0],max,time);
	for(int i=1;i<time;i++){
		for(int j=i;j>=1;j--) dp[i][j]=dp[i-1][j-1];
		dp[i][0]=dp[0][0];
		//for(int j=0;j<time;j++) cout<<dp[i][j];
		big_add(big_value,dp[i],max,time);
	}
	//cout<<"max is "<<max<<endl;
	for(int i=max-1;i>=0;i--){
		cout<<big_value[i];
	}
	return 0;
}
void big_add(char *big_value,char *value,int &max,int time){
	int up=0;
	int count=0;
	int a=0;
	//while(value[count]!='0') count++;
	//cout<<"###########value is "<<value<<endl;
	while(value[count]!='0' && count<time){
		a=(big_value[count]-'0'+up+value[count]-'0')%10;
		//cout<<"want is "<<a;
		up=(big_value[count]-'0'+up+value[count]-'0')/10;
		//cout<<" up is "<<up<<endl;
		big_value[count]=a+'0';
		count++;
		//cout<<"value count is "<<value[count]<<endl;
	}
	if(up!=0) big_value[count++]=up+'0';
	if(count>max) max=count;
}