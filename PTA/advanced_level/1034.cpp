#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string,unordered_map<string,int> > dp;
unordered_map<string,int> boss;
unordered_map<string,bool> visited;
string my_boss;
void dfs(string name,int &gang_count,int &gang_max,int &calling_time,string &my_boss){
	gang_count++;
	visited[name]=true;
	int sum=0;
	for(auto it:dp[name]){
		sum+=it.second;
		if(visited[it.first]==false) dfs(it.first,gang_count,gang_max,calling_time,my_boss);
	}
	calling_time+=sum;
	if(sum>gang_max){
		gang_max=sum;
		my_boss=name;
	}
   cout<<name<<" total time "<<sum<<endl;
}
int main(){
	int line,shre,time;
	cin>>line>>shre;
    string name1,name2;
	for(int i=0;i<line;i++){
        cin>>name1>>name2>>time;
        dp[name1][name2]+=time;
        dp[name2][name1]+=time;
        visited[name1]=false;
        visited[name2]=false;
    }
    for(auto it:dp){
		if(visited[it.first]==false){
			int gang_count=0;
			int gang_max=0;
			int calling_time=0;
            string my_boss;
			dfs(it.first,gang_count,gang_max,calling_time,my_boss);
            cout<<"total calling time "<<calling_time<<endl;
			if(gang_count>2 && calling_time/2>shre) boss[my_boss]=gang_count;
		}
	}
	cout<<boss.size()<<endl;
	for(auto it:boss) cout<<it.first<<" "<<it.second<<endl;
	return 0;
}