#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define N 30005
int n,m,t[N];
using ul=unsigned int;
ul val[N],uni[N];
int lowbit(int x){return x&(-x);}
void add(int x){
    for(;x<=n;x+=lowbit(x)) t[x]++;
}
int sum(int x){
    int ans=0;
    for(;x;x-=lowbit(x)) ans+=t[x];
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%u",val+i),uni[i]=val[i];
    sort(uni+1,uni+1+n);
    int rel=unique(uni+1,uni+1+n)-uni-1;
    unordered_map<int,int> mp;
    for(int i=1;i<=rel;i++) mp[uni[i]]=i;
    int j=1,index,ans,num,low,high,mid,k;
    for(int i=0;i<m;i++){
        scanf("%d",&num);
        index=i+1;
        while(j<=num) add(mp[val[j++]]);
        low=1,high=rel;
        while(high>=low){
            mid=(low+high)/2;
            k=sum(mid);
            if(k>=index){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        printf("%u\n",uni[ans]);
    }
    return 0;
}