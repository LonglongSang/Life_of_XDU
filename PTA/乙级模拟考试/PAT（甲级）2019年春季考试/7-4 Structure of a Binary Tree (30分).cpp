#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <sstream>
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
node *pre_order(int leftin, int rightin, int leftpost, int rightpost, vector<int> &in, vector<int> &post) {
        if (leftin > rightin) return NULL;
        node *root = new node(post[rightpost]);
        int rootin = leftin;
        while (rootin <= rightin && in[rootin] != post[rightpost]) rootin++;
        int left = rootin - leftin;
        root->left = pre_order(leftin, rootin - 1, leftpost, leftpost + left - 1, in, post);
        root->right = pre_order(rootin + 1, rightin, leftpost + left, rightpost - 1, in, post);
        return root;
}
int get_int(string &temp){
	int sum=0;
	for(int i=0;i<temp.length();i++){
		sum=sum*10+temp[i]-'0';
	}
	return sum;
}
void are_they_sblings(node* root,int left,int right,bool &good){
	if(root->left && root->right){
		if((root->left->val==left && root->right->val==right) || (root->left->val==right && root->right->val==left)) good=true;
	}
	if(root->left && !good) are_they_sblings(root->left,left,right,good);
	if(root->right && !good) are_they_sblings(root->right,left,right,good);
}
void are_they_left(node* root,int parent,int son,bool &good){
	if(root->val==parent && (root->left && root->left->val==son)) good=true;
	if(root->left && !good) are_they_left(root->left,parent,son,good);
	if(root->right && !good) are_they_left(root->right,parent,son,good);	
}
void are_they_right(node* root,int parent,int son,bool &good){
	if(root->val==parent && (root->right && root->right->val==son)) good=true;
	if(root->left && !good) are_they_right(root->left,parent,son,good);
	if(root->right && !good) are_they_right(root->right,parent,son,good);	
}
void are_they_fs(node* root,int parent,int son,bool &good){
	if(root->val==parent && ((root->left && root->left->val==son) || (root->right && root->right->val==son))) good=true;
	if(root->left && !good) are_they_fs(root->left,parent,son,good);
	if(root->right && !good) are_they_fs(root->right,parent,son,good);	
}
void get_level(int index,node* root,int num1,int num2,int &count1,int &count2){
	if(root->val==num1) count1=index;
	if(root->val==num2) count2=index;
	if(root->left && (count1==-1 || count2==-1) ) get_level(index+1,root->left,num1,num2,count1,count2);
	if(root->right && (count1==-1 || count2==-1) ) get_level(index+1,root->right,num1,num2,count1,count2);
}
void is_it_a_full(node *root,bool &good){
	if(root->left && root->right){
		is_it_a_full(root->left,good);
		is_it_a_full(root->right,good);
	}else if(!root->left && !root->right){
		
	}else{
		good=false;
	}
}
int main(){
	int num;
	cin>>num;
	vector<int> postorder(num);
	vector<int> inorder(num);
	for(int i=0;i<num;i++) cin>>postorder[i];
	for(int i=0;i<num;i++) cin>>inorder[i];
	
	node *root=pre_order(0,inorder.size()-1,0,inorder.size()-1,inorder,postorder);
	cin>>num;
	scanf("\n");
	for(int i=0;i<num;i++){
//		getline(cin,line);
		vector<string> line;
		string temp;
		string pp;
		getline(cin,pp);
		int last=0;
		for(int i=0;i<pp.length();i++){
			if(pp[i]==' '){
				line.push_back(pp.substr(last,i-last));
				last=i+1;
			}
		}
		line.push_back(pp.substr(last,pp.length()-last));
		if(line[3]=="root"){
			if(get_int(line[0])==root->val) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}else if(line[4]=="siblings"){
			bool good=false;
			are_they_sblings(root,get_int(line[0]),get_int(line[2]),good);
			if(good) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}else if(line[3]=="parent"){
			bool good=false;
			are_they_fs(root,get_int(line[0]),get_int(line[5]),good);
			if(good) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;			
		}else if(line[3]=="left"){
			bool good=false;
			are_they_left(root,get_int(line[6]),get_int(line[0]),good);
			if(good) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;				
		}else if(line[3]=="right"){
			bool good=false;
			are_they_right(root,get_int(line[6]),get_int(line[0]),good);
			if(good) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;			
		}else if(line[3]=="are"){
			int a=-1,b=-1;
			get_level(0,root,get_int(line[0]),get_int(line[2]),a,b);
			if(a==b) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}else{
			bool good=true;
			is_it_a_full(root,good);
			if(good) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;			
		}
	}
	return 0;
}
