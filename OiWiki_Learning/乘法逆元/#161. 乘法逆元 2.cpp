//https://loj.ac/p/110
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
using ll=long long;
ll n,dev=1000000007,ec,p,ans,a,q=998244353;
ll qpow(ll a, ll p,ll dev){
    //(a**p)%dev
    ll ans=1;
    while(p){
        if(p&1) ans=(ans*a)%dev;
        p/=2;
        a=(a*a)%dev;
    }
    return ans;
}
ll val[500000];
int main(){

    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",val+i);
    }
    ll x=1;
    for(int i=n;i>=1;i--){
        ans=(ans+qpow(a,dev-2,dev)*x)%dev;
        x=(x*q)%dev;
    }
    printf("%lld",ans);

}

