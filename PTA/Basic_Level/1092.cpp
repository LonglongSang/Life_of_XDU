#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;
int main(){
	int type,city;
	cin>>type>>city;
	vector<long> sum(type,0);
	long temp;
	for(int i=0;i<city;i++){
		for(int j=0;j<type;j++){
			cin>>temp;
			sum[j]+=temp;
		}
	}
	set<int> dp;
	long max=-1;
	for(int i=0;i<type;i++){
		if(sum[i]>max){
			dp.clear();
			max=sum[i];
			dp.insert(i+1);
		}else if(sum[i]==max){
			dp.insert(i+1);
		}
	}
	cout<<max<<endl;
	int count=0;
	set<int>::iterator up;
	for(up=dp.begin();up!=dp.end();up++){
		if(count){
			cout<<" "<<*up;
		}else{
			cout<<*up;
		}
		count++;
	}
	return 0;
}

