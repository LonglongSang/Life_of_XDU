#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define N 200005
using namespace std;
int n,m,cnt,from,to,lef,righ;
int head[100005];
struct node{
    int to;
    int next;
    int lef;
    int righ;
}arr[N];
void add(){
    arr[++cnt].to=to;
    arr[cnt].lef=lef;
    arr[cnt].righ=righ;
    arr[cnt].next=head[from];
    head[from]=cnt;

    arr[++cnt].to=from;
    arr[cnt].lef=lef;
    arr[cnt].righ=righ;
    arr[cnt].next=head[to];
    head[to]=cnt;
}
struct pos{
    int to;
    int cost;
    bool operator < (const pos&b)const{
        return cost>b.cost;
    }
    pos(int _to,int _cost):to(_to),cost(_cost){}
    pos(){}
};
bool vis[100005];
struct range{
    int x;
    int y;
};
vector<range> ans;
void dfs(int cur,int left,int right){
    if(cur==n){
        ans.push_back({left,right});
        return;
    }
    vis[cur]=true;
    //cout<<"vis"<<cur<<endl;
    for(int i=head[cur];i;i=arr[i].next){
        int to=arr[i].to;
        if(vis[to] || arr[i].righ<left || arr[i].lef>right) continue;
        dfs(to,max(arr[i].lef,left),min(arr[i].righ,right));
    }
    vis[cur]=false;
}

int main(){
    scanf("%d %d\n",&n,&m);
    if(n==1){
        cout<<arr[1].righ-arr[1].lef+1<<endl;
        return 0;
    }
    for(int i=0;i<m;i++){
        scanf("%d %d %d %d\n",&from,&to,&lef,&righ);
        add();
    }
    dfs(1,0,1e9);
    sort(ans.begin(),ans.end(),[](const range&a,const range&b){
        return a.x<b.x;
    });
    //cout<<ans.size()<<endl;
    if(ans.size()==0){
        cout<<0<<endl;
        return 0;
    }
    int cnt=1;
    for(int i=1;i<ans.size();i++){
        if(ans[i].x<=ans[cnt-1].y){
            ans[cnt-1].y=max(ans[cnt-1].y,ans[i].y);
        }else{
            ans[cnt++]=ans[i];
        }
    }
    int kk=0;
    for(int i=0;i<cnt;i++){
        kk+=ans[i].y-ans[i].x+1;
    }   
    cout<<kk<<endl;

}