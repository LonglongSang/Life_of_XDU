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
#define N 5005
struct node{
    int to;
    int t;
};
int T,n,m,from,to,t;
vector<node> e[N];//to，cost
int dfs(int cur,int t_tot){
    //当前访问点，vis已经访问的点数，t_tot已经花费的时间
    if(t_tot>T) return 0;
    if(cur==n) return 1;
    int ans=0,temp;
    for(auto&next:e[cur]){
        temp=dfs(next.to,t_tot+next.t);
        ans=max(ans,temp);
    }
    return ans?ans+1:0;
}
int main(){
    scanf("%d %d %d",&n,&m,&T);
    getchar();
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&from,&to,&t);
        getchar();
        e[from].push_back({to,t});
    }
    printf("%d\n",dfs(1,0));

}


