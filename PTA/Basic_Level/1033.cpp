#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
#include <set>
using namespace std;
int main(){
	string bad,good;
	getline(cin,bad);
	getline(cin,good);
	set<char> dp;
	for(int i=0;i<bad.size();i++){
		dp.insert(bad[i]);	
		if((bad[i]>='a' && bad[i]<='z') || (bad[i]>='A' && bad[i]<='Z')){
			dp.insert(bad[i]-'a'+'A');
			dp.insert(bad[i]-'A'+'a');
		}else if(bad[i]=='+'){
			for(char j='A';j<='Z';j++) dp.insert(j);
		}
	}
	for(int i=0;i<good.size();i++) if(dp.find(good[i])==dp.end()) cout<<good[i];
	cout<<endl;
	return 0;
}
