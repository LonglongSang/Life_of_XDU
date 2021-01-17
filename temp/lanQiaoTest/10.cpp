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
#define N 105
int r,c;
int dp[N][N];
bool ok(int i,int j){
    return i>=0 && j>=0 && i<r && j<c;
}
int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>dp[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(i==0 && j==0) continue;
            int add=-120102102;
            for(int a=0;a<=3;a++){
                for(int b=0;b<=3;b++){
                    if(a+b>3 || (a==0 && b==0) || !ok(i-a,j-b)) continue;
                    add=max(add,dp[i-a][j-b]);
                }
            }
            dp[i][j]+=add;
        }
        
    }
    cout<<dp[r-1][c-1]<<endl;

}