#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
int main(){
	int m,n,a,b,c,temp;
	cin>>m>>n>>a>>b>>c;
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		if(temp>=a && temp<=b) temp=c;
		printf("%.3d",temp);
		for(int j=1;j<n;j++){
			scanf("%d",&temp);
			if(temp>=a && temp<=b) temp=c;
			printf(" %.3d",temp);
		}
		printf("\n");
	}
	return 0;
}



