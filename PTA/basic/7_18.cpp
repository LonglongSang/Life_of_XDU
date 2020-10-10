#include <iostream>
#include <cstdio>
#include <string>
#include <math.h>
using namespace std;
double cal(double *a,double key);
int main(){
	double dp[4],low,high,mid,value,low_val,high_val;
	for(int i=0;i<4;i++) cin>>dp[i];
	cin>>low>>high;
	while(1){
		value=(float)((int)(cal(dp,(low+high)/2)*10000+0.5))/10000;
		if(cal(dp,(low+high)/2)==0 || (value==0 && cal(dp,high)*cal(dp,low)<0)){
			printf("%.2f",(low+high)/2);
			return 0;
		}else if(cal(dp,low)==0){
			printf("%.2f",low);
			return 0;
		}else if(cal(dp,high)==0){
			printf("%.2f",high);
			return 0;		
		}else if(value*cal(dp,low)<0){
			high=(low+high)/2;
		}else if(value*cal(dp,high)<0){
			low=(low+high)/2;
		}
	}
	return 0;
}
double cal(double *a,double key){
	double sum=0;
	double dp[4];
	dp[3]=1;
	for(int i=2;i>=0;i--) dp[i]=key*dp[i+1];
	for(int i=3;i>=0;i--) sum+=dp[i]*a[i];
	return sum;
}
