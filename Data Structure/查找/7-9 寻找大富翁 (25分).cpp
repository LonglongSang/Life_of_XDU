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
int n,m,v,cnt,temp[10];
int main(){
    priority_queue<int,vector<int>,greater<int>> Q;
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&v);
        if(Q.size()<m){
            Q.push(v);
        }else if(v>Q.top()){
            Q.pop();
            Q.push(v);
        }
    }
    while(!Q.empty()) temp[cnt++]=Q.top(),Q.pop();
    printf("%d",temp[cnt-1]);
    for(int i=cnt-2;i>=0;i--){
        printf(" %d",temp[i]);
    }
    printf("\n");
}