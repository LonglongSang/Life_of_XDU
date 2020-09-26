/*
P2949 [USACO09OPEN]Work Scheduling G
工作调度
https://www.luogu.com.cn/problem/P2949
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
    int d,p;
}arr[100005];
struct cmp{
    bool operator()(const int&a,const int&b){
        return a>b;
    }
};
int main(void){
    int n,deadline,price;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d\n",&arr[i].d,&arr[i].p);
    }
    sort(arr,arr+n,[](const node&a,const node&b){
        return a.d!=b.d? a.d<b.d : a.p>b.p;
    });
    priority_queue<int,vector<int>,cmp> Q;
    long ans=0;
    for(int i=0;i<n;i++){
        if(arr[i].d>Q.size()){
            Q.push(arr[i].p);
            ans+=arr[i].p;
        }else if(arr[i].p>Q.top()){
            ans-=Q.top();
            Q.pop();
            Q.push(arr[i].p);
            ans+=arr[i].p;
        }
    }
    printf("%ld\n",ans);
    return 0;
}


