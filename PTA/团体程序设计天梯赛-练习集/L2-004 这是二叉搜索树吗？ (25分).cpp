#include <stdio.h>
#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,m,k,a,b;
ll arr[1005];
ll temp[1005];
struct node{
    node* left;
    node* right;
    ll val;
    node(int _val): val(_val),left(NULL),right(NULL){}
};
node* build1(int left,int right){
    if(left>right) return NULL;
    node* root=new node(arr[left]);
    int mid=left;
    while(mid+1<right && arr[mid+1]<arr[left]) mid++;
    root->left=build1(left+1,mid);
    root->right=build1(mid+1,right);
    return root;
}
node* build2(int left,int right){
    if(left>right) return NULL;
    node* root=new node(arr[left]);
    int mid=left;
    while(mid+1<right && arr[mid+1]>=arr[left]) mid++;
    root->right=build2(left+1,mid);
    root->left=build2(mid+1,right);
    return root;
}
int cnt=0;
void check(node* root){
    if(!root) return;
    check(root->left);
    temp[cnt++]=root->val;
    check(root->right);
}
void post(node* root){
    if(!root) return;
    post(root->left);
    post(root->right);
    if(cnt++){
        printf(" %lld",root->val);
    }else{
        printf("%lld",root->val);
    }
}
void ok(node* root){
    printf("YES\n");
    cnt=0;
    post(root);
    printf("\n");
}
bool fun( node* (build)(int,int)){
    node* root=build(0,n-1);
    check(root);
    bool good=true;
    cnt=0;
    for(int i=1;i<n;i++){
        if(temp[i]<temp[i-1]){
            good=false;
            break;
        }
    }
    if(!good) return false;
    ok(root);
    return true;
}
int main() {
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",arr+i);
        getchar();
    }
    if(fun(build1)) return 0;
    if(fun(build2)) return 0;
    printf("NO\n");
	return 0;
}