#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int n,k,x;
	cin>>n>>k>>x;
	vector<int> sum(n,0);
	vector<int> temp(n);
	int count=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>temp[j];
			if(i%2==0 && count%2==1){
				if(j==0) sum[j]+=x;
				else sum[j]+=temp[j-1];
			}else if(i%2==0 && count%2==0)
				if(j<k) sum[j]+=x;
				else sum[j]+=temp[j-k];				
			else{
				sum[j]+=temp[j];
			}
		}
		if(i%2==0) count++;
	}
	for(int i=0;i<n;i++){
		if(i) cout<<" "<<sum[i];
		else cout<<sum[i];
	}
	return 0;
}