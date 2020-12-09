//https://www.acwing.com/problem/content/discussion/content/1077/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define N 100005
#define mid (l+r)/2
#define ls p*2
#define rs (p*2+1)
using ll=long long;
int n,m,tag[N<<2],lower,upper,val,v;
char typ;
ll t[N<<2];

void update(int p,int l,int r){
    if(lower<=l && r<=upper){
        tag[p]+=val;
        t[p]+=(r-l+1)*val;
        return;
    }
    if(lower<=mid) update(ls,l,mid);
    if(upper>mid) update(rs,mid+1,r);
    t[p]=t[ls]+t[rs];
}
void push_down(int p,int l,int r){
    if(tag[p]==0) return;
    t[ls]+=(mid-l+1)*tag[p];
    tag[ls]+=tag[p];
    t[rs]+=(r-mid)*tag[p];
    tag[rs]+=tag[p];
    t[p]=t[ls]+t[rs];
    tag[p]=0;
}
ll query(int p,int l,int r){
    if(lower<=l && r<=upper) return t[p];
    push_down(p,l,r);
    return ((lower<=mid)?query(ls,l,mid):0)+((upper>mid)?query(rs,mid+1,r):0);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++){
        scanf("%d",&val);
        getchar();
        lower=i,upper=i;
        update(1,1,n);
    }
    for(int i=1;i<=m;i++){
        typ=getchar();
        cout<<"typ is "<<typ<<endl;
        getchar();
        if(typ=='C'){
            scanf("%d %d %d",&lower,&upper,&val);
            update(1,1,n);
        }else{
            scanf("%d %d",&lower,&upper);
        }
        getchar();
    }
}
