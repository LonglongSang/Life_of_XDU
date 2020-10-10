#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;
void pr(int max,int now,char a){
	for(int j=0;j<(max-now)/2;j++) cout<<" ";
	for(int j=0;j<now;j++) cout<<a;
	//for(int j=0;j<(max-now)/2;j++) cout<<" ";
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	char a;
	cin>>a;
	n--;
	int count=0;
	while(1){
		if(n-4*(count+1)-2*pow(count+1,2)<0) break;
		count++;
	}
	n=n-4*(count)-2*pow(count,2);
	//count--;
	int dp[count];
	for(int i=0;i<count;i++) dp[i]=3+i*2;
	int max=3+(count-1)*2;
	for(int i=count-1;i>=0;i--)pr(max,dp[i],a);
	pr(max,1,a);
	for(int i=0;i<count;i++) pr(max,dp[i],a);
	cout<<n<<endl;
	return 0;
}
