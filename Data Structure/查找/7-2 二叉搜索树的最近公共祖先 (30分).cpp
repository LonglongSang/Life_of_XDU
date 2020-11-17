#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int n,m,a,b,v,cnt;
int arr[10000];
struct node{
    int val;
    node* left;
    node* right;
    node(int v):val(v),left(NULL),right(NULL){}
};
node* build(int l,int r){
    if(l>=r) return NULL;
    int i=l;
    node* root=new node(arr[l]);
    while(i<r && arr[i]<=arr[l]) i++;
    root->left=build(l+1,i);
    root->right=build(i,r);
    return root;
}

node* LCA(node* root){
    if(!root) return NULL;
    if(root->val==a || root->val==b) return root;
    node* left=LCA(root->left);
    node* right=LCA(root->right);
    if(left && right) return root;
    return left?left:right;
}
int main(){
    //for(int i=0;i<10000;i++) printf("%d ",i);
    //return 0;
    unordered_set<int> dp;
    scanf("%d %d\n",&m,&n);
    for(int i=0;i<n;i++) scanf("%d",arr+i),dp.insert(arr[i]);
    node* root=build(0,n);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        if(dp.find(a)==dp.end() && dp.find(b)==dp.end()){
            printf("ERROR: %d and %d are not found.\n",a,b);
        }else if(dp.find(a)==dp.end()){
            printf("ERROR: %d is not found.\n",a);
        }else if(dp.find(b)==dp.end()){
            printf("ERROR: %d is not found.\n",b);
        }else{
            node* temp=LCA(root);
            if(temp->val==a){
                printf("%d is an ancestor of %d.\n",a,b);
            }else if(temp->val==b){
                printf("%d is an ancestor of %d.\n",b,a);
            }else{
                printf("LCA of %d and %d is %d.\n",a,b,temp->val);
            }
        }
    }
    return 0;
}