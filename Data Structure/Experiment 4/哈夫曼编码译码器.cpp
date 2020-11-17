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
 * ���룺
 * ��һ��һ��n����ʾ�ؼ��ָ���
 * ����n�У�ÿ��һ���ַ�c��һ��Ƶ��
 * ֮��һ���ı�����Ҫ����������
 * �����
 * n��һ���ַ����Լ����Ӧ��huffman��
 * ֮�������ı��ľ���Huffman�������ı�
 * ֮��һ�л��������decode���ԭ�ı�
 */
/*
 * ����1��
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
/* ������¼����ؼ��ּ���Ƶ�� */
char code[128][9], path[9], after_encode[10000];
/*
 * code�����洢ascii���Ӧ�ĵ�huffman��
 * after_encode�����洢�����������ı���huffman��
 */
int n, pos;
struct huffman_node {
	/* huffman���Ľڵ� */
	char v;
	/* �ؼ���v��ֻ��Ҷ�ӽڵ��v�������� */
	float f;
	/* �ؼ���v���ı��г��ֵ�Ƶ�� */
	huffman_node* next[2];
	/* ���Ҷ��� */
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
	 * ����ÿһ���ؼ��ֵ�huffman��
	 * ����洢����������encode
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
	/* ����huffman�� */
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
	/* ���ö����ӿ�huffman���Ĺ��� */
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
	/* encode������ı��ļ� */
	char v;
	while ( (v = getchar() ) != EOF )
	{
		strcat( after_encode, code[v] );
	}
}


void decode( huffman_node* root )
{
	/* ��huffman����н������ָ�Ϊԭ���ľ��� */
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
		/* ����ؼ���ֻ��һ����û�б�Ҫ���� */
		printf( "this is no need to encoding\n" );
		return(0);
	}
	huffman_node*root = build_huffman();
	for ( int i = 0; i < n; i++ )
	{
		/* ���ÿ���ؼ��ֶ�Ӧ��huffman�� */
		printf( "%c 's huffman code is: %s\n", keyword[i].first, code[keyword[i].first] );
	}
	encode( root );
	/* ���� */
	printf( "after_encode %s\n", after_encode );
	printf( "now will decode:\n" );
	while ( after_encode[pos] != 0 )
		decode( root );
	/* ���� */
	return(0);
}
