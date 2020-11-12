//https://www.lintcode.com/problem/interval-minimum-number/description
#define N 300000
#define ls p<<1
#define rs (p<<1)+1
#define mid (l+r)/2
#define INF 0x7fffffff
int t[N<<2];
void build(int p,int l,int r,vector<int> &A){
    if(l==r){
        t[p]=A[l-1];
        return;
    }
    t[ls]=INF;
    t[rs]=INF;
    build(ls,l,mid,A);
    build(rs,mid+1,r,A);
    t[p]=min(t[ls],t[rs]);
}
int query(int p,int l,int r,int q_l,int q_r){
    if(q_l<=l && r<=q_r){
        return t[p];
    }
    int a=INF,b=INF;
    if(q_l<=mid) a=query(ls,l,mid,q_l,q_r);
    if(q_r>mid) b=query(rs,mid+1,r,q_l,q_r);
    return min(a,b);
}
class Solution {
public:
    /**
     * @param A: An integer array
     * @param queries : An query list
     * @return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        int n=A.size();
        build(1,1,n,A);
        int m=queries.size();
        vector<int> ans(m);
        //return ans;
        for(int i=0;i<m;i++){
            ans[i]=query(1,1,n,queries[i].start+1,queries[i].end+1);
        }
        return ans;
    }
};