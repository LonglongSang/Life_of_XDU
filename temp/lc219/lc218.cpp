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




struct node{
    int l,w,h,i;
}e[1000];
int cnt;
int dp[1000][100];
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        memset(dp,0,sizeof(dp));
        int n=cuboids.size();
        int a=0;
        cnt=0;
        for(auto&v:cuboids){
            e[cnt++]={min(v[1],v[2]),max(v[1],v[2]),v[0],a};
            e[cnt++]={min(v[0],v[2]),max(v[0],v[2]),v[1],a};
            e[cnt++]={min(v[0],v[1]),max(v[0],v[1]),v[2],a};
            a++;
        }
        sort(e,e+cnt,[&](node&a,node&b){
            return a.l*a.w<b.l*b.w;
        });
        int v;
        for(int i=0;i<cnt;i++){
            v=0;
            for(int j=0;j<i;j++){
                if(e[i].i==e[j].i ||  e[j].w>w[i].w || w[j].l>e[i].l) continue;
                for(int x=0;x<n;x++){
                    for(int y=0;y<n;y++){
                        if(x==y) continue;
                        dp[i][y]=max(dp[i][y],dp[j][x]+e[i].h);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<cnt;i++){
            for(int j=0;j<n;j++){
                ans=max(dp[i][j],ans);
            }
        }
        return ans;

    }
};



int main(){

}