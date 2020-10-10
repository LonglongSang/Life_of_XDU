#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int num;
	scanf("%d\n",&num);
	int temp[num];
	scanf("%d",&temp[0]);
	for(int i=1;i<num;i++){
		scanf(" %d",&temp[i]);
	}
	sort(temp,temp+num);
	int sum=0;
	printf("%d ",num%2);
	int low=0,high=num-1;
	while(high>low) sum+=temp[high--]-temp[low++];
	if(high==low) sum+=temp[high];
	printf("%d",sum);
	return 0;
}
