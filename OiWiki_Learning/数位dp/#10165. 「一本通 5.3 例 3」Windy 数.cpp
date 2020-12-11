#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
//#include <math.h>
#include <cmath>
using namespace std;
int l,r,len;
int dp[20][20];
int path[20];
int cnt;
int inf=0x3f3f3f3f;
int dfs(int step,int last,bool typ,int sum){
    if(step==cnt){
        return 1;
        //if(sum!=0) return 1;
        //else return 0;
    }
    if(typ==false && sum!=0 && dp[step][last]!=inf){
        //cout<<"# "<<typ<<" "<<step<<" "<<last<<" "<<dp[step][last]<<endl;
        return dp[step][last];
    }

    int tot=0,up=(typ?path[step]:9);
    for(int i=0;i<=up;i++){
        if(sum==0 || abs(i-last)>=2) tot+=dfs(step+1,i,(typ && (i==up)),sum*10+i);
    }
    if(!typ && sum==0) dp[step][last]=tot;
    return tot;
}
int getpath(int v){
    cnt=0;
    while(v){
        path[cnt++]=v%10;
        v/=10;
    }
    reverse(path,path+cnt);
    int ret=dfs(0,0,true,0);
    return ret;
}


int main(){
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++) dp[i][j]=inf;
    }
    scanf("%d %d",&l,&r);
    //cout<<getpath(209)<<" "<<getpath(210)<<" "<<getpath(240)<<endl;
    cout<<getpath(209)<<endl;
    cout<<getpath(210)<<endl;
    cout<<getpath(r)-getpath(l-1)<<endl;
    //
    return 0;
}