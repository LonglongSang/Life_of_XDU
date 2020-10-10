#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct infor{
	vector<infor*> children;
};
void visit(infor *root,int count,vector<int> &dp,int &max){
	if(count+1>max) max=count+1;
	if(root->children.size()==0){
		dp[count]++;
	}else{
		for(int i=0;i<root->children.size();i++){
			visit(root->children[i],count+1,dp,max);
		}
	}
}
int main(){
	int n,m,father,k,son;
	cin>>n>>m;
	vector<infor*> address(n+1);
	vector< vector<int> > edge(n+1);
	vector<int> indegree(n+1,0);
	for(int i=0;i<m;i++){
		cin>>father>>k;
		for(int j=0;j<k;j++){
			cin>>son;
			indegree[son]++;
			edge[father].push_back(son);
		}
	}
	int ro;
	for(int i=1;i<n+1;i++){
		if(indegree[i]==0){
			ro=i;
			break;
		}
	}
	queue<int> Q;
	int node;
	address[ro]=new infor();
	Q.push(ro);
	while(!Q.empty()){
		node=Q.front();
		Q.pop();
		infor *root=address[node];
		infor *temp;
		for(int i=0;i<edge[node].size();i++){
			temp=new infor();
			address[edge[node][i]]=temp;
			root->children.push_back(temp);
			Q.push(edge[n	ode][i]);
		}
	}
	vector<int> dp(n+1,0);
	int max=0;
	visit(address[ro],0,dp,max);
	for(int i=0;i<max;i++){
		if(i) cout<<" "<<dp[i];
		else cout<<dp[i];
	}
	
	return 0;
}