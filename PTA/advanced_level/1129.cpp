#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
vector<pair<int,int>> rec;//index,sales
int k;
bool cmp(pair<int,int> &a,pair<int,int> &b){
	if(a.second!=b.second) return a.second>b.second;
	else return a.first<b.first;
}
void incre(int comm,vector<int> &count){
	bool find=false;
	int mi=0;
	for(int i=0;i<rec.size();i++){
		if(mi>rec[i].second) mi=rec[i].second;
		if(rec[i].first==comm){
			rec[i].second++;
			find=true;
		}
	}
	if(find==false) if(count[comm]>=mi) rec.push_back({comm,count[comm]});
	sort(rec.begin(),rec.end(),cmp);
	rec.resize(k);
}
int main(){
	int num,comm;
	cin>>num>>k;
	vector<int> count(num+1,0);
	rec.resize(k,{0,0});
	for(int i=0;i<num;i++){
		cin>>comm;
		if(rec[0].first!=0){
			printf("%d:",comm);
			for(int j=0;j<rec.size();j++) if(rec[j].first!=0)printf(" %d",rec[j].first);
			printf("\n");
		}
		count[comm]++;
		incre(comm,count);
		
	}
	return 0;
}
