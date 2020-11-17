#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
/* https://paste.ubuntu.com/p/BY2Rv3Rwv3/ */
using namespace std;
/*
 * 输入：
 * 第一行一个n，表示关键字个数
 * 后序n行，每行一个字符c和一个频率
 * 之后一行文本，需要我们来解析
 * 输出：
 * n行一个字符，以及其对应的huffman码
 * 之后会输出文本的经过Huffman编码后的文本
 * 之后一行会输出经过decode后的原文本
 */
/*
 * 样例1：
 * 26
 * a 0.830000
 * b 0.860000
 * c 0.770000
 * d 0.150000
 * e 0.930000
 * f 0.350000
 * g 0.860000
 * h 0.920000
 * i 0.490000
 * j 0.210000
 * k 0.620000
 * l 0.270000
 * m 0.900000
 * n 0.590000
 * o 0.630000
 * p 0.260000
 * q 0.400000
 * r 0.260000
 * s 0.720000
 * t 0.360000
 * u 0.110000
 * v 0.680000
 * w 0.670000
 * x 0.290000
 * y 0.820000
 * z 0.300000
 * abcdefghigkmnopqrstuvwxyzaaaaaaa
 */
using p = pair<char, float>;
p keyword[128];
/* 用来记录输入关键字及其频率 */
char code[128][9], path[9], after_encode[10000];
/*
 * code用来存储ascii码对应的的huffman码
 * after_encode用来存储经过编码后的文本的huffman码
 */
int n, pos;
struct huffman_node {
	/* huffman树的节点 */
	char v;
	/* 关键字v，只有叶子节点的v才有意义 */
	float f;
	/* 关键字v在文本中出现的频率 */
	huffman_node* next[2];
	/* 左右儿子 */
	huffman_node( int _v, float _f )
	{
		next[0] = NULL;
		next[1] = NULL;
		f	= _f;
		v	= _v;
	}


	huffman_node( huffman_node* a, huffman_node* b )
	{
		f	= a->f + b->f;
		next[0] = a;
		next[1] = b;
	}
}
;
void getcode( huffman_node* root, int step )
{
	/*
	 * 解析每一个关键字的huffman码
	 * 将其存储起来，方便encode
	 */
	if ( !root->next[0] && !root->next[1] )
	{
		path[step] = 0;
		memcpy( code[root->v], path, step );
		return;
	}
	path[step] = '0';
	getcode( root->next[0], step + 1 );
	path[step] = '1';
	getcode( root->next[1], step + 1 );
}


huffman_node* build_huffman()
{
	/* 构建huffman树 */
	huffman_node	* a;
	huffman_node	* b;
	huffman_node	* c;
	float		f;
	char		v;
	auto		cmp = [] (const huffman_node * a, const huffman_node * b) {
		return(a->f > b->f);
	}
	;
	priority_queue<huffman_node*, vector<huffman_node*>, decltype( cmp )> Q( cmp );
	/* 利用堆来加快huffman树的构造 */
	for ( int i = 0; i < n; i++ )
	{
		scanf( "%c %f\n", &keyword[i].first, &keyword[i].second );
		a = new huffman_node( keyword[i].first, keyword[i].second );
		Q.push( a );
	}
	while ( Q.size() > 1 )
	{
		a	= Q.top(), Q.pop();
		b	= Q.top(), Q.pop();
		Q.push( new huffman_node( a, b ) );
	}
	getcode( Q.top(), 0 );
	return(Q.top() );
}


void encode( huffman_node* root )
{
	/* encode输入的文本文件 */
	char v;
	while ( (v = getchar() ) != EOF )
	{
		strcat( after_encode, code[v] );
	}
}


void decode( huffman_node* root )
{
	/* 对huffman码进行解析，恢复为原来的句子 */
	if ( !root->next[0] && !root->next[1] )
	{
		putchar( root->v );
		return;
	}
	decode( root->next[after_encode[pos++] - '0'] );
}


int main()
{
	scanf( "%d\n", &n );
	if ( n <= 1 )
	{
		/* 如果关键字只有一个就没有必要编码 */
		printf( "this is no need to encoding\n" );
		return(0);
	}
	huffman_node*root = build_huffman();
	for ( int i = 0; i < n; i++ )
	{
		/* 输出每个关键字对应的huffman码 */
		printf( "%c 's huffman code is: %s\n", keyword[i].first, code[keyword[i].first] );
	}
	encode( root );
	/* 编码 */
	printf( "after_encode %s\n", after_encode );
	printf( "now will decode:\n" );
	while ( after_encode[pos] != 0 )
		decode( root );
	/* 解码 */
	return(0);
}
