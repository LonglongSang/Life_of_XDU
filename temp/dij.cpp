#include <stdio.h>
#include <iostream>
#include <queue>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <string.h>
#include <stack>
class Solution
{
public:
    Solution(){

    }
    int r,c;
    static int dir[4][2];
    static int mp[4];
    static short pre[1000][1000];
    void retVal(int &x,int &y,int &val){
        x=val/c;
        y=val%c;
    }
    int getVal(int &x,int& y){
        return x*c+y;
    }
    void getPath(std::vector<std::vector<int>>& grid,int staX,int staY,int endX,int endY)
    {
        
        memset(pre,-1,sizeof(pre));
        if(grid.size()==0 || grid[0].size()==0) return;
        if(staX==endX && staY==endY) return;
        std::queue<int> Q;
        r=grid.size(),c=grid[0].size();
        Q.push(getVal(staX,staY));
        int x,y,cur,x1,y1;
        pre[staX][staY]=5;
        while(!Q.empty())
        {
            cur=Q.front();
            Q.pop();
            retVal(x1,y1,cur);
            for(int i=0;i<4;i++)
            {
                x=dir[i][0]+x1,y=dir[i][1]+y1;
                if(x<0 || y<0 || x>=r || y>=c || grid[x][y]==1 || pre[x][y]!=-1) continue;
                pre[x][y]=mp[i];
                Q.push(getVal(x,y));
                if(x==endX && y==endY) break;
            }
        }
        if(pre[endX][endY]==-1){
            std::cout<<"no path from ("<<staX<<", "<<staY<<") to ("<<endX<<", "<<endY<<")"<<std::endl;
            return;
        }else{
            std::cout<<"path from ("<<staX<<", "<<staY<<") to ("<<endX<<", "<<endY<<") showing below"<<std::endl;
        }
        std::stack<int> S;
        S.push(getVal(endX,endY));
        while(1){
            cur=S.top();
            retVal(x1,y1,cur);
            if(pre[x1][y1]==5) break;
            x=x1,y=y1;
            x+=dir[pre[x1][y1]][0];
            y+=dir[pre[x1][y1]][1];
            S.push(getVal(x,y));
        }
        while(!S.empty()){
            cur=S.top();
            S.pop();
            retVal(x,y,cur);
            printf("(%d,%d)->",x,y);
        }
        putchar('\n');
    }
    void generateGrid(std::vector<std::vector<int>>& grid,int r,int c)
    {
        grid.resize(r,std::vector<int>(c));
        srand(time(0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                grid[i][j]=(rand()%10)<=6?0:1;
            }
        }
    }
    void showGrid(std::vector<std::vector<int>>& grid)
    {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(j) putchar(' ');
                fprintf(stdout,"%d",grid[i][j]);
            }
            putchar('\n');
        }
    }
};
int Solution::dir[4][2]={0,-1,0,1,-1,0,1,0};
int Solution::mp[4]={1,0,3,2};
short Solution::pre[1000][1000];
int main(int argc,char* argv[]){
    Solution s;
    std::vector<std::vector<int>> grid;
    s.generateGrid(grid,10,10);
    s.showGrid(grid);
    grid[0][0]=0;


    //找到0,0到4,5的路径
    s.getPath(grid,0,0,4,5);

    return 0;
}