#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm> //sort
#include <set>
using namespace std;
int main(){
	string good,bad;
	cin>>good;
	cin>>bad;
	set<char> dp;
	int j=0;
	for(int i=0;i<good.size();i++){
		if(good[i]==bad[j]){
			j++;
		}else{
			if(good[i]>='a' && good[i]<='z') good[i]=good[i]-'a'+'A';
			if(dp.find(good[i])==dp.end()){
				cout<<good[i];
				dp.insert(good[i]);
			}
		}
	}
	return 0;
}

