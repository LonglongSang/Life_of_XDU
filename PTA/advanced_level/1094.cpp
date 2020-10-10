#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
int main(){
	int num,have_son,father,son,son_num;
	
	cin>>num>>have_son;
    if(num==0){
        cout<<0<<" "<<0<<endl;
        return 0;
    }
	vector<int> indegree(num+1,0);
	vector<vector<int>> dp(num+1);
	for(int i=0;i<have_son;i++){
		cin>>father>>son_num;
		for(int j=0;j<son_num;j++){
			cin>>son;
			indegree[son]++;
			dp[father].push_back(son);
		}
	}
	vector<int> level_count(200,0);
	int cur;
	for(int i=1;i<num+1;i++){
		if(indegree[i]==0){
			cur=i;
			break;
		}
	}
	queue<int> Q;
	Q.push(cur);
	Q.push(-1);
	int level=1;
	int level_num=0;
    indegree[cur]=-1;
	while(!Q.empty()){
		cur=Q.front();
        Q.pop();
		
		if(cur==-1 && !Q.empty()){
			level_count[level]=level_num;
			level_num=0;
			level++;
            Q.push(-1);
			continue;
		}else if(cur==-1 && Q.empty()){
            break;
        }
		level_num++;
		for(int i=0;i<dp[cur].size();i++){
			indegree[dp[cur][i]]--;
			if(indegree[dp[cur][i]]==0){
				indegree[dp[cur][i]]=-1;
                Q.push(dp[cur][i]);
			}
		}
	}
    int a=0,b;
	for(int i=1;i<level;i++){
        if(level_count[i]>a){
            a=level_count[i];
            b=i;
        }
    }
    cout<<a<<" "<<b<<endl;
	return 0;
}
