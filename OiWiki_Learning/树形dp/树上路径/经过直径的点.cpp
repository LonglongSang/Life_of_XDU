//https://ac.nowcoder.com/acm/contest/9753/C
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;


/*
思想，我们要选出从cur出发的三条路径分别标记为first，second，third

第一部分
（求first，second）dfs1实现
    对于一颗树中的节点cur，他有一个父亲节点fa（可能不存在）
    对于以cur做为根的子树（不包含向fa扩散的那一部分），
    能找到的以cur作为起点的最长路径为first(可能不存在，就为0)，同时标记这条最长路径的第二个节点为son[cur]
    次长路径长度为second(可能不存在，就为0)

第二部分
（求third）dfs2实现
    third指的是以cur作为根，包含fa这一枝的这个子树，从cur出发的最长路径
    如son[fa]==cur
    那么
    third[cur]=max(second[fa],third[fa])+1;
    否则的话
    third[cur]=max(first[fa],third[fa])+1;

这样对于一个节点cur，就可以求出first[cur],second[cur],third[cur];
那么对于经过节点cur的最长径（径定义为由一个叶子到另一个叶子的路径，直径就是最长径）的长度为val=max(third[cur]+second[cur],second[cur]+third[cur],first[cur]+third[cur]);
那么我们就能找到有多少个点经过直径，只要对于cur's val=直径，那么这个点就经过直径
*/


//start
#define N 100005
int head[N],first[N],second[N],son[N],cnt,third[N];
struct node{
    int to;
    int next;
}e[N*2];
void add(int from,int to){
    e[++cnt].to=to;
    e[cnt].next=head[from];
    head[from]=cnt;

    e[++cnt].to=from;
    e[cnt].next=head[to];
    head[to]=cnt;
}


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param n int整型 节点个数
     * @param u int整型vector 
     * @param v int整型vector 
     * @return int整型
     */
    void inti(int n){
        memset(head+1,0,sizeof(int)*n);
        memset(first+1,0,sizeof(int)*n);
        memset(second+1,0,sizeof(int)*n);
        memset(son+1,0,sizeof(int)*n);
        memset(third+1,0,sizeof(int)*n);
        cnt=0;
    }
    void dfs1(int cur,int fa){
        int to,v;
        for(int i=head[cur];i;i=e[i].next){
            to=e[i].to;
            if(to==fa) continue;
            dfs1(to,cur);
            if(first[to]+1>first[cur]){
                second[cur]=first[cur];
                first[cur]=first[to]+1;
                son[cur]=to;
            }else if(first[to]+1>second[cur]){
                second[cur]=first[to]+1;
            }
        }
    }
    void dfs2(int cur,int fa){
        int to;
        for(int i=head[cur];i;i=e[i].next){
            to=e[i].to;
            if(to==fa) continue;
            if(son[cur]!=to){
                third[to]=max(third[to],first[cur]+1);
            }else{
                third[to]=max(third[to],second[cur]+1);
            }
            dfs2(to,cur);
        }
    }
    int PointsOnDiameter(int n, vector<int>& u, vector<int>& v) {
        // write code here
        inti(n);
        for(int i=0;i<n-1;i++) add(u[i],v[i]);
        dfs1(1,-1);
        dfs2(1,-1);
        int diameter=0,ans=0,val;
        for(int i=1;i<=n;i++){
            val=max({first[i]+second[i],first[i]+third[i],second[i],third[i]});
            cout<<val<<endl;
            if(val>diameter){
                diameter=val;
                ans=1;
            }else if(val==diameter){
                ans++;
            }
        }
        return ans;
    }
};

//end










int main(){
    vector<int> u={1,2};
    vector<int> v={2,3};
    int n=3;
    Solution a;
    cout<<a.PointsOnDiameter(n,u,v)<<endl;
}