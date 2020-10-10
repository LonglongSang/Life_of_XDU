#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
using namespace std;
int main(){
	string sold,mine;
	cin>>sold;
	cin>>mine;
	int unbelieve=10000000;
	vector<int> sum(256,unbelieve);
	for(int i=0;i<mine.size();i++){
		if(sum[mine[i]]==unbelieve){
			sum[mine[i]]=1;
		}else{
			sum[mine[i]]++;
		}
	}
	for(int i=0;i<sold.size();i++) if(sum[sold[i]]!=unbelieve) sum[sold[i]]--;
	int count_bad=0;
	int count_good=0;
	int bad=0;
	for(int i=0;i<sum.size();i++){
		if(sum[i]!=unbelieve && sum[i]>0){
				bad=1;
				count_bad+=sum[i];
		}
	}
	if(bad==0){
		int dev=sold.size()-mine.size();
		printf("Yes %d\n",dev);
	}else{
		printf("No %d\n",count_bad);
	}
	return 0;
}
