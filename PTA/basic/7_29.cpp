#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	string m;
	string s;
	getline(cin,m);
	getline(cin,s);
	int flag=0;
	int count=0;
	int total=0;
	int m_len=m.size();
	while(m_len>0 && m_len>s.size()){
		for(int i=0;i<m_len-s.size();i++){
			for(int j=0;j<s.size();j++){
				if(m[i+j]==s[j]){
					count++;
				}else{
					break;
				}
			}
			if(count==s.size()){
				for(int j=i+s.size();j<m_len;j++) m[j-s.size()]=m[j];
				m_len=m_len-s.size();
				total++;
			}
			count=0;
		}
		if(total==0) break;
		total=0;
	}
	for(int i=0;i<m_len;i++){
		cout<<m[i];
	}
	return 0;
}