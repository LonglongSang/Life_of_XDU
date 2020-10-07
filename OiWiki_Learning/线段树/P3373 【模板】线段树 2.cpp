//https://www.luogu.com.cn/problem/P3373
//P3373 【模板】线段树 2
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
/*
第一行包含三个整数 n,m,p，分别表示该数列数字的个数、操作的总个数和模数。

第二行包含 n 个用空格分隔的整数，其中第 ii 个数字表示数列第 ii 项的初始值。

接下来 mm 行每行包含若干个整数，表示一个操作，具体如下：

操作 1： 格式：1 x y k 含义：将区间 [x,y][x,y] 内每个数乘上 k

操作 2： 格式：2 x y k 含义：将区间 [x,y][x,y] 内每个数加上 k

操作 3： 格式：3 x y 含义：输出区间 [x,y][x,y] 内每个数的和对 pp 取模所得的结果
*/
#define N (int)1e6+5
typedef long long ll;
int n,m,typ,lower,upper;
ll q,k;
ll arr[N],dp[N*4];
bool mul;
struct node{
    ll k;
    bool mul;
};
unordered_map<int,queue<node>> tag;

void build(int pos,int left,int right){
    if(left==right){
        dp[pos]=arr[left];
        return;
    }
    int mid=(left+right)/2;
    build(pos*2,left,mid);
    build(pos*2+1,mid+1,right);
    dp[pos]=dp[pos*2]+dp[pos*2+1];
}

void assign(int pos,int left,int right){
    int mid=(left+right)/2;
    while(tag[pos].size()){
        if(mid!=left) tag[pos*2].push({tag[pos].front()});
        if(mid+1!=right) tag[pos*2+1].push({tag[pos].front()});
        if(tag[pos].front().mul){
            dp[pos*2]*=tag[pos].front().k;
            dp[pos*2+1]*=tag[pos].front().k;
        }else{
            dp[pos*2]+=(ll)(mid-left+1)*tag[pos].front().k;
            dp[pos*2+1]+=(ll)(right-mid)*tag[pos].front().k;
        }
        tag[pos].pop();
    }
    tag.erase(pos);
}
void update(int pos,int left,int right){
    if(lower<=left && right<=upper){
        if(mul){
            dp[pos]*=k;
        }else{
            dp[pos]+=(ll)(right-left+1)*k;
        }
        if(left!=right) tag[pos].push({k,mul});
        return;
    }
    int mid=(left+right)/2;
    if(tag.find(pos)!=tag.end()) assign(pos,left,right);
    if(lower<=mid) update(pos*2,left,mid);
    if(upper>mid) update(pos*2+1,mid+1,right);
    dp[pos]=dp[pos*2]+dp[pos*2+1];
}
ll getsum(int pos,int left,int right){
    if(lower<=left && right<=upper){
        return dp[pos];
    }
    int mid=(left+right)/2;
    if(tag.find(pos)!=tag.end()) assign(pos,left,right);
    ll ans=0;
    if(lower<=mid) ans+=getsum(pos*2,left,mid);
    if(upper>mid) ans+=getsum(pos*2+1,mid+1,right);
    return ans;
}
int main(){
    scanf("%d %d %lld\n",&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%lld",arr+i);
    build(1,1,n);
    for(int i=0;i<m;i++){
        scanf("%d ",&typ);
        //1 x y k 含义：将区间 [x,y][x,y] 内每个数乘上 k
        //格式：2 x y k 含义：将区间 [x,y][x,y] 内每个数加上 k
        if(typ!=3){
            //乘以
            scanf("%d %d %lld\n",&lower,&upper,&k);
            if(typ==1) mul=true;
            else mul=false;
            update(1,1,n);
        }else{
            scanf("%d %d\n",&lower,&upper);
            printf("%lld\n",getsum(1,1,n)%q);

        }

    }
    return 0;
}