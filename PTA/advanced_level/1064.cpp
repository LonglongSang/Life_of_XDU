#include <iostream>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
struct node{
	int val;
	node *left;
	node *right;
    node(int a){
        val=a;
        left=NULL;
        right=NULL;
    }
};
void build(int &count,vector<int> &dp,node *root){
	if(root->left) build(count,dp,root->left);
	root->val=dp[count++];
	if(root->right) build(count,dp,root->right);
}
node *visit(int &num){
	queue<node *> Q;
	node *root;
    node *cur;
	root=new node(0);
	Q.push(root);
	int count=0;
	while(!Q.empty()){
		cur=Q.front();
		Q.pop();
		if(count+1<num){
			cur->left=new node(count++);
			Q.push(cur->left);
		}else break;
		if(count+1<num){
			cur->right=new node(count++);
			Q.push(cur->right);
		}else break;
	}
	return root;
}
void got(node *root){
	int count=0;
	queue<node *> Q;
	Q.push(root);
	Q.push(NULL);
	node *cur;
	while(!Q.empty()){
		cur=Q.front();
		Q.pop();
		if(cur==NULL){
			if(Q.empty()) break;
			Q.push(NULL);
			continue;
		}
		if(count) printf(" %d",cur->val);
		else printf("%d",cur->val);
		if(cur->left) Q.push(cur->left);
		if(cur->right) Q.push(cur->right);
		count++;
	}
}
int main(){
	int num;
	scanf("%d\n",&num);
	vector<int> dp(num);
	for(int i=0;i<num;i++) cin>>dp[i];
	sort(dp.begin(),dp.end());
	node *root=visit(num);
    int count=0;
	build(count,dp,root);
	got(root);
	return 0;
}

