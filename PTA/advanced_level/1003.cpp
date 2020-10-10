#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
using namespace std;
vector<int> rescue_team;
long min_dis,max_team,end_city,min_dis_run,max_team_run,route_count;
vector<vector<int>> dist;
vector<bool> visited;
void dfs(int index){
	max_team_run+=rescue_team[index];
	if(index==end_city){
		if(min_dis>min_dis_run){
            route_count=1;
			//route_count++;
			min_dis=min_dis_run;
			max_team=max_team_run;
		}else if(min_dis==min_dis_run){
            route_count++;
            if(max_team<max_team_run) max_team=max_team_run; 
        }
		return;
	}
	for(int i=0;i<dist[index].size();i++){
		if(dist[index][i]!=-1 && visited[i]==false && index!=i){
            visited[i]=true;
			min_dis_run+=dist[index][i];
			dfs(i);
            visited[i]=false;
			min_dis_run-=dist[index][i];
		}
	}
    max_team_run-=rescue_team[index];
}
int main(){
	int city,road,start,c1,c2,len;
	cin>>city>>road>>start>>end_city;
	dist.resize(city,vector<int>(city,-1));
	rescue_team.resize(city);
	visited.resize(city,false);
    visited[start]=true;
	for(int i=0;i<city;i++){
		cin>>rescue_team[i];
	} 
	for(int i=0;i<road;i++){
		cin>>c1>>c2>>len;
		dist[c2][c1]=len;
		dist[c1][c2]=len;
	}
	min_dis=300000000,max_team=0,min_dis_run=0,max_team_run=0,route_count=0;
	dfs(start);
	cout<<route_count<<" "<<max_team<<endl;
	return 0;
}
