#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdlib.h>
#include <map>
using namespace std;
bool is_exist(string b,vector<string> a){
	for(int i=0;i<a.size();i++){
		if(b==a[i]) return true;
	}
	return false;
}
int main(){
	vector<string> une;
	vector<string> how;
	int m,n;
	cin>>m>>n;
	string a,b;
	while(m!=0){
		cin>>a>>b;
		how.push_back(a);
		une.push_back(a+b);
		m--;
	}
	vector<string> temp;
	int num,flag=0;
	while(n!=0){
		//cout<<"n is "<<n<<endl;
		cin>>num;
		while(num!=0){
			cin>>a;
			if(is_exist(a,how)){
				temp.push_back(a);			
			}
			num--;
		}
		//cout<<"size is "<<temp.size()<<endl;
		if(temp.size()>1){
			for(int i=0;i<temp.size()-1;i++){
				for(int j=i+1;j<temp.size();j++){
					for(int c=0;c<une.size();c++){
						if(temp[i]+temp[j]==une[c] || temp[j]+temp[i]==une[c]){
							flag=1;
							break;
						}
					}
					if(flag==1) break;
				}
				if(flag==1) break;
			}
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
/*
int main(){
	map< string,map<string,int> > une;
	int m,n;
	cin>>m>>n;
	string a,b;
	while(m!=0){
		cin>>a>>b;
		une[a][b]++;
		une[b][a]++;
		m--;
	}
	vector<string> temp;
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
*/