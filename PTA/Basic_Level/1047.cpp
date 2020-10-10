#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm> //sort
#include <sstream>
using namespace std;
int main(){
	int n;
	vector<int> grade_sum(1001,0);
	int group,num,grade,max=-1,index;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d-%d %d\n",&group,&num,&grade);
		grade_sum[group]+=grade;
	}
	
	for(int i=0;i<1001;i++){
		if(grade_sum[i]>max){
			max=grade_sum[i];
			index=i;
		}
	}
	cout<<index<<" "<<max<<endl;
	return 0;
}



