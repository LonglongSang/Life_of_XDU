/*
P1209 [USACO1.3]修理牛棚 Barn Repair
https://www.luogu.com.cn/problem/P1209
题目样例：
4 50 18
3 
4 
6 
8 
14
15 
16 
17 
21
25 
26 
27 
30 
31 
40 
41 
42 
43
答案：
25

思想：我们有18头牛分布在3到43牛棚的范围，我们最简单的方式，直接拿一根长为43-3+1的木头覆盖就完了
此题给了我们m根（4根）木头，那就是说我们可以留下至多3（4-1）个连续区域的牛棚不给覆盖
那么我们就找出牛棚区域内所有的gap
此题为
32 39
9 13
18 20
22 24
28 29
5 5
7 7
我们从中选出最多3个区域，使这三个区域的牛棚最多
即为前三个，他们加起来长度为（39-32+1）+（13-9+1）+（20-18+1）= 16
那么答案就位41-16=25
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <queue>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
using namespace std;
struct node{
    int left,right;
}arr[100];
int cnt[300];

int main(void){
    int m,niupeng,niu,temp;
    scanf("%d %d %d\n",&m,&niupeng,&niu);
    for(int i=0;i<niu;i++){
        scanf("%d\n",&temp);
        cnt[temp]++;
    }
    int gap=0;
    bool start=false;
    int left=-1;
    int left_boundary,right_boundary;
    for(int i=1;i<=205;i++){
        if(cnt[i]){
            if(!start) left_boundary=i;
            right_boundary=i;
            start=true;
            if(left!=-1){
                arr[gap].left=left;
                arr[gap++].right=i-1;
            }
            left=-1;
        }
        if(left==-1 && cnt[i]==0 && start){
            left=i;
        }
    }
    sort(arr,arr+gap,[](const node&a,const node&b){
        return a.right-a.left>b.right-b.left;
    });
    int ans=right_boundary-left_boundary+1;
    for(int i=0;i<min(gap,m-1);i++){
        ans-=(arr[i].right-arr[i].left+1);
    }
    printf("%d\n",ans);
    return 0;
}


