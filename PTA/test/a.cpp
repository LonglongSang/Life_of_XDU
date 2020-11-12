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
#define N 100001
int n,m,q;
using p=pair<int,int>;
p arr[N];
int v[3*N];
int query[N];
int cnt;
int sum[3*N];
int main()
{
    scanf("%d %d %d\n",&n,&m,&q);
    for(int i=0;i<m;i++){
        scanf("%d %d\n",&arr[i].first,&arr[i].second);
        v[cnt++]=arr[i].first;
        v[cnt++]=arr[i].second;
    }
    for(int i=0;i<q;i++){
        scanf("%d",&query[i]);
        v[cnt++]=query[i];
    }
    sort(v,v+cnt);
    cnt=unique(v,v+cnt)-v;
    unordered_map<int,int> mp;
    for(int i=0;i<cnt;i++){
        mp[v[i]]=i;
    }
    for(int i=0;i<m;i++){
        sum[mp[arr[i].first]]++;
        sum[mp[arr[i].second]+1]--;
    }
    int upper=mp[v[cnt-1]];
    int add=0;
    for(int i=0;i<=upper;i++){
        add+=sum[i];
        sum[i]=add;
    }
    for(int i=0;i<q;i++){
        printf("%d\n",sum[mp[query[i]]]);
    }
    return 0;
}
