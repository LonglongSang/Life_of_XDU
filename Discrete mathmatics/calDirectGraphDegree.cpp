/*
This file please name as "xx.cpp"
Then you can follow the input standard
to calculate the degree of a given
directed graph
Author:
Long long Sang 
Date:
2020-12-12
Email:
llsang@foxmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define N 10005
int inDegree[N], outDegree[N], n, m, from, to;
void calDirectGraphDegree(){
    scanf("%d %d", &n, &m);
    getchar();
    for(int i = 0; i < m; i++){
        scanf("%d %d", &from, &to);
        outDegree[from]++;
        inDegree[to]++;
    }
    printf("vertex\tin degree\tout degree\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%d\t%d\n", i, inDegree[i], outDegree[i]);
    }
}
/*
input standard:
first line tow decimal number:
n m
n meaning number of vertex and m menaing number of edge
Then m line follow, and each line include three num like:
vertex1 vertex2
meaning there is a directed edge from vertex1 to vertex2
0 <= vertex1 < n
0 <= vertex2 < n

Example:
4 4
0 1
1 0
1 1
2 3
*/

int main(){
    calDirectGraphDegree();
}


