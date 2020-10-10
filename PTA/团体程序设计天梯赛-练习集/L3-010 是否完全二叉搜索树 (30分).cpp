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
    node* build_tree(node* root,int val){
        if(root==NULL){
            root=new node(val);
            return root;
        }
        if(val>root->val) root->left=build_tree(root->left,val);
        else root->right=build_tree(root->right,val);
        return root;
    }
    struct pos{
        node* root;
        int index;
    };
    bool level_traverse(node* root){
        queue<pos> Q;
        Q.push({root,1});
        int cnt=0;
        int want=1;
        bool ans=true;
        while(!Q.empty()){
            pos cur=Q.front();
            Q.pop();
            if(cur.index!=want) ans=false;
            want++;
            if(cnt) printf(" %d",cur.root->val);
            else printf("%d",cur.root->val);
            cnt++;
            //if(!cur.root->left && cur.root->right) ans=false;
            if(cur.root->left) Q.push({cur.root->left,cur.index*2});
            if(cur.root->right) Q.push({cur.root->right,cur.index*2+1});
        }
        printf("\n");
        return ans;
    }
    int main(){
        node* root=NULL;
        scanf("%d\n",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&val);
            root=build_tree(root,val);
        }
        if(level_traverse(root)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        
    }