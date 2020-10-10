#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
using namespace std;
//cost, happiness, avrage happiness
unordered_map<string,int> happy;
unordered_map<string, unordered_map<string,int> > dis;
vector<vector<string>> path;
vector<string> temp_path;
int small;
unordered_map<string,bool> visited;
void dfs(string index,int sum){
	if(index=="ROM"){
		if(sum<=small){
			if(sum<small) path.resize(0);
			small=sum;
			path.push_back(temp_path);
		}
		return;
	}
	for(auto it:dis[index]){
		if(visited[it.first]==false && sum+it.second<=small){
			visited[it.first]=true;
			temp_path.push_back(it.first);
			dfs(it.first,sum+it.second);
			temp_path.pop_back();
			visited[it.first]=false;
		}
	}
}
int main(){
	int city,road,temp;
	string start,end,name1,name2;
	cin>>city>>road>>start;
	happy[start]=0;
	visited[start]=true;
	for(int i=0;i<city-1;i++){
		cin>>name1>>temp;
		happy[name1]=temp;
		visited[name1]=false;
	}
	for(int i=0;i<road;i++){
		cin>>name1>>name2>>temp;
		dis[name1][name2]=temp;
		dis[name2][name1]=temp;
	}
	small=100000;
	temp_path.push_back(start);
	dfs(start,0);
	int size=path.size();
    int max_happy_sum=0;
    int max_happy_ave=0;
    int index;
    for(int i=0;i<path.size();i++){
        int happy_sum=0;
        for(int j=0;j<path[i].size();j++){
            happy_sum+=happy[path[i][j]];
        }
        int happy_ave=happy_sum/(path[i].size()-1);
        if((happy_sum>max_happy_sum) || (happy_sum==max_happy_sum && happy_ave>max_happy_ave)){     
            index=i;
			max_happy_sum=happy_sum;
			max_happy_ave=happy_ave;
        }
    }
	cout<<path.size()<<" "<<small<<" "<<max_happy_sum<<" "<<max_happy_ave<<endl;
	for(int i=0;i<path[index].size();i++){
		if(i) cout<<"->"<<path[index][i];
		else cout<<path[index][i];
	}
	return 0;
}
