#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
bool is_o(int n);
int main(){
	int n,a4_count=0,a2_count=0;
	vector<double> a(5,0);
	cin>>n;
	vector<int> dp;
	int temp;
	while(n!=0){
		cin>>temp;
		dp.push_back(temp);
		n--;
	}
	int count=0;
	for(int i=0;i<dp.size();i++){
		if(dp[i]%5==0 && dp[i]%2==0){
			a[0]+=dp[i];
		}else if(dp[i]%5==1){
			a[1]+=(int)pow(-1,count)*dp[i];
			count=count^1;
			a2_count++;
		}else if(dp[i]%5==2){
			a[2]++;
		}else if(dp[i]%5==3){
			a[3]+=dp[i];
			a4_count++;
		}else if(dp[i]%5==4){
			if(dp[i]>a[4]) a[4]=dp[i];
		}
	}
	if(a4_count!=0)a[3]=a[3]/a4_count;
	for(int i=0;i<5;i++){
		if(i) cout<<" ";
		if(a[i]!=0){
			if(i==3){
				printf("%.1lf",a[i]);
			}else{
				cout<<a[i];
			}
		}else{
			if(i==1){
				if(a2_count!=0){
					cout<<a[i];
				}else{
					cout<<"N";
				}
			}else{
				cout<<"N";	
			}
			
		}
	}
	return 0;
}
