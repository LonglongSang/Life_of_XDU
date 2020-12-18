//https://ac.nowcoder.com/acm/contest/10167/C
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <string.h>
using namespace std;



/*
这个题思想很巧妙，给定我们一个树，求出树中所有路径值的和，路径定义为路径经过的所有点的价值的与运算的和
一个点也算一个路径。
思路：
题目给定每个点的价值小于2的20次方，对于二进制中的每一位，求出该树的连通子集
假如对于第i位的第j个联通子集，其包含的点数量为num[j]
sum+=(1<<i)*E(num[j]*(num[j]+1)/2)
类似于分治
*/
#define N 100005
int par[N],cpy[N],cnt[N],tot;
bool vis[N];
int find(int a){
    if(a==par[a]) return a;
    else return par[a]=find(par[a]);
}
void merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(cnt[b]>cnt[a]) swap(a,b);
    par[a]=b;
    cnt[b]+=cnt[a];
}
void init(int n){
    if(tot==0){
        for(int i=0;i<N;i++) cpy[i]=i;
    }
    tot++;
    memcpy(par,cpy,sizeof(int)*(n+1));
    memset(cnt,-1,sizeof(int)*(n+1));
    memset(vis,0,n+1);
}
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param n int整型 点的个数
     * @param u int整型vector 每条边的起点
     * @param v int整型vector 每条边的终点
     * @param p int整型vector 每个点的价值
     * @return long长整型
     */
    long long solve(int n, vector<int>& u, vector<int>& v, vector<int>& p) {
        // write code here
        using ll=long long;
        ll sum=0,num,temp_sum;
        int k=0,z,q;
        for(int i=0;i<n;i++){
            //求出价值的二进制最高位
            q=p[i];
            z=0;
            while(q){
                q/=2;
                z++;
            }
            k=max(k,z);
        }
        for(int i=0;i<k;i++){//对k个2进制位遍历
            init(n);//初始化
            for(int j=0;j<n-1;j++){
                //并查集寻找连通子集
                if((p[u[j]]&p[v[j]]&(1<<i))==0) continue;
                //如果这条边连接的两个点不能够形成联通条件，就跳过
                merge(u[j]+1,v[j]+1);
            }
            temp_sum=0;
            for(int j=1;j<=n;j++){
                if(vis[find(j)] || (p[j-1]&(1<<i))==0) continue;
                vis[find(j)]=true;
                num=-cnt[find(j)];//该连通集的大小
                //点个数为num的连通集，可形成路径数num*(num+1)/2
                temp_sum+=(num+1)*num/2;
            }
            sum+=temp_sum*(1<<i);
        }
        return sum;
    }
};












int main(){

}