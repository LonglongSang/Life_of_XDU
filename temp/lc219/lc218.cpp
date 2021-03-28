#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string.h>
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
class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        if(primeFactors<=3) return 1;
        int two,th;
        th=primeFactors/3;
        two=primeFactors%3;
        if(two==0){
            
        }else if(two==1){
            th--;
            two=2;
        }else{
            two=1;
        }
        ll ans=(qpow(3LL,(ll)th,dev)*qpow(2LL,(ll)two,dev))%dev;
        return ans;

    }
};













int main(){

}


