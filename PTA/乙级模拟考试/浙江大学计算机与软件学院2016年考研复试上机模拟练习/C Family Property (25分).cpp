#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct infor{
	int small,count;
	double ave_set;
	double ave_area;
};
void dfs(int &small,int &count,int &set,int &area,int index,unordered_map<int,unordered_set<int>> &edge,vector<bool> &visited,unordered_map<int,pair<int,int>> &fortune){
	visited[index]=true;
	if(index<small) small=index;
	count++;
	if(fortune.find(index)!=fortune.end()){
		set+=fortune[index].first;
		area+=fortune[index].second;
	}
	for(auto it:edge[index]){
		if(visited[it]==false) dfs(small,count,set,area,it,edge,visited,fortune);
	}
	
}
//The families must be given in descending order of their average areas, and in ascending order of the ID's if there is a tie.
bool cmp(infor &a,infor &b){
	if(a.ave_area!=b.ave_area) return a.ave_area>b.ave_area;
	else return a.small<b.small;
}
int main(){
	int num,cur,father,mother,k,set,area,son;
	scanf("%d\n",&num);
	unordered_map<int,unordered_set<int>> edge;
	unordered_map<int,pair<int,int>> fortune;
	vector<bool> visited(10000,false);
	for(int i=0;i<num;i++){
		scanf("%d %d %d %d",&cur,&father,&mother,&k);
		if(father==-1 && mother==-1){
			edge[cur];
		}else{
			if(father!=-1){
				edge[father].insert(cur);
				edge[cur].insert(father);
			}
			if(mother!=-1){
				edge[mother].insert(cur);
				edge[cur].insert(mother);
			}
		}
		for(int j=0;j<k;j++){
			scanf(" %d",&son);
			edge[cur].insert(son);
			edge[son].insert(cur);			
		}
		scanf(" %d %d\n",&set,&area);
		fortune[cur].first=set;
		fortune[cur].second=area;
	}
	vector<infor> output;
	for(auto it:edge){
		if(visited[it.first]==true) continue;
		int small=it.first;
		int count=0,set=0,area=0;
		dfs(small,count,set,area,small,edge,visited,fortune);
		output.push_back({small,count,(double)set/count,(double)area/count});
	}
	sort(output.begin(),output.end(),cmp);
	printf("%d\n",output.size());
	for(int i=0;i<output.size();i++){
		printf("%0.4d %d %.3lf %.3lf\n",output[i].small,output[i].count,output[i].ave_set,output[i].ave_area);
	}
	return 0;
}
