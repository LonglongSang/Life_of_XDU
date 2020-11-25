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
/*
输入:
n q
输出：
假设x=qqqqqqqqqq(n个q)，y=1000000007
输出x%y
数据范围：
n<=1e18,1<=q<=9
*/

/*
求a在模p下的乘法逆元x
x=qpow(a,p-2,p)
即a的(p-2)次方模p

之后(b/a)%p,就可以转化为(b*x)%p
*/


/*
这道题等价于让我们求111111111111111（n个1）
等于等比数列
((10**n-1)/9)%1000000007
我们先求9关于1000000007的乘法逆元x
x=pow(9,1000000005,1000000007)
转化为(10**n-1)*x%1000000007

*/
int main(){
    scanf("%lld %lld",&n,&q);
    ec=qpow(9,dev-2,dev);
    ll a=qpow(10,n,dev);
    printf("%lld",q*(a-1)*ec%dev);

}