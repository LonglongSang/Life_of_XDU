#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct node{
	string str;
	node *left;
	node *right;
	node(){
		left=NULL;
		right=NULL;
	}
};
node* input(int &num,vector<int> &indegree,vector<node*> &add){
	string temp;
	int left,right;
	for(int i=1;i<=num;i++) add[i]=new node();
	for(int i=1;i<=num;i++){
		//scanf("%s %d %d\n",temp.c_str(),&left,&right);
		cin>>temp>>left>>right;
		add[i]->str=temp;
        //strcpy((add[i]->)str,temp);
		if(left!=-1){
			add[i]->left=add[left];
			indegree[left]++;
		}
		if(right!=-1){
			add[i]->right=add[right];
			indegree[right]++;
		}
	}
	for(int i=1;i<=num;i++) if(indegree[i]==0) return add[i];
	return NULL;
}
void trav(node *root){
	printf("(");
	if(!root->left && root->right){
		cout<<root->str;
		if(root->right) trav(root->right);
	}else{
		if(root->left) trav(root->left);
		if(root->right) trav(root->right);
		cout<<root->str;
	}
	
	printf(")");
}
int main(){
	int num;
	scanf("%d\n",&num);
	vector<node*> add(num+1);
	vector<int> indegree(num+1,0);
	node *root=input(num,indegree,add);
	trav(root);
	return 0;
}



