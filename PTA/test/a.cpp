#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <unordered_map>
using namespace std;







#define mid (l+r)/2
int dp[10001];
class Solution {
public:
    /**
     * @param A: An integer array
     * @param queries: The query list
     * @return: The number of element in the array that are smaller that the given integer
     */
    struct node{
        node* left=NULL;
        node* right=NULL;
        int l,r,tag=0;
        int cnt=0;
        node(int _l,int _r): l(_l),r(_r){}
    };
    node* add(node* root,int l,int r,int q_l,int q_r,int k){
        if(!root) root=new node(l,r);
        if(q_l<=l && r<=q_r){
            root->cnt+=k;
            return;
        }
        if(q_l<=mid) root->left=add(root->left,l,mid,q_l,q_r,k);
        if(q_r>mid) root->right=add(root->right,mid+1,r,q_l,q_r,k);
        root->cnt=(root->left?root->left->cnt:0)+(root->right?root->right->cnt:0);
        return root;
    }
    int query(node* root,int l,int r,int q_l,int q_r){
        if(q_l<=l && r<=q_r) return root->cnt;
        int ans=0;
        if(q_l<=mid && root->left) ans+=query(root->left,l,mid,q_l,q_r);
        if(q_r>mid && root->right) ans+=query(root->right,mid+1,q_l,q_r);
        return ans;
    }

    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        node* root=NULL;
        memset(dp,0,40004);
        for(auto &v:A){
            dp[v]++;
        }
        vector<int> ans(queries.size());
        for(int i=0;i<10001;i++) if(dp[i]) root=add(root,0,10000,i,i,dp[i]);
        for(int i=0;i<queries.size();i++){
            if(queries[i]==0) ans[i]=0;
            else ans[i]=query(root,0,10000,0,queries[i]-1);
        }
        return ans;
    }
};










int main()
{

    return 0;
}
