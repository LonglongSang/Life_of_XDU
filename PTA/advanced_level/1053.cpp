#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
	int val;
	vector<node*> children;
};
void dfs(node* root,int sum,vector<vector<int>> &ret,vector<int> &temp,int &target){
	sum+=root->val;
	temp.push_back(root->val);
	if(root->children.size()==0){
        if(sum==target) ret.push_back(temp);
    }else{
        for(int i=0;i<root->children.size();i++) dfs(root->children[i],sum,ret,temp,target);
    }
	temp.pop_back();
}
bool cmp(vector<int> &a,vector<int> &b){return a>b;}
int main(){
	int total,father,target,id,num,son;
	cin>>total>>father>>target;
	vector<node*> address(total);
	vector<int> indegree(total,0);
	for(int i=0;i<total;i++){
		address[i]=new node();
		cin>>address[i]->val;
	}
	for(int i=0;i<father;i++){
		cin>>id>>num;
		for(int j=0;j<num;j++){
			cin>>son;
			indegree[son]++;
			address[id]->children.push_back(address[son]);
		}
	}
	node* root;
	for(int i=0;i<total;i++){
		if(indegree[i]==0){
			root=address[i];
			break;
		}
	}
	vector<vector<int>> ret;
	vector<int> temp;
	dfs(root,0,ret,temp,target);
	sort(ret.begin(),ret.end(),cmp);
	for(int i=0;i<ret.size();i++){
		for(int j=0;j<ret[i].size();j++){
			if(j) cout<<" "<<ret[i][j];
			else cout<<ret[i][j];
		}
		cout<<endl;
	}
	return 0;
}
