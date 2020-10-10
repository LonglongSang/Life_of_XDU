#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
void pr(string &word,vector< vector<string> > &letter){
	for(int i=0;i<7;i++){
		for(int j=0;j<word.length();j++){
			if(j) cout<<" "<<letter[word[j]-'A'][i];
			else cout<<letter[word[j]-'A'][i];
		}
		printf("\n");
	}
}
int main(){
	vector< vector<string> > letter(26,vector<string>(7));
	for(int i=0;i<26;i++){
		for(int j=0;j<7;j++){
			getline(cin,letter[i][j]);
			scanf("\n");
		}
	}
	string line;
	string temp;
	getline(cin,line);
	vector<string> ret;
	for(int i=0;i<line.length();i++){
		if(isupper(line[i])){
			temp.push_back(line[i]);
		}else{
			if(temp.size()!=0) ret.push_back(temp);
			temp.resize(0);
		}
	}
	if(temp.size()!=0) ret.push_back(temp);
	for(int i=0;i<ret.size();i++){
		if(i){
			printf("\n");
			pr(ret[i],letter);
		}else{
			pr(ret[i],letter);
		}
	}
	return 0;
}

