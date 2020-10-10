#include <iostream>
#include <vector>
using namespace std;
struct node{
	int val;
	node* left;;
    node* right;
};
node* build(vector<int> &temp,int low,int high){//通过先序序列建立二叉树
	if(low==high) return NULL;
	node *ret=new node();
	ret->val=temp[low];
	int index=low+1;
	while(index<high && temp[index]<temp[low]) index++;
	ret->left=build(temp,low+1,index);
	ret->right=build(temp,index,high);
	return ret;
}
int check(node *root,bool &good){
	int left=0,right=0;
	if(root->left) left=check(root->left,good);
	if(root->right) right=check(root->right,good);
	if(abs(left-right)>1) good=false;
	return 1+(left>right?left:right);
}
void input(){
	int num;
	scanf("%d\n",&num);
	vector<int> temp(num);
	scanf("%d\n",&temp[0]);
	for(int i=1;i<num;i++) scanf(" %d\n",&temp[i]);
	node *root=build(temp,0,num);
	bool good=true;
	check(root,good);
	if(good) printf("Yes\n");
	else printf("No\n");
}
int main(){
	int num;
	scanf("%d\n",&num);
	for(int i=0;i<num;i++) input();
	return 0;
}
