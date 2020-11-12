//https://www.luogu.com.cn/problem/P3372
//P3372 【模板】线段树 1
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;
ll dp[300000],ori[100005],tag[300000];
int n,m;
ll build(int pos,int left,int right){
    if(left==right){
        dp[pos]=ori[left];
        return dp[pos];
    } 
    int mid=(left+right)/2;
    dp[pos]+=build(pos*2,left,mid);
    dp[pos]+=build(pos*2+1,mid+1,right);
    return dp[pos];
} 
void to_solve(int pos,int left,int right,int mid){
    tag[pos*2]+=tag[pos];
    tag[pos*2+1]+=tag[pos];
    dp[pos*2]+=tag[pos]*(mid-left+1);
    dp[pos*2+1]+=tag[pos]*(right-mid);
    tag[pos]=0;
}
ll getsum(int pos,int left,int right,int lower,int upper){
    
    if(lower<=left && upper>=right){
        return dp[pos];
    }
    int mid=(left+right)/2;
    ll ans=0;
    if(left!=right && tag[pos]) to_solve(pos,left,right,mid);
    if(lower<=mid) ans+=getsum(pos*2,left,mid,lower,upper); 
    if(upper>mid) ans+=getsum(pos*2+1,mid+1,right,lower,upper);
    return ans;
}
void update(int pos,int left,int right,int lower,int upper,int add){
	//left,right是dp下标pos所管辖的区间范围，lower和upper是需要修改的区间,add是要向[lower,upper]区间加的值
    if(lower<=left && upper>=right){
        dp[pos]+=(right-left+1)*add;
        tag[pos]+=add;
        return;
    }
    int mid=(left+right)/2;
    if(left!=right && tag[pos]) to_solve(pos,left,right,mid);
    if(lower<=mid) update(pos*2,left,mid,lower,upper,add);
    if(upper>mid) update(pos*2+1,mid+1,right,lower,upper,add);
    dp[pos]=dp[pos*2]+dp[pos*2+1];
}
int main(void) {
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",ori+i);
    build(1,0,n-1);
    //for(int i=1;i<10;i++) printf("%d %d\n",i,dp[i]);
    int typ,upper,lower,add;
    for(int i=0;i<m;i++){
        scanf("%d",&typ);
        if(typ==1){
            scanf("%d %d %d",&lower,&upper,&add);
            lower--;
            upper--;
            update(1,0,n-1,lower,upper,add);
        }else{
            scanf("%d %d",&lower,&upper);
            lower--;
            upper--;
            printf("%lld\n",getsum(1,0,n-1,lower,upper));
        }
    }
    return 0;
}