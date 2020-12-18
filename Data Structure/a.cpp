#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
    int val;
    node* next;
    node(int v):val(v),next(NULL){}
};


void insert(node*& head,node* i){
    if(head==NULL || i->val<head->val){
        i->next=head;
        head=i;
    }else{
        node* cur=head;
        while(cur->next!=NULL && i->val>=cur->next->val) cur=cur->next;
        i->next=cur->next;
        cur->next=i;
    }
}
node* sortList(node* cur){
    node* head=NULL;
    node* next;
    while(cur){
        next=cur->next;
        insert(head,cur);
        cur=next;
    }
    return head;
}
int main(){
    node* root=NULL;
    for(int i=0;i<10000;i++) insert(root,new node(rand()%21312));
    node* temp=root;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}