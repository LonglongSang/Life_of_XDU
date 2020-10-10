#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct node{
	int key;
	node *left;
	node *right;
	node(int a){
		key=a;
		right=left=NULL;
	}
};
node* build_tree(int &key,node *root){
	if(!root){
		node *ret=new node(key);
		return ret;
	}else{
		if(key<=root->key) root->left=build_tree(key,root->left);
		else root->right=build_tree(key,root->right);
		return root;
	}
}
void visit(int count,vector<int> &level,node* root){
	if(level.size()<count+1) level.resize(count+1);
	level[count]++;
	if(root->left) visit(count+1,level,root->left);
	if(root->right) visit(count+1,level,root->right);
}
int main(){
	int num,temp;
	scanf("%d\n",&num);
	scanf("%d\n",&temp);
	node *root=build_tree(temp,NULL);
	int max=0;
	for(int i=1;i<num;i++){
		scanf(" %d",&temp);
		build_tree(temp,root);
	}
	//return 0;
	vector<int> level;
	visit(0,level,root);
	if(level.size()==1){
		printf("%d + %d = %d\n",level[0],0,level[0]);
	}else{
		printf("%d + %d = %d\n",level[level.size()-1],level[level.size()-2],level[level.size()-1]+level[level.size()-2]);
	}
	return 0;
}
