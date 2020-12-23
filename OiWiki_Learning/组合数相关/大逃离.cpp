//https://ac.nowcoder.com/acm/contest/10323/C
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

#define N 200005
int inv[N],fac[N],ok,dev=1e9+7,q[N];
//fac[i]=(i!)%dev
//int[i]=逆元(fac[i])
//如何求一个数i关于模dev的逆元 逆元(i)=ksm(i,dev-2,dev)
using ll=long long;
int ksm(int base,int power,int mod){
    //快速幂,base的power次方对mod取模
    int ans=1;
    while(power){
        if(power%2) ans=1LL*ans*base%mod;
        base=1LL*base*base%mod;
        power/=2;
    }
    return ans;
}
void init(){
    if(ok) return;
    ok=1;
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i]=1LL*fac[i-1]*i%dev;
    //初始化阶乘
    inv[N-1]=ksm(fac[N-1],dev-2,dev);
    for(int i=N-2;i>=0;i--) inv[i]=1LL*inv[i+1]*(i+1)%dev;
    //初始化逆元

}
//C(n,m)=n! / (n-m)! / m!
int C(int n,int m){
    //求模运算下的组合数 C(n,m)%dev
    //C(n,m)=fac[n]*inv[n-m]*inv[m]
    return 1LL*fac[n]*inv[n-m]%dev*inv[m]%dev;
}
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param n int整型 
     * @param k int整型 
     * @param Point int整型vector 
     * @return int整型vector
     */
    vector<int> city(int n, int k, vector<int>& Point) {
        init();
        for(int i=0;i<n;i++) q[i]=i;
        sort(q,q+n,[&](int a,int b){
            return Point[a]<Point[b];
        });
        int tot=C(n,k);
        tot=ksm(tot,dev-2,dev);
        for(int i=0;i<k-1;i++) Point[q[i]]=0;
        for(int i=k-1;i<n;i++){
            Point[q[i]]=1LL*C(i,k-1)*tot%dev;
        }
        return Point;
    }
};









int main(){

}