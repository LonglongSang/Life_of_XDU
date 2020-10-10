#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
using namespace std;
unordered_map<int,vector<int>> hob_peo;
vector<vector<int>> peo_hob;
vector<bool> visited_people;
unordered_map<int,bool> visited_hobby;
vector<int> count_clus;
int num_clus;
void dfs(int index){
	num_clus++;
    //cout<<"vis "<<index<<endl;
	visited_people[index]=true;
	for(auto it:peo_hob[index]){
		if(visited_hobby[it]==false){
			visited_hobby[it]=true;
			for(auto ne:hob_peo[it]){
				if(visited_people[ne]==false){
					dfs(ne);
				}
			}
		}
	}
}
bool cmp(int &a,int &b){
    return a>b;
}
int main(){
	int num,hob_num,temp;
	scanf("%d\n",&num);
	peo_hob.resize(num);
	visited_people.resize(num,false);
	for(int i=0;i<num;i++){
		scanf("%d:",&hob_num);
		for(int j=0;j<hob_num;j++){
			scanf(" %d",&temp);
			//cout<<temp<<endl;
			visited_hobby[temp]=false;
			hob_peo[temp].push_back(i);
			peo_hob[i].push_back(temp);
		}
		scanf("\n");
	}
	for(int i=0;i<num;i++){
		if(visited_people[i]==false){
			num_clus=0;
			dfs(i);
            //cout<<"vis "<<i<<" num is　"<<num_clus<<endl;
			count_clus.push_back(num_clus);
		}
	}
	sort(count_clus.begin(),count_clus.end(),cmp);
    cout<<count_clus.size()<<endl;
	for(int i=0;i<count_clus.size();i++){
		if(i) cout<<" "<<count_clus[i];
		else cout<<count_clus[i];
	}
	return 0;
}
