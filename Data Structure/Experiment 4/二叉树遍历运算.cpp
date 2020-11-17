#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct node {
	node	* left;
	node	* right;
	char	val;
	node( int _v ) : left( NULL ), right( NULL ), val( _v ){}
};

void create( node* &root )
{
	/* 创建二叉树 */
	char v = getchar();
	if ( v == '.' )
		root = NULL;
	else{
		root = new node( v );
		create( root->left );
		create( root->right );
	}
}


void preorder( node* root )
{
	/* 前序遍历 */
	if ( !root )
		return;
	putchar( root->val );
	preorder( root->left );
	preorder( root->right );
}


void inorder( node* root )
{
	/* 中序遍历 */
	if ( !root )
		return;
	inorder( root->left );
	putchar( root->val );
	inorder( root->right );
}


void postorder( node* root )
{
	/* 后序遍历 */
	if ( !root )
		return;
	postorder( root->left );
	postorder( root->right );
	putchar( root->val );
}


int main()
{
	node* root = NULL;
	create( root );
	printf( "pre order: " );
	preorder( root );
	putchar( '\n' );

	printf( "in order: " );
	inorder( root );
	putchar( '\n' );

	printf( "post order: " );

	postorder( root );
	putchar( '\n' );
	return(0);
}
