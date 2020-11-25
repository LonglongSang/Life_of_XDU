//https://loj.ac/p/110
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
using ll=long long;
ll n,q,dev=1000000007,ec;
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

int main(){
    scanf("%lld %lld",&n,&q);
    ec=qpow(9,dev-2,dev);
    ll a=qpow(10,n,dev);
    printf("%lld",q*(a-1)*ec%dev);

}