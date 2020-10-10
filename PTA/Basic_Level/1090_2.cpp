#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
using namespace std;
int main(){
	map< int,map<int,int> > une;
	int m,n;
	cin>>m>>n;
	int a,b;
	while(m!=0){
		cin>>a>>b;
		une[a][b]++;
		une[b][a]++;
		m--;
	}
	vector<int> temp;
	int num,flag=0;
	while(n!=0){
		cin>>num;
		while(num!=0){
			cin>>a;
			temp.push_back(a);
			num--;
		}
		for(int i=0;i<temp.size()-1;i++){
			for(int j=i+1;j<temp.size();j++){
				if(une[temp[i]][temp[j]]){
					flag=1;
					break;
				} 
			}
			if(flag==1) break;
		}
		if(flag==1){
			cout<<"No"<<endl;
		}else{
			cout<<"Yes"<<endl;
		}
		temp.resize(0);
		flag=0;
		n--;
	}
	return 0;
}