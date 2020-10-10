#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
set<string> alumi;
void dfs(int index,int count,vector<vector<int>> &bang,vector<vector<int>> &dp,vector<bool> &visited,vector<int> &suspect){
	visited[suspect[index]]=true;
	//cout<<"vis "<<suspect[index]<<endl;
	bang[count].push_back(suspect[index]);
	for(int i=0;i<suspect.size();i++){
		if(!visited[suspect[i]] && dp[suspect[index]][suspect[i]]!=0 && dp[suspect[i]][suspect[index]]!=0) dfs(i,count,bang,dp,visited,suspect);
	}
}
int main(){
	int K,N,M;
	scanf("%d %d %d\n",&K,&N,&M);
	vector<vector<int>> dp(N+1,vector<int>(N+1,0));
	int call,rece,time;
	for(int i=0;i<M;i++){
		scanf("%d %d %d\n",&call,&rece,&time);
		dp[call][rece]+=time;
	}
	vector<bool> visited(N+1,false);
	vector<int> suspect;
	for(int i=1;i<N+1;i++){
		int count=0;
		int reback=0;
		for(int j=1;j<N+1;j++){
			if(dp[i][j]==0) continue;
			if(dp[i][j]<=5){
				count++;
				if(dp[j][i]!=0) reback++;
			}
		}
		float a=(float)reback/count;
		if(count>K && a<=0.2) suspect.push_back(i);
	}
	//for(int i=0;i<suspect.size();i++) cout<<suspect[i]<<endl;
	if(suspect.size()==0){
		cout<<"None"<<endl;
		return 0;
	}
	vector<vector<int>> bang(1000);
	int count=0;
	for(int i=0;i<suspect.size();i++){
		if(visited[suspect[i]]) continue;
		dfs(i,count,bang,dp,visited,suspect);
		count++;
	}
	for(int i=0;i<count;i++) sort(bang[i].begin(),bang[i].end());
	sort(bang.begin(),bang.begin()+count,[](vector<int> &a,vector<int> &b){
		return a[0]<b[0];
	});
	for(int i=0;i<count;i++){
		for(int j=0;j<bang[i].size();j++){
			if(j) printf(" %d",bang[i][j]);
			else printf("%d",bang[i][j]);
		}
		printf("\n");
	}
	return 0;
}


