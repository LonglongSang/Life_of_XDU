//https://www.luogu.com.cn/problem/P1168
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define N 100005
#define ls pos*2
#define rs (pos*2+1)
#define mid (l+r)/2
int ori[N],t[N<<2],n,cnt,uni[N],m;
unordered_map<int,int> mp;
int pos(int v){ return lower_bound(uni+1,uni+1+m,v)-uni;}
void update(int pos,int l,int r,int i,int add){
    if(l==r){
        t[pos]+=add;
        return;
    }
    if(i<=mid) update(ls,l,mid,i,add);
    else update(rs,mid+1,r,i,add);
    t[pos]=t[ls]+t[rs];
}
int query(int pos,int l,int r,int kth){
    if(l==r) return l;
    if(kth<=t[ls]) return query(ls,l,mid,kth);
    else return query(rs,mid+1,r,kth-t[ls]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",ori+i);
    memcpy(uni+1,ori+1,n*4);
    sort(uni+1,uni+1+n);
    m=unique(uni+1,uni+1+n)-uni-1;
    for(int i=1;i<=n;i++){
        update(1,1,m,pos(ori[i]),1);
        if(i%2) printf("%d\n",uni[query(1,1,m,i/2+1)]);
    }
    return 0;
}
