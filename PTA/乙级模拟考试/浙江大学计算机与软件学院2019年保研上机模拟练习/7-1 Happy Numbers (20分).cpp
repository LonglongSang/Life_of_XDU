#include <iostream>
#include <vector>
#include <math.h>
#include <set>
using namespace std;
int get(int target){
	int sum=0;
	while(target!=0){
		sum+=pow(target%10,2);
		target/=10;
	}
	return sum;
}
int main(){
	int num,target;
	scanf("%d\n",&num);
	for(int i=0;i<num;i++){
		scanf("%d\n",&target);
		set<int> dp;
		int step=0;
		int temp;
		dp.insert(target);
		bool go=false;
		while(target!=1){
			target=get(target);
			if(dp.find(target)!=dp.end()){
				printf("%d\n",target);
				go=true;
				break;
			}else{
				dp.insert(target);
			}
			step++;
		}
		if(go) continue;
		printf("%d\n",step);
	}
	return 0;
}
