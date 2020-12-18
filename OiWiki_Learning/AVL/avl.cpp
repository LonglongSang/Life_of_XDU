#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
struct node{
    int val;
    node* left;
    node* right;
    int h;
    node(int v):h(1),val(v),left(NULL),right(NULL){}
};
int height(node* root){
    if(!root) return 0;
    else return root->h;
}
void LL(node*& root){
    node* temp=root->left;
    root->left=temp->right;
    temp->right=root;
    root->h=std::max(height(root->left),height(root->right))+1;
    root=temp;
}
void RR(node*& root){
    node* temp=root->right;
    root->right=temp->left;
    temp->left=root;
    root->h=std::max(height(root->left),height(root->right))+1;
    root=temp;
}
void LR(node*& root){
    RR(root->left);
    LL(root);
}
void RL(node*& root){
    LL(root->right);
    RR(root);
}
void adjust(node*& root){
    if(height(root->left)-height(root->right)>1){
        if(height(root->left->left)>=height(root->left->right)){
            LL(root);
        }else{
            LR(root);
        }
    }else if(height(root->right)-height(root->left)>1){
        if(height(root->right->right)>=height(root->right->left)){
            RR(root);
        }else{
            RL(root);
        }
    }
    root->h=std::max(height(root->left),height(root->right))+1;
}
void insert(node*& root,int val){
    if(!root) root=new node(val);
    if(val<root->val) insert(root->left,val);
    else if(root->val<val) insert(root->right,val);
    adjust(root);
}
node* findMax(node* root){
    if(!root || !root->right) return root;
    else return findMax(root->right);
}
void erase(node*& root,int val){
    if(!root) return;
    if(root->val==val){
        if(root->left && root->right){
            node* temp=findMax(root->left);
            std::swap(root->val,temp->val);
            erase(root->left,val);
        }else{
            node* temp=root;
            root=root->left?root->left:root->right;
            delete temp;
        }
    }else if(val<root->val){
        erase(root->left,val);
    }else{
        erase(root->right,val);
    }
    if(root) adjust(root);
}
int get_height(node* root){
    if(!root) return 0;
    int left=get_height(root->left);
    int right=get_height(root->right);
    return std::max(left,right)+1;
}
void clear(node* root){
    if(!root) return;
    clear(root->left);
    clear(root->right);
    delete root;
}
void inOrder(node* root){
    if(!root) return;
    inOrder(root->left);
    printf("%d ",root->val);
    inOrder(root->right);
}
int check(node* root,std::set<int>& dp,bool& good,int &last){
    if(!root) return 0;
    int left=0,right=0;
    if(good) left=check(root->left,dp,good,last);
    if(dp.find(root->val)==dp.end() || root->val<=last) good=false;
    last=root->val;
    if(good) right=check(root->right,dp,good,last);
    if(left-right>1 || right-left>1) good=false;
    return std::max(left,right)+1;
}
int getNum(node* root){
    if(!root) return 0;
    return getNum(root->left)+getNum(root->right)+1;
}
node* build(int n){
    node* root=NULL;
    srand(time(0));
    std::set<int> dp;
    int v,dev=1e9+7;
    for(int i=0;i<n;i++){
        v=rand()%dev;
        dp.insert(v);
        insert(root,v);
    }
    printf("n is:%d\n",n);
    printf("first check\n");
    printf("dp's size: %d cal size: %d\n",dp.size(),getNum(root));
    printf("get_height:%d height of root:%d\n",get_height(root),root->h);
    {
        //check
        bool good=true;
        int last=0x80000000;
        check(root,dp,good,last);
        if(good) printf("yes\n");
        else printf("no\n");
    }
    //return 0;
    for(int i=0;i<n/10;i++){
        v=rand()%dev;
        dp.erase(v);
        erase(root,v);
    }
    printf("second check\n");
    printf("dp's size: %d cal size: %d\n",dp.size(),getNum(root));
    printf("get_height:%d height of root:%d\n",get_height(root),root->h);
    {
        //check
        bool good=true;
        int last=0x80000000;
        check(root,dp,good,last);
        if(good) printf("yes\n");
        else printf("no\n");
    }
    //inOrder(root);
    clear(root);
    return NULL;
}


int main(){
    build(1000000);
}