#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;

int main(){
	int n;
	long long a,b,c,add;
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld\n",&a,&b,&c);
		add=a+b;
		if((res<0 && a>0 && b>0)){
			printf("Case #%d: true\n",i);
		}else{
			printf("Case #%d: false\n",i);
		}
	}
	return 0;
}


