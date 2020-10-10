#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
	int total,num,temp;
	double price,per;
	cin>>total>>price>>per;
	vector<vector<int>> dp(total,vector<int>(1,-1));
	vector<int> indegree(total,0);
	for(int i=0;i<total;i++){
		cin>>num;
		if(num==0){
			cin>>dp[i][0];
		}else{
			for(int j=0;j<num;j++){
				cin>>temp;
				indegree[temp]++;
				dp[i].push_back(temp);
			}
		}
	}
	int cur;
	for(int i=0;i<total;i++){
		if(indegree[i]==0){
			cur=i;
			break;
		}
	}
	queue<int> Q;
	Q.push(cur);
	Q.push(-1);
	double sum=0;
	while(!Q.empty()){
		cur=Q.front();
		Q.pop();
		if(cur==-1){
			if(Q.empty()) break;
			price=price*(1+per/100);
			Q.push(-1);
            continue;
		}
		if(dp[cur][0]==-1){
            for(int i=1;i<dp[cur].size();i++){
                Q.push(dp[cur][i]);
			}
		}else{
			sum=sum+(double)dp[cur][0]*price;
		}
	}
    printf("%0.1lf\n",sum);
	//cout<<sum<<endl;
	return 0;
}
