#include <iostream>
#include <vector>
#include <algorithm>
#define min(a,b) (a>b?b:a)
using namespace std;
void pr(vector<int> &temp,int &type,int &line_count,int &count);
int main(){
	int num,width,a;
	scanf("%d %d\n",&num,&width);
	vector<int> dp(10001,0);
	//int count=0;
	scanf("%d",&a);
	dp[a]++;
	for(int i=1;i<num;i++){
		scanf(" %d",&a);
		dp[a]++;
	}
	vector<int> temp(width);
	int count=0;
	int index=1;
	int type=1;
	int line_count=0;
	while(num!=0){
		while(dp[index]!=0){
			dp[index]--;
			temp[count++]=index;
			num--;
			if(count==width){
				pr(temp,type,line_count,count);
			}
		}
		index++;
	}
	if(count!=0) pr(temp,type,line_count,count);
	return 0;
}
void pr(vector<int> &temp,int &type,int &line_count,int &count){
	if(line_count) printf("\n");
	if(type){
		for(int i=0;i<count;i++){
			if(i) printf(" %d",temp[i]);
			else printf("%d",temp[i]);
		}
	}else{
		printf("%d",temp[count-1]);
		for(int i=count-2;i>=0;i--) printf(" %d",temp[i]);
	}
	type^=1;
	count=0;
	line_count++;
}
