#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int row,col,level,thre;
struct infor{
	int x,y,z;
}cur;
queue<infor> Q;
void dfs(int a,int b,int c,vector< vector<vector<int> > > &dp,int &sum){
    sum++;
	dp[a][b][c]=0;
	Q.push({a,b,c});
	while(!Q.empty()){
		cur=Q.front();
		Q.pop();
		for(int i=0;i<6;i++){
			if(cur.x+dir[i][0]>=0 && cur.x+dir[i][0]<level && cur.y+dir[i][1]>=0 && cur.y+dir[i][1]<row && cur.z+dir[i][2]>=0 && cur.z+dir[i][2]<col && dp[cur.x+dir[i][0]][cur.y+dir[i][1]][cur.z+dir[i][2]]==1){
				dp[cur.x+dir[i][0]][cur.y+dir[i][1]][cur.z+dir[i][2]]=0;
				Q.push({cur.x+dir[i][0],cur.y+dir[i][1],cur.z+dir[i][2]});
				sum++;
			}
		}
	}
}
int main(){
	cin>>row>>col>>level>>thre;
	vector< vector<vector<int> > > dp(level,vector< vector<int> > (row,vector<int>(col)));
	for(int i=0;i<level;i++){
		for(int j=0;j<row;j++){
			for(int c=0;c<col;c++){
                cin>>dp[i][j][c];
			}
		}
	}
	int sum=0,temp;
	for(int i=0;i<level;i++){
		for(int j=0;j<row;j++){
			for(int c=0;c<col;c++){
				if(dp[i][j][c]==1){
					int a=0;
					dfs(i,j,c,dp,a);
					if(a>=thre) sum+=a;
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
















