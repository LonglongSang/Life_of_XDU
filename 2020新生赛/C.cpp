#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
//http://acm.xidian.edu.cn/problem.php?cid=1068&pid=2
using namespace std;
using ll=long long;
ll n,k,ans;
int t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        ll a=n%k;
        ll b=n/k;
        printf("%lld\n",((n-b-1)*(b+1)*a+(n-b)*b*(k-a))/2);        
    }
    return 0;
}


