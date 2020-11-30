#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
//http://acm.xidian.edu.cn/problem.php?cid=1068&pid=1
using namespace std;
using ll=long long;
int n,k,t;
ll ans,last,v;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",v),last+=v;
    for(int i=0;i<n;i++){
        scanf("%lld",&v);
        ans+=v*last;
    }
    printf("%lld\n",ans);
    return 0;
}


