#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#define N 200005
using namespace std;



class Solution {
public:
    struct node{
        int x,y,val;
    };
    struct pos{
        int cnt,val;
    };
    struct axis{
        int x,y;
    };
    static vector<pos> row;
    static vector<pos> col;
    struct cmp{
        bool operator() (const node&a,const node&b)const{
            int c=max(row[a.x].cnt,col[a.y].cnt);
            int d=max(row[a.x].cnt,col[a.y].cnt);
            return c<d;
        }
    };
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
       int r=matrix.size(),c=matrix[0].size();
       pos p={0,-1000000005};
       row.resize(r,p);
       col.resize(c,p);
       vector<node> temp(r*c);
       int cnt=0;
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
               temp[cnt++]={i,j,matrix[i][j]};
           }
       }
       sort(temp.begin(),temp.end(),[&](const node&a,const node&b){
           return a.val<b.val; 
       });
       vector<vector<int>> ans(r,vector<int>(c));
       priority_queue<node,vector<node>,cmp> q;
       cnt=0;
        while(cnt<r*c){
            node tar={temp[cnt].val,0};
            int up=upper_bound(temp.begin()+cnt,temp.end(),tar)-temp.begin();
            for(int i=cnt;i<up;i++) q.push({temp[i].x,temp[i].y});
            while(!q.empty()){
                node cur=q.top();
                q.pop();
                    row[cur.x].val=cur.val;
                    col[cur.y].val=cur.val;
                    int cnt=max(row[cur.x].cnt,col[cur.x].cnt);
                    ans[cur.x][cur.y]=++cnt;
                    row[cur.x].cnt=cnt;
                    col[cur.x].cnt=cnt;
            }
            cnt=up;
        }
       return ans;
    }
};















class Solution1 {
public:
    struct node{
        int x,y,val;
    };
    struct pos{
        int cnt,val;
    };
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
       int r=matrix.size(),c=matrix[0].size();
       pos p={0,-100000};
       vector<pos> row(r,p);
       vector<pos> col(c,p);
       vector<node> temp(r*c);
       int cnt=0;
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
               temp[cnt++]={i,j,matrix[i][j]};
           }
       }
       sort(temp.begin(),temp.end(),[&](const node&a,const node&b){
           return a.val<b.val; 
       });
       vector<vector<int>> ans(r,vector<int>(c));
       for(int i=0;i<r*c;i++){
           if(row[temp[i].x].cnt>col[temp[i].y].cnt){
               col[temp[i].y].cnt=row[temp[i].x].cnt;
               col[temp[i].y].val=max(col[temp[i].y].val,row[temp[i].x].val);
               row[temp[i].x].val=col[temp[i].y].val;
           }else{
               row[temp[i].x].cnt=col[temp[i].y].cnt;
               col[temp[i].y].val=max(col[temp[i].y].val,row[temp[i].x].val);
               row[temp[i].x].val=col[temp[i].y].val;
           }
           if(temp[i].val>row[temp[i].x].val){
               row[temp[i].x].val=temp[i].val;
               ans[temp[i].x][temp[i].y]=++row[temp[i].x].cnt;
           }else if(temp[i].val==row[temp[i].x].val){
               ans[temp[i].x][temp[i].y]=row[temp[i].x].cnt;
           }

       }
       return ans;
    }
};
int main(){

}