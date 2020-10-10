#include <iostream>
#include <vector>
using namespace std;
vector<int> rescue_team;
vector<vector<int>> dist;
vector<bool> visited;
int end_city;
void dfs(int index,int &min_dis,int &max_team,int max_team_run,int min_dis_run,int &route_count){
	max_team_run+=rescue_team[index];
	if(index==end_city){
		if(min_dis>min_dis_run){
            route_count=1;
			min_dis=min_dis_run;
			max_team=max_team_run;
		}else if(min_dis==min_dis_run){
            route_count++;
            if(max_team<max_team_run) max_team=max_team_run; 
        }
		return;
	}
	for(int i=0;i<dist[index].size();i++){
		if(dist[index][i]!=-1 && visited[i]==false && index!=i && min_dis_run+dist[index][i]<=min_dis){
            visited[i]=true;
			dfs(i,min_dis,max_team,max_team_run,min_dis_run+dist[index][i],route_count);
            visited[i]=false;
		}
	}
}
int main(){
	int city,road,start,c1,c2,len,min_dis=20000000,max_team=0,route_count=0;
	cin>>city>>road>>start>>end_city;
	dist.resize(city,vector<int>(city,-1));
	rescue_team.resize(city);
	visited.resize(city,false);
    visited[start]=true;
	for(int i=0;i<city;i++) cin>>rescue_team[i];
	for(int i=0;i<road;i++){
		cin>>c1>>c2>>len;
		dist[c2][c1]=len;
		dist[c1][c2]=len;
	}
	dfs(start,min_dis,max_team,0,0,route_count);
	cout<<route_count<<" "<<max_team<<endl;
	return 0;
}
