#include <stdio.h>
#include <stdlib.h>
typedef struct noode node;
struct noode{
    node* left;
    node* right;
    char val
};
node* new(char val){
    node* root=(node*)malloc(sizeof(node));
    root->left=NULL;
    root->right=NULL;
    root->val=val;
    return root;
}
int n;
char pre[100],in[100];
int cnt;
int get_index(){
    for(int i=0;i<n;i++){
        if(in[i]==pre[cnt]){
            cnt++;
            return i;
        }
    }
    return -1;
}
node* build_tree(int left,int right){
    if(right<left) return NULL;
    if(left==right) return new(pre[left]);
    int mid=get_index();
    node* ans=new(in[mid]);
    ans->left=build_tree(left,mid-1);
    ans->right=build_tree(mid+1,right);
    return ans;
}

int main(){
    scanf("%d",&n);
    scanf("%s\n",pre);
    scanf("%s\n",in);
    node* root=build_tree(0,n-1);
    return 0;
}