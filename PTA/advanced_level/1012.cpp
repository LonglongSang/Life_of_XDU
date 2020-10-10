#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <set>
#include <map>
using namespace std;
void get_input(map< int,vector<int> > &dp,vector< map<int,int> > &rank){
	int ID,c,m,e,a;
	cin>>ID>>c>>m>>e;
	a=(int)((double)(c+m+e)/3+0.5);
	vector<int> save(4);
	save[0]=a;
	save[1]=c;
	save[2]=m;
	save[3]=e;
	for(int i=0;i<4;i++) rank[i][save[i]]++;
	dp.insert(pair< int,vector<int> >((int)ID,save));
}
int find_rank(int target,map<int,int> &one_rank){
	int count=0;
	map<int,int>::reverse_iterator down;
	for(down=one_rank.rbegin();down!=one_rank.rend();down++){
		if(down->first==target) break;
		count+=down->second;
	}
	return count+1;
}
int main(){
	int num,check,small,index;
	scanf("%d %d\n",&num,&check);
	string p="ACME";
	map< int,vector<int> > dp;
	map< int,vector<int> >::iterator up;
	vector< map<int,int> > rank(4);
	for(int i=0;i<num;i++) get_input(dp,rank);
	vector<int> temp_rank(4);
	for(int i=0;i<check;i++){
		cin>>num;
		up=dp.find(num);
		if(up==dp.end()){
			cout<<"N/A"<<endl;
		}else{
			for(int i=0;i<4;i++) temp_rank[i]=find_rank(up->second[i],rank[i]);
			small=100;
			for(int i=0;i<4;i++){
				if(temp_rank[i]<small){
					small=temp_rank[i];
					index=i;
				} 
			}
			cout<<temp_rank[index]<<" "<<p[index]<<endl;
		}
	}
	return 0;
}
