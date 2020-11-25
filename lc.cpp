#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,cnt[100000],v,ans,path[100],total;
bool good;
void dfs(int total,int i,int step){
    //访问存在cnt[i]中的币值
    if(total==0){
        good=true;
        ans=step;
        return;
    }
    if(i==total) return;
    path[step]=cnt[i];
    if(good) dfs(total-cnt[i],i+1,step+1);//选这一张币值
    if(good) dfs(total,i+1,step);//不选这一张币值
}
int main(){
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",cnt+total);
        if(cnt[total]<=m) total++;
    }
    sort(cnt,cnt+total);
    dfs(m,0,0);
    if(ans==0){
        printf("No Solution\n");
    }else{
        printf("%d",path[0]);
        for(int i=1;i<ans;i++) printf(" %d",path[i]);
        printf("\n");
    }
}


