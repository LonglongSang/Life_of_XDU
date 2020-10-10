#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct node{
	int val;
	node* next;
};
 node* build_list(){
	node* root=(node*)malloc(sizeof(node));//头结点，空的
	root->next=NULL;
	node* last=root;
	node* temp;
	int val;
	do{
		scanf("%d",&val);
		getchar();
		if(val==-1) return root;
		temp=(node*)malloc(sizeof(node));
		temp->val=val;
		temp->next=NULL;
		last->next=temp;
		last=temp;
	}while(1);
	return root;
}
void assign(node** root,node** last,node** root1){
	if(!*root){
		*root=*root1;
		*last=*root1;
	}else{
		(*last)->next=*root1;
		(*last)=*root1;
	}
	*root1=(*root1)->next;
	(*last)->next=NULL;	
}
int main(){
	node* root1=build_list();
	node* root2=build_list();
	root1=root1->next;
	root2=root2->next;
	if(!root1 && !root2){
		printf("NULL\n");
		return 0;
	}
	node* last=NULL;
	node* root=NULL;
	while(root1 && root2){
		if(root1->val<root2->val){
			assign(&root,&last,&root1);
		}else{
			assign(&root,&last,&root2);
		}
	}
	while(root1){
		assign(&root,&last,&root1);
	}
	while(root2){
		assign(&root,&last,&root2);
	}
	int i=0;
	while(root){
		if(i) printf(" %d",root->val);
		else printf("%d",root->val);
		root=root->next;
		i++;
	}
	printf("\n");
	
    return 0;
}