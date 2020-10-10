#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define min(a,b) (a>b?b:a)
struct infor{
	int index,grade;
};
bool cmp1(infor &a,infor &b){
	return a.index<b.index;
}
bool cmp2(infor &a,infor &b){
	if(a.grade!=b.grade) return a.grade>b.grade;
	else return a.index<b.index;
}
struct edge{
	int a,b;
};
int main(){
	int num,relation,A,B,mini;
	scanf("%d %d\n",&num,&relation);

	vector<vector<int>> dp(num+1,vector<int>(100,1));
	
	for(int i=0;i<relation;i++){
		scanf("%d %d\n",&B,&A);
		mini=min(A,B);
		dp[mini][dp[mini][0]++]=A+B-mini;
	}
	while(1){
		scanf("%d",&num);
		if(num==0) break;
		vector<infor> temp(num);
		int count=0;
		for(int i=0;i<num;i++){
			scanf(" %d\n",&A);
			temp[count++].index=A;
		}
		sort(temp.begin(),temp.end(),cmp1);
		for(int i=0;i<num-1;i++){
			for(int j=i+1;j<num;j++){
				for(int c=1;c<dp[temp[i].index][0];c++){
					if(dp[temp[i].index][c]==temp[j].index){
						temp[i].grade++;
						temp[j].grade++;						
						break;
					}
				}
			}
		}
		sort(temp.begin(),temp.end(),cmp2);
		printf("%d",temp[0]);
		printf(" %d",temp[1]);
		printf(" %d\n",temp[2]);
	}
	return 0;
}