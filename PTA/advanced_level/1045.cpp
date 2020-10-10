#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main(){
	int color_num,fav_num,temp,chain_num;
	cin>>color_num;
	cin>>fav_num;
	vector<int> fav(color_num+1,-1);
	for(int i=0;i<fav_num;i++){
		cin>>temp;
		fav[temp]=i;
	}
	cin>>chain_num;
	vector<int> chain(chain_num);
	int count=0;
	for(int i=0;i<chain_num;i++){
		cin>>temp;
		if(fav[temp]!=-1){
			chain[count++]=temp;
		}
	}
	chain.resize(count);
	vector<int> max(color_num+1,0);
	int big=0;
	vector<int> dp(count,0);

	for(int i=count-1;i>=0;i--){
		if(max[chain[i]]==0){
			max[chain[i]]=1;
		}else{
			big=0;
			for(int j=1;j<max.size();j++) if(fav[j]>=fav[chain[i]] && max[j]>big) big=max[j];
			if(big+1> max[chain[i]]+1) max[chain[i]]=big+1;
			else max[chain[i]]++;
		}
		
		
		
	}
	for(int i=0;i<max.size();i++){
		cout<<max[i]<<endl;
	}
	return 0;
}
