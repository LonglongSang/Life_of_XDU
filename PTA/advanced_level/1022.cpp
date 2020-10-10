#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <set>
#include <unordered_map>
using namespace std;
void for_keywords(vector< unordered_map<string,set<int> > > &information,int j,string &name,int &num){
	int last=0;
	for(int i=0;i<name.length();i++){
		if(name[i]==' '){
			if(i!=last) information[j][name.substr(last,i-last)].insert(num);
			last=i+1;
		}
	}
	if(name[name.length()-1]!=' ') information[j][name.substr(last,name.length()-last)].insert(num);
}
void input(vector< unordered_map<string,set<int> > > &information){
	int num;
	scanf("%d\n",&num);
	string name;
	for(int i=0;i<5;i++){
		getline(cin,name);
		if(i!=2) information[i][name].insert(num);
		if(i==2) for_keywords(information,i,name,num);
	}
}
void output(vector< unordered_map<string,set<int> > > &information){
	int n;
	string line;
	scanf("%d: ",&n);
	getline(cin,line);
	n--;
	unordered_map<string,set<int> >::iterator map_pointer;
	set<int>::iterator set_pointer;
	map_pointer=information[n].find(line);
	printf("%d: ",n+1);
	cout<<line<<endl;
	if(map_pointer!=information[n].end()){
		for(set_pointer=map_pointer->second.begin();set_pointer!=map_pointer->second.end();set_pointer++){
			printf("%.7d\n",*set_pointer);
		}
	}else{
		printf("Not Found\n");
	}
}
int main(){
	int m;
	vector< unordered_map<string,set<int> > > information(5);
	scanf("%d\n",&m);
	for(int i=0;i<m;i++) input(information);
	scanf("%d\n",&m);
	for(int i=0;i<m;i++) output(information);
	return 0;
}
