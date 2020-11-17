//https://blog.csdn.net/kid1402/article/details/109649815
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <unordered_map>
using namespace std;
int n,m,a,b,cnt,p;
int main(){
    scanf("%d %d\n",&n,&p);
    set<int> dp;
    unordered_map<int,int> vis;
    set<int>::iterator it;
    for(int i=0;i<p;i++) dp.insert(i);
    for(int i=0;i<n;i++){
        if(i) printf(" ");
        scanf("%d",&a);
        
        if(vis.find(a)!=vis.end()){
            printf("%d",vis[a]);
            continue;
        }
        b=a%p;
        it=dp.lower_bound(b);
        if(it==dp.end()) it=dp.begin();
        printf("%d",*it);
        vis[a]=*it;
        dp.erase(*it);
        
    }
    printf("\n");
    return 0;
}