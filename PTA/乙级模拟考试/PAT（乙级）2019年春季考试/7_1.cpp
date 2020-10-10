#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
void check(vector<int> &factor,int low,int high,int already,int step,int sum,int target,int bool &good){
	for(int i=low;i<=high;i++){
		if(step-already<=high-low+1 && already<step){
			check(factor,i,high,already+1,step,sum+fact		or[i],target,good);
		}
	}
	if(already==step && sum==target) good=true;
}
void input(){
	int temp;
	cin>>temp;
	vector<int> factor;
	for(int i=1;i<=(int)sqrt(temp);i++){
		if(temp%i==0){
			factor.push_back(i);
			factor.push_back(temp/i);
		}
	}
	if(factor.size()<5){
		cout<<"No"<<endl;
	}else{
		sort(factor.begin(),factor.end());
		bool good=false;
		for(int i=4;i<factor.size();i++){
			check(factor,0,i-1,0,4,0,factor[i],good);
			if(good==true) break;
		}
		if(good==true) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) input();
	return 0;
}