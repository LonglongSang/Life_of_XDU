#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
int main(){
	//printf("YES\nNO\nNO\nNO\nYES\nNO\n");
	//return 0;
	int vertex,num,count=0,a,b,k;
	scanf("%d %d\n",&vertex,&num);
	set<pair<int,int>> edge;
	for(int i=0;i<num;i++){
		scanf("%d %d\n",&a,&b);
		edge.insert({min(a,b),max(a,b)});
	}
	scanf("%d\n",&num);
	int temp[vertex+1];
	for(int i=0;i<num;i++){
		scanf("%d",&k);
		bool good=true;
		int y[k];
		for(int j=0;j<k;j++){
			scanf(" %d",&a);
			y[j]=a;
		}
		scanf("\n");
		if(y[0]!=y[k-1] || k!=vertex+1 || k<3) good=false;
		if(good){
			set<pair<int,int>> check;
			for(int j=0;j<k-1;j++) check.insert({min(y[j],y[j+1]),max(y[j],y[j+1])});
			if(check.size()!=k-1) good=false;
			if(good){
				for(auto it:check){
					if(edge.find(it)==edge.end()){
						good=false;
						break;
					}
				}
			}
			if(good){
				fill(temp+1,temp+vertex+1,0);
				for(int j=0;j<k-1;j++) temp[y[j]]++;
				for(int j=1;j<vertex+1;j++){
					if(temp[j]==0){
						good=false;
						break;
					}
				}
			}
		}
		if(good) printf("YES\n");
		else printf("NO\n");
		
	}
	return 0;
}
