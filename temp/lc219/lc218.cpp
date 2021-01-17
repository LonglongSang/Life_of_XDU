#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct node{
    int index;
    int tot;
}e[10000];
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        heights.push_back(0);
        stack<int> S;
        for(int i=0;i<heights.size();i++){
            while(!S.empty() && heights[i]<heights[S.top()]){
                int top=S.top();
                S.pop();
                ans=max(ans,heights[top]*(S.empty()?i:(i-S.top()-1)));
            }
            S.push(i);
        }   
        return ans;
    }
class Solution {
public:
    int ass(vector<int> &y,vector<int> &x){
        memcpy(y.data(),x.data(),sizeof(int)*x.size());
        sort(y.begin(),y.end(),[&](int&a,int&b){
            return a>b;
        });
        int ans=0;
        for(int i=0;i<y.size() && y[i];i++){
            ans=max(ans,(i+1)*y[i]);
        }
        return ans;
    }
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int col=matrix[0].size(),row=matrix.size();
        vector<int> y(col);
        int ans=0,temp;
        ans=ass(y,matrix[row-1]);
        for(int i=row-2;i>=0;i--){
            for(int j=0;j<col;j++){
                if(matrix[i][j]){
                    matrix[i][j]+=matrix[i+1][j];
                }else{
                    matrix[i][j]=0;
                }
            }
            temp=ass(y,matrix[i]);
            ans=max(temp,ans);
        }
        return ans;
    }
};

int main(){

}