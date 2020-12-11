#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;
int l,r,len;
int path[100];
bool ok(int v){
    if(v==0) return false;
    int cnt=0;
    while(v){
        path[cnt++]=v%10;
        v/=10;
    }
    for(int i=1;i<cnt;i++) if(abs(path[i]-path[i-1])<2) return false;
    return true;
}
int main(){
    scanf("%d %d",&l,&r);
    int ans;
    for(int i=l;i<=r;i++){
        if(ok(i)) ans++;
    }
    cout<<ans<<endl;
}