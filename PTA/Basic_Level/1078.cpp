#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
using namespace std;
void to_string(int count,string &output,char last){
	stringstream pipe;
	string temp;
	pipe<<count;
	pipe>>temp;
	output+=temp;
	output+=last;
}
void exchange(int &count,string &output,char a){
	if(count==0){
		output+=a;
	}else{
		for(int i=0;i<count;i++){
			output+=a;
		}
		count=0;
	}
}
int main(){
	char type,last;
	cin>>type;
	getchar();
	string line;
	getline(cin,line);
	string output;
	int count;
	if(type=='C'){
		last=line[0];
		count=1;
		for(int i=1;i<line.length();i++){
			if(line[i]==last){
				count++;
			}else{
				if(count==1){
					output+=last;
				}else{
					to_string(count,output,last);
				}
				last=line[i];
				count=1;
			}
		}
		if(count==1)
			output+=last;
		else
			to_string(count,output,last);
	}else{
		count=0;
		for(int i=0;i<line.length();i++){
			if(line[i]>='0' && line[i]<='9'){
				count=count*10+line[i]-'0';
			}else{
				exchange(count,output,line[i]);
			}
		}
		//exchange(count,output,line[line.length()-1]);
	}
	cout<<output<<endl;
	return 0;
}