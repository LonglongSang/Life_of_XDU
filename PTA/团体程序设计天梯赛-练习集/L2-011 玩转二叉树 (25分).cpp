#include <stdio.h>
#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
//中前
int pre[100],in[100];
int n;
struct node{
    node* left;
    node* right;
    int val;
    node(int _val): val(_val),left(NULL),right(NULL){}
};
node* build(int left,int right,int index){
    if(left>right) return NULL;
    node* root=new node(pre[index]);
    int mid=left;
    while(mid<=right && in[mid]!=pre[index]) mid++;
    //left mid-1 index+1
    //mid+1 right index+mid-left+1
    root->left=build(left,mid-1,index+1);
    root->right=build(mid+1,right,index+mid-left+1);
    return root;
}
void scan(int* a){
    for(int i=0;i<n;i++) scanf("%d",a+i);
}
void rev(node* root){
    if(!root) return;
    swap(root->left,root->right);
    rev(root->left);
    rev(root->right);
}
void bfs(node* root){
    queue<node*> Q;
    int cnt=0;
    Q.push(root);
    while(!Q.empty()){
        root=Q.front();
        Q.pop();
        if(cnt++) printf(" ");
        printf("%d",root->val);
        if(root->left) Q.push(root->left);
        if(root->right) Q.push(root->right);
    }
}
int main(){
    node* root=NULL;
    scanf("%d\n",&n);
    scan(&in[0]);
    scan(&pre[0]);
    root=build(0,n-1,0);
    rev(root);
    bfs(root);
    return 0;
}