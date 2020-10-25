#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define N 100005
using namespace std;

typedef pair<int,int> pii;

int n,m,cnt,from,to,lower,upper;
int mp[N<<1],pre[N];
int tot;
int pos(int val){return lower_bound(mp,mp+tot,val)-mp;}
struct infor{
    int from,to,lower,upper;
}arr[N];
vector<pii> edge[N<<3];
void build(int index,int left,int right,int lower,int upper,int from,int to){
    if(left>right) return;
    if(lower<=left && right<=upper){
        edge[index].push_back({from,to});
        return;
    }
    int mid=(left+right)/2;
    //左[left,mid]
    //右(mid,right]
    if(lower<mid) build(index*2,left,mid,lower,upper,from,to);
    if(upper>mid) build(index*2+1,mid,right,lower,upper,from,to);
}
int find1(int a){
    if(a==pre[a]) return a;
    else return find1(pre[a]);
}
int find(int x) { 
    //if(x==pre[x]) return x;
    //else return pre[x]=find(pre[x]);
    return x == pre[x] ? x : find(pre[x]); 
}
void merge1(vector<int>& now,int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(b>a) swap(a,b);
    pre[a]=b;
    now.push_back(a);
}
void merge(vector<int>& now, int x, int y) {//按秩合并
	x = find(x);
	y = find(y);
	if (x == y)return;
	//if (rk[x] < rk[y])swap(x, y);
    if(x>y) swap(x,y);
	pre[y] = x;
	//if (rk[x] == rk[y])rk[x]++;
	now.push_back(y);
}
void update(vector<int>& now,int index){
    for(auto& e:edge[index]){
        merge(now,e.first,e.second);
    }
}
void cancel(vector<int>&now){
    for(auto& e:now) pre[e]=e;
}
int ans;
void dfs1(int index,int left,int right){
    //cout<<index<<" "<<left<<" "<<right<<endl;
    //if(left>right) return;
    vector<int> now;
    update(now,index);
    if(find(1)==find(n)){
        ans+=mp[right]-mp[left]+1;
        cancel(now);
        return;
    }
    if(left==right){
        cancel(now);
        return;
    }
    int mid=(left+right)/2;
    dfs1(index*2,left,mid);
    dfs1(index*2+1,mid+1,right);
    cancel(now);
}
void dfs(int index,int left,int right){
    vector<int> now;
    update(now,index);
    if(left==right-1){
        if(find(1)==find(n)){
            ans+=mp[right]-mp[left];
        }
        cancel(now);
        return;
    }
    int mid=(left+right)/2;
    dfs(index*2,left,mid);
    dfs(index*2+1,mid,right);
    cancel(now);
}
void set_pre(){
    for(int i=1;i<=n;i++) pre[i]=i;
}
int main(){
    scanf("%d%d",&n,&m);
    set_pre();
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d",&arr[i].from,&arr[i].to,&arr[i].lower,&arr[i].upper);
        mp[tot++]=arr[i].lower;
        mp[tot++]=arr[i].upper+1;
    }
    sort(mp,mp+tot);
    tot=unique(mp,mp+tot)-mp;
    for(int i=0;i<m;i++){
        build(1,0,tot,pos(arr[i].lower),pos(arr[i].upper),arr[i].from,arr[i].to);
    }
    dfs(1,0,tot);
    cout<<ans<<endl;
}