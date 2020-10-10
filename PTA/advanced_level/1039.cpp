#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <map>
#include <algorithm>
using namespace std;
void input(map< string,vector<int> > &name_index){
	int index,num;
	string name;
	scanf("%d %d\n",&index,&num);
	for(int i=0;i<num;i++){
		cin>>name;
		name_index[name].push_back(index);
	}
	scanf("\n");
}
void output(map< string,vector<int> > &name_index,int &n){
	string name;
	map< string,vector<int> >::iterator find;
	for(int i=0;i<n;i++){
		cin>>name;
		find=name_index.find(name);
		cout<<name;
		if(find==name_index.end()){
			cout<<" 0";
		}else{
			sort(find->second.begin(),find->second.end());
			cout<<" "<<find->second.size();
			for(int j=0;j<find->second.size();j++){
				cout<<" "<<find->second[j];
			}
		}
		printf("\n");
	}
}
int main(){
	map< string,vector<int> > name_index;
	int n,m,index,people,count=0;
	scanf("%d %d\n",&n,&m);
	for(int i=0;i<m;i++) input(name_index);
	output(name_index,n);
	return 0;
}


