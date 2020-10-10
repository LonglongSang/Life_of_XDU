#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void build(vector<pair<int,int>> &dp,int cur,unordered_map<int,pair<int,int>> &add){
	while(cur!=-1){
		dp.push_back({cur,add[cur].first});
		cur=add[cur].second;
	}
}
void output(vector<pair<int,int>> &longer,vector<pair<int,int>> & shorter){
	vector<pair<int,int>> temp(longer.size()+shorter.size());
	int index=shorter.size()-1;
	int count=0;
	int cnt=0;
	for(int i=0;i<longer.size();i++){
		temp[cnt++]=longer[i];
		count++;
		if(count%2==0 && index>=0) temp[cnt++]=shorter[index--];
	}
	for(int i=0;i<temp.size()-1;i++) printf("%0.5d %d %0.5d\n",temp[i].first,temp[i].second,temp[i+1].first); 
	printf("%0.5d %d %d\n",temp[temp.size()-1].first,temp[temp.size()-1].second,-1); 
}
int main(){
	int a1,a2,num,cur,data,next;
	scanf("%d %d %d\n",&a1,&a2,&num);
	unordered_map<int,pair<int,int>> add;
	for(int i=0;i<num;i++){
		scanf("%d %d %d\n",&cur,&data,&next);
		add[cur]={data,next};
	}
	vector<pair<int,int>> a,b;
	build(a,a1,add);
	build(b,a2,add);
	add.clear();
	if(a.size()>b.size()) output(a,b);
	else output(b,a);
	return 0;
}
