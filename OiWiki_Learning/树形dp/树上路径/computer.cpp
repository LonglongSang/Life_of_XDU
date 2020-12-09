//http://acm.hdu.edu.cn/showproblem.php?pid=2196
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;


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
    void dfs1(int cur,int last){
        int to,v;
        for(int i=head[cur];i;i=e[i].next){
            to=e[i].to;
            if(to==last) continue;
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
    void dfs2(int cur,int last){
        int to;
        for(int i=head[cur];i;i=e[i].next){
            to=e[i].to;
            if(to==last) continue;
            if(son[cur]!=to){
                third[to]=max(first[cur],third[cur])+1;
            }else{
                third[to]=max(second[cur],third[cur])+1;
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
            val=max({first[i]+second[i],first[i]+third[i],second[i]+third[i]});
            //cout<<first[i]<<" "<<son[i]<<" "<<second[i]<<" "<<third[i]<<" "<<val<<endl;
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











int main(){
    vector<int> u={1,2};
    vector<int> v={2,3};
    int n=3;
    Solution a;
    cout<<a.PointsOnDiameter(n,u,v)<<endl;
}