#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int main(){
	int sep,num;
	scanf("%d %d\n",&sep,&num);
	int max_now;
	int max_best=0;
	int temp;
	for(int i=0;i<sep;i++){
		max_now=0;
		scanf("%d",&temp);
		if(temp>max_now) max_now=temp;
		for(int j=1;j<num;j++){
			scanf(" %d",&temp);
			if(temp>max_now) max_now=temp;
		}
		scanf("\n",&temp);
		if(i) printf(" %d",max_now);
		else printf("%d",max_now);
		if(max_now>max_best) max_best=max_now;
	}
	printf("\n%d\n",max_best);
	return 0;
}
