#include <stdio.h>
#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
int n,a;
map<int,int> dp;

int main(){
    freopen("G:\\Life_of_XDU\\PTA\\test\\data","r+",stdin);
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        getchar();
        dp[a]++;
    }
    long long ans=0;
    map<int,int>::iterator it;
    while(dp.size()){
        int a=dp.begin()->first;//取现存元素最小的那个
        dp[a]--;//把a的数量减一
        if(dp[a]==0) dp.erase(a);//如果最小元素a减一后已经没有，就把他删除
        it=dp.upper_bound(a);//寻找第一个大于a的元素在dp中的地址
        if(it==dp.end()){//如果不存在，说明只剩下这一种元素，如7,7,7,7,7,7,dp[7]=6
            ans+=a;
            if(dp.count(a)) ans+=a*dp[a]; 
            break;//直接终止循环
        }else{//如果存在大于a的元素
            ans+=it->first;//本次的消耗
            //it->first是第一个大于a元素的值,it->second=dp[it->first]
            it->second--;//将其计数减1
            if(it->second==0) dp.erase(it->first);//如果计数为0就删除
        }
    }
    cout<<ans<<endl;
    return 0;
} 