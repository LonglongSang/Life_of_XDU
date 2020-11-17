#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string.h>
using namespace std;
#define N 1020
using ll=long long;
int n,m,k,head[N],cnt;
ll c,d;
char from[20],to[20];
bool vis[N];//标记某个点是否访问过
int toint(char* s){
    int ans=0;
    while(*s) ans=ans*10+*s-'0',s++;
    return ans; 
}
int getindex(char* s){
    //重新映射垃圾箱和居民区的地址
    //G1-Gm映射为[1,m]
    //居民点1-n映射为[1+m,1+m+n]
    if(s[0]=='G') return toint(s+1);
    else return m+toint(s);
}
struct node{
    //存储边信息
    int to;
    //到达点
    int next;
    //下一个节点
    ll d;
    //距离
}e[20005];
void add(int from,int to){
    //邻接表表示
    e[++cnt].to=to;
    e[cnt].next=head[from];
    e[cnt].d=c;
    head[from]=cnt;

    e[++cnt].to=from;
    e[cnt].next=head[to];
    e[cnt].d=c;
    head[to]=cnt;
}
bool isperson(int i){
    //是否是一个居民点
    return i>m;
}

struct info{
    int i;
    ll d;
};
struct cmp{
    bool operator ()(info&a,info&b){
        return a.d>b.d;
    }
};
ll total,min_dis;
bool bfs(int p){
    memset(vis,0,N);
    priority_queue<info,vector<info>,cmp> Q;
    //利用堆来加快迪杰斯特拉的速度
    Q.push({p,0});
    info cur;
    total=0;
    min_dis=-1;
    while(!Q.empty()){
        cur=Q.top();
        Q.pop();
        if(vis[cur.i]) continue;
        vis[cur.i]=true;
        if(isperson(cur.i)){
            //访问到一个居民点
            if(min_dis==-1) min_dis=cur.d;
            //更新垃圾站p到所有居民点中的最小距离
            total+=cur.d;
            //总距离
            if(cur.d>d) return false;
            //发现p到cur.i的距离超过了题目中d的限制
        }
        for(int i=head[cur.i];i;i=e[i].next){
            //访问与cur.i相邻的点
            if(vis[e[i].to]) continue;
            Q.push({e[i].to,cur.d+e[i].d});
        }
    }
    for(int i=m+1;i<=n+m;i++) if(!vis[i]) return false;
    //检查是否有居民点未被访问到
    return true;
}
int main(){
    scanf("%d %d %d %lld\n",&n,&m,&k,&d);
    for(int i=0;i<k;i++){
        scanf("%s %s %lld\n",from,to,&c);
        add(getindex(from),getindex(to));
        
    }
    int ans_index=-1;//垃圾箱编号答案
    ll ans_min_dis,ans_total;//到所有居民地中的最小距离，到所有居民地总距离
    for(int i=1;i<=m;i++){
        if(!bfs(i)) continue;
        if(ans_index==-1 || min_dis>ans_min_dis || (min_dis==ans_min_dis && total<ans_total) || (min_dis==ans_min_dis && total==ans_total && i<ans_index)){
            ans_index=i;
            ans_min_dis=min_dis;
            ans_total=total;
        }
    }
    if(ans_index==-1){
        printf("No Solution\n");
    }else{
        printf("G%d\n",ans_index);
        printf("%.1lf %.1lf\n",(double)ans_min_dis,(double)ans_total/n);
    }
    return 0;
}
