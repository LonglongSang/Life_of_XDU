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


//0 buy 找比我低的
//1 sell 找比我高的

#define N 4000000
#defien M 14
int trie[N][3];
int tot;
int cnt[30000];
//0 
//1
//节点数
void insert(int val,int cur,int step){
    if(step==-1){
        trie[cur][2]++;
        return;
    }
    int t=val>>step&1;
    if(trie[cur][t]==-1){
        trie[cur][t]=++tot;
    }
    insert(val,t[cur][t],step-1);
    trie[cur][2]++;
}
int getVal(int val,int up,int step,int cur,bool limit){
    if(step==-1){
        return trie[cur][2];
    }
    int sum=0;
    if(limit){
        if(trie[cur][0] && (val>>step&1)<=(up>>step&1)) sum+=getVal(val,up,step-1,trie[cur][0],(val>>step&1)<(up>>step&1));
        if(trie[cur][1] && (1^(val>>step&1))<=(up>>step&1)) sum+=getVal(val,up,step-1,trie[cur][1],(1^(val>>step&1))<(up>>step&1));
        return sum;
    }else{
        return trie[cur][2];
    }

}
void init(){
    memset(trie,0,sizeof(int)*(tot+100));
    memset(cnt,0,sizeof(cnt));
    tot=0;
}
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        init();
        //int getVal(int val,int up,int step,int cur,bool limit){
        int ans=0;
        for(auto&e:nums){
            ans+=getVal(e,low,M,0,true)+getVal(e,high,M,0,true)+cnt[e^low];
            insert(e,0,M);
            cnt[e]++;
            //void insert(int val,int cur,int step){
        }
        return ans;
    }
};


int main(){

}


