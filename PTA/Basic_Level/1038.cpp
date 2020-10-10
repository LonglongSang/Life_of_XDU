#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm> //sort
using namespace std;
int main(){
	vector<int> sum(101,0);
	int n,temp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		sum[temp]++;
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		if(i){
			cout<<" "<<sum[temp];
		}else{
			cout<<sum[temp];
		}
	}
	return 0;
}

