#include <stdlib.h>
#include <stdio.h>
using namespace std;
using ll=long long;
ll dev=1e9+7;
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
    printf("%lld\n",qpow(2,100,dev));
    return 0;
}