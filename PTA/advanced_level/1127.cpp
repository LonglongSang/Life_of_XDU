#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
struct node{
	int val;
	node *left;
	node *right;
	node(int a){
		val=a;
		left=NULL;
		right=NULL;
	}
}
node* build(int low,int high,vector<int> &inorder,vector<int> &postorder){
	if(low==high) return NULL;
	int index;
	for(int i=low;i<high
}
int main(){
	int num;
	scanf("%d\n",&num);
	vector<int> inorder(num);
	vector<int> postorder(num);
	scanf("%d",&inorder[0]);
	for(int i=1;i<num;i++) scanf(" %d",&inorder[i]);
	scanf("\n");
	scanf("%d",&postorder[0]);
	for(int i=1;i<num;i++) scanf(" %d",&postorder[i]);
	return 0;
}
