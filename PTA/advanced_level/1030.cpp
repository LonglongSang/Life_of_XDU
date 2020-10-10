#include <iostream>
#include <string>
#include <vector>
using namespace std;
int des;
int small_dis;
int small_cost;
bool findmy;
vector<bool> visited;
vector< vector< pair<int,int> > > dp;
vector<int> path;
vector<int> temp;
void dfs(int index,int dis,int cost){
	if(index==des){
        if(dis<small_dis || (dis==small_dis && cost<small_cost)){
			path=temp;
			small_dis=dis;
			small_cost=cost;
			findmy=true;
		}
		return;
	}
	for(int i=0;i<dp.size();i++){
		if(dp[index][i].first!=550 && visited[i]==false && (findmy==false || (findmy && dis<small_dis))){
			visited[i]=true;
			temp.push_back(i);
			dfs(i,dis+dp[index][i].first,cost+dp[index][i].second);
			visited[i]=false;
			temp.pop_back();
		}
	}
}
int main(){
	int city,highway,start;
	cin>>city>>highway>>start>>des;
	dp.resize(city,vector< pair<int,int> >(city,{550,550}) );
	visited.resize(city,false);
	int row,col,dis,cost;
	for(int i=0;i<highway;i++){
		cin>>row>>col>>dis>>cost;
		dp[row][col]={dis,cost};
		dp[col][row]={dis,cost};
	}
	small_dis=0x7fffffff;
	small_cost=0x7fffffff;
	findmy=false;
	visited[start]=true;
	dfs(start,0,0);
	for(int i=0;i<path.size();i++) printf(" %d",path[i]);
	int a=path.size();
	printf(" %d %d\n",a+1,small_dis);
	return 0;
}