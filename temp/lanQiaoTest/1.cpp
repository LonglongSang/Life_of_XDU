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
int r,c;
#define N 500
int ori[N][N];
int dir[9][2]={-1,-1,-1,0,-1,1,0,-1,0,0,0,1,1,-1,1,0,1,1};
bool ok(int i,int j){
    if(i<0 || j<0 || i>=r || j>=c) return false;
    else return true;
}
int getVal(int i,int j){
    int cnt=0,tot=0;
    for(int k=0;k<9;k++){
        if(!ok(i+dir[k][0],j+dir[k][1])) continue;
        cnt++;
        tot+=ori[i+dir[k][0]][j+dir[k][1]];
    }
    return tot/cnt;
}
int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>ori[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(j) cout<<" ";
            cout<<getVal(i,j);
        }
        cout<<endl;
    }
    return 0;
}