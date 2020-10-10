#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;
int main(){
	int n,sum_n,count_n;
	cin>>n;
	int sum=-1,count=-1;
	string id,sum_id,count_id;
	for(int i=0;i<n;i++){
		cin>>id>>sum_n>>count_n;
		sum_n=sum_n*count_n;
		if(count_n>count){
			count=count_n;
			count_id=id;
		}
		if(sum_n>sum){
			sum=sum_n;
			sum_id=id;
		}
	}
	cout<<count_id<<" "<<count<<endl;
	cout<<sum_id<<" "<<sum<<endl;
	return 0;
}