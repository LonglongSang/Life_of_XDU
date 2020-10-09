#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int n,temp,m,a,b,ans;
struct node{
    char val;
    int f;
    node* left;
    node* right;
    node(char _val,int _f):val(_val),f(_f),left(NULL),right(NULL){}
};
struct cmp{
    bool operator ()(const node* a,const node* b)const{
        return a->f>b->f;
    }
};
priority_queue<node*,vector<node*>,cmp> Q;
void build_huffman(){
    while(Q.size()!=1){
        node* a=Q.top();
        Q.pop();
        node* b=Q.top();
        Q.pop();
        node* merge=new node('0',a->f + b->f);
        merge->left=a;
        merge->right=b;
        Q.push(merge);
    }
}
int get_ans(node* a,int step){
    if(a->left==NULL && a->right==NULL){
        return step * a->f;
    }
    int sum=0;
    if(a->left) sum+=get_ans(a->left,step+1);
    if(a->right) sum+=get_ans(a->right,step+1); 
    return sum;
}
int weight[128];
char val[65];
char code[65][30];
int main(){
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        node* temp=new node('0',1);
        scanf("%c %d",&(temp->val),&(temp->f));
        weight[temp->val]=temp->f;
        getchar();
        Q.push(temp);
    }
    build_huffman();
    ans=get_ans(Q.top(),0);
    scanf("%d\n",&m);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%c %s\n",&val[j],&code[j]);
        }
        int sum=0;
        for(int j=0;j<n;j++) sum+=weight[val[j]]*strlen(code[j]);
        if(sum!=ans){
            printf("No\n");
            continue;
        }
        bool good=true;
        for(int a=0;a<n-1;a++){
            for(int b=a+1;b<n;b++){
                if(strstr(code[a],code[b])==code[a]){
                    good=false;
                    break;
                }
            }
            if(!good) break;
        }
        if(good){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}