#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <unordered_map>
using namespace std;
struct infor{
	string name;
	int grade;
};
bool cmp(const infor &a, const infor &b){
	return a.grade != b.grade ? a.grade > b.grade : a.name < b.name;
}
int main(){
	int n,m,order;
	cin >> n >> m;
	vector<infor> dp(n);
	string type;
	for(int i = 0; i < n; i++) cin >> dp[i].name >> dp[i].grade;
	for(int i = 0; i < m; i++) {
		cin >> order >> type;
		vector<infor> temp;
		int cnt = 0, sum = 0;
		printf("Case %d: %d %s\n", i+1, order, type.c_str());
		if(order == 1){
			for(int j = 0; j < n; j++)
				if(dp[j].name[0] == type[0]) temp.push_back(dp[j]);
		}else if(order == 2){

			for(int j = 0; j < n; j++){
				if(dp[j].name.substr(1,3) == type){
					sum+=dp[j].grade;
					cnt++;
				}	
			}
			if (cnt != 0) printf("%d %d\n", cnt, sum);
		}else if(order == 3){
			unordered_map<string ,int> save;
			for(int j = 0; j < n; j++) if( dp[j].name.substr(4,6) == type) save[dp[j].name.substr(1,3)]++;
			for(auto it : save) temp.push_back({it.first, it.second});
		}
		sort(temp.begin(), temp.end(),cmp);
		for (int j = 0; j < temp.size(); j++) printf("%s %d\n", temp[j].name.c_str(), temp[j].grade);
		if (((order == 1 || order == 3) && temp.size() == 0) || (order == 2 && cnt == 0)) printf("NA\n");
	}
	return 0;
}



