#include<iostream>
#include<cstdio>
#define N 1000001
using namespace std;
using ll=long long;
#define ls p<<1
#define rs (p<<1)+1
#define m (l+r)/2
int ori[N];
ll tag[N<<2],t[N<<2];
void build(int p,int l,int r){
    if(l==r){
        t[p]=ori[l];
        return;
    }  
    build(ls,l,m);
    build(rs,m+1,r);
    t[p]=t[ls]+t[rs];
}
void push_down(int p,int l,int r){
    if(tag[p]==0) return;
    tag[rs]+=tag[p];
    tag[ls]+=tag[p];
    t[ls]+=tag[p]*(m-l+1);
    t[rs]+=tag[p]*(r-m);
    tag[p]=0;
}
void update(int p,int l,int r,int q_l,int q_r,ll k){
    if(q_l<=l && r<=q_r){
        tag[p]+=k;
        t[p]+=k*(r-l+1);
        return;
    }
    push_down(p,l,r);
    if(q_l<=m) update(ls,l,m,q_l,q_r,k);
    if(q_r>m) update(rs,m+1,r,q_l,q_r,k);
    t[p]=t[ls]+t[rs];
}
ll query(int p,int l,int r,int q_l,int q_r){
    if(q_l<=l && r<=q_r){
        return t[p];
    }
    push_down(p,l,r);
    ll ret=0;
    if(q_l<=m) ret+=query(ls,l,m,q_l,q_r);
    if(q_r>m) ret+=query(rs,m+1,r,q_l,q_r);
    return ret;
}
int main()
{
    int n,q,typ,l,r;
    ll k;
    scanf("%d %d\n",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",ori+i);
        getchar();
    }
    build(1,1,n);
    for(int i=0;i<q;i++){
        scanf("%d ",&typ);
        switch(typ){
            case 1:{
                scanf("%d %d %lld\n",&l,&r,&k);
                update(1,1,n,l,r,k);
                break;
            }

            case 2:{
                scanf("%d %d\n",&l,&r);
                printf("%lld\n",query(1,1,n,l,r));
                break;
            }
        }
    }
    return 0;
}