#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
//#include <math.h>
#include <cmath>
#include <queue>
using namespace std;



#define N 505
#define M 1001
using LL=long long;
double loge[M];
double C(int a,int b){
    return loge[a]-loge[b]-loge[a-b];
}
LL p=1e9+7;
LL quick_mod(LL a, LL b)
{
    LL ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}
 
LL C(LL n, LL m)
{
    if(m > n) return 0;
    LL ans = 1;
    for(int i=1; i<=m; i++)
    {
        LL a = (n + i - m) % p;
        LL b = i % p;
        ans = ans * (a * quick_mod(b, p-2) % p) % p;
    }
    return ans;
}

LL Lucas(LL n, LL m)
{
    if(m == 0) return 1;
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int head[N],tot;
struct edge{
    int to;
    LL weight;
    double cost;
    int next;
}e[N*N/2+10];
void add(vector<int>& a){
    e[++tot].to=a[0];
    e[tot].next=head[a[1]];
    e[tot].weight=Lucas(a[2],a[3]);
    e[tot].cost=C(a[2],a[3]);
    head[a[1]]=tot;


    e[++tot].to=a[1];
    e[tot].next=head[a[0]];
    e[tot].weight=e[tot-1].weight;
    e[tot].cost=e[tot-1].cost;
    head[a[0]]=tot;
}
struct node{
    int to;
    LL weight;
    double cost;
};
struct cmp{
    bool operator()(node&a,node&b){
        return a.cost>b.cost;
    }
};
bool vis[N];

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param n int整型 有n个城市
     * @param m int整型 有m条路径
     * @param s int整型 起始城市坐标
     * @param t int整型 终点城市坐标
     * @param edge int整型vector<vector<>> 边的格式如下:[[u1,v1,a1,b1],[u2,v2,a2,b2],...]
     * @return int整型
     */
    void init(){
        loge[0]=0;
        for(int i=1;i<M;i++){
            loge[i]=loge[i-1]+log((double)i);
        }
    }

    int minDist(int n, int m, int s, int t, vector<vector<int> >& edge) {
        // write code here
        tot=0;
        init();
        memset(vis+1,0,n);
        memset(head+1,0,sizeof(int)*n);
        for(auto&v:edge){
            add(v);
        }
        priority_queue<node,vector<node>,cmp>Q;
        node cur;
        Q.push({s,1LL,0.0});
        while(!Q.empty()){
            cur=Q.top();
            Q.pop();
            if(vis[cur.to]) continue;
            vis[cur.to]=true;
            if(cur.to==t) return (int)cur.weight;
            for(int i=head[cur.to];i;i=e[i].next){
                if(vis[e[i].to]) continue;
                Q.push({e[i].to,(cur.weight*e[i].weight)%p,cur.cost+e[i].cost});
            }
        }
        return 0;
    }
};