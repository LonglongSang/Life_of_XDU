#include <iostream>
#include <vector>
#include <stdio.h>
#include <unordered_map>
#include <math.h>
using namespace std;
void pr(vector<pair<int,int>> &arr){
	if(arr.size()==0) return;
    for(int i=0;i<arr.size()-1;i++){
		printf("%0.5d %d %0.5d\n",arr[i].first,arr[i].second,arr[i+1].first);
	}
	printf("%0.5d %d %d\n",arr[arr.size()-1].first,arr[arr.size()-1].second,-1);
}
int main(){
	int first,num,cur,data,next;
	vector<pair<int,int>> add(100001,{0,0});//data,next;
	vector<pair<int,int>> ori,dup;
	vector<int> check(10001,0);
	cin>>first>>num;
	for(int i=0;i<num;i++){
		cin>>cur>>data>>next;
		add[cur]={data,next};
	}
	cur=first;
	while(cur!=-1){
		check[abs(add[cur].first)]++;
		if(check[abs(add[cur].first)]==1) ori.push_back({cur,add[cur].first});
		else dup.push_back({cur,add[cur].first});
		cur=add[cur].second;
	}
	pr(ori);
	pr(dup);
	return 0;
}
