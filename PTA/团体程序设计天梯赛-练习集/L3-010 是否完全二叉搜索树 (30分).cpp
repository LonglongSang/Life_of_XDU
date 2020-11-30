#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;
int n,val;
struct node{
    int val;
    node* left;
    node* right;
    node(int _val): val(_val),left(NULL),right(NULL){
    }
};
int pre[1000];
bool cmp1(int a,int b){
    return a<b;
}
bool cmp2(int a,int b){
    return a>=b;
}
node* build(int left,int right,bool (*cmp)(int,int)){
    if(left>right) return NULL;
    node* root=new node(pre[left]);
    int k=left;
    while(k+1<=right && cmp(pre[k+1],pre[left])) k++;
    root->left=build(left+1,k,cmp);
    root->right=build(k+1,right,cmp);
    return root;
}
int seq[1000],cnt;
void in_traverse(node* root){
    if(!root) return;
    in_traverse(root->left);
    seq[cnt++]=root->val;
    in_traverse(root->right);
}
void post_traverse(node* root){
    if(!root) return;
    post_traverse(root->left);
    post_traverse(root->right);
    seq[cnt++]=root->val;
}
bool check1(){
    for(int i=1;i<n;i++) if(seq[i]<seq[i-1]) return false;
    return true;
}
bool check2(){
    for(int i=1;i<n;i++) if(seq[i]>seq[i-1]) return false;
    return true;
}
void pri(){
    printf("YES\n");
    printf("%d",seq[0]);
    for(int i=1;i<n;i++) printf(" %d",seq[i]);
    printf("\n");
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",pre+i);
    node* root=build(0,n-1,cmp1);
    in_traverse(root);
    if(check1()){
        cnt=0;
        post_traverse(root);
        pri();
        return 0;
    }
    root=build(0,n-1,cmp2);
    cnt=0;
    in_traverse(root);
    if(check2()){
        cnt=0;
        post_traverse(root);
        pri();
        return 0;
    }
    printf("NO\n");
    return 0;
}
