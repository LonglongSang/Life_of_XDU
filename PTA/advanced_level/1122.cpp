#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
int vertex;
vector<vector<int>> dp;

int bfs(vector<bool> &visited,vector<int>&indegree){
	queue<pair<int,char>> Q;
	Q.push({1,'l'});
	visited[1]=true;
	pair<int,char> cur;
	int count=2;
	int left=-1,right=-1;
	while(!Q.empty()){
		cur=Q.front();
		Q.pop();
		if(count==2){
			for(auto it:dp[cur.first]){
				if(visited[it]==false){
					visited[it]=true;
					if(count==2){
						Q.push({it,'l'});
						left=it;
					}else{
						Q.push({it,'r'});
						right=it;
					}
					count--;
				}
				if(count==0) break;
			}
			count=1;
		}else{
			for(auto it:dp[cur.first]){
				if(visited[it]==false){
					visited[it]=true;
					Q.push({it,cur.second});
					if(cur.second=='l') left=it;
					else right=it;
				}
			}			
			count=1;
		}
	}
	for(int i=1;i<vertex+1;i++){
		if(visited[i]==false) return 1;
	}
	if(left==-1 && right!=-1){
		left=1;
	}else if(left!=-1 && right==-1){
		right=1;
	}
	for(auto it:dp[left]){
		if(it==right) return 3;
	}
	return 2;
}
int main(){
	int num,a,b,temp;
	scanf("%d %d\n",&vertex,&num);
	dp.resize(vertex+1);
	vector<bool> visited(vertex+1,false);
	vector<int> indegree(vertex+1,0);
	for(int i=0;i<num;i++){
		scanf("%d %d\n",&a,&b);
		dp[a].push_back(b);
		dp[b].push_back(a);
		indegree[a]++;
		indegree[b]++;
	}
	int type=bfs(visited,indegree);
	for(int i=1;i<vertex+1;i++){
		if(i-1) printf(" %d",indegree[i]);
		else printf("%d",indegree[i]);
	}
	printf("\n");
	if(type==1){
		printf("Non-Eulerian\n");
	}else if(type==2){
		printf("Semi-Eulerian\n");
	}else{
		printf("Eulerian\n");
	}
	return 0;
}
