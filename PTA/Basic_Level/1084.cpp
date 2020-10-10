#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm> //sort
#include <sstream>
using namespace std;
void exchange(vector<char> *second,int a){
	ostringstream h;
	h<<a;
	string ret=h.str();
	for(int i=0;i<ret.length();i++) second->push_back(ret[i]);
}
int main(){
	char d;
	char last;
	int N,count=0;
	cin>>d>>N;
	//cout<<d<<" "<<N<<endl;
	vector<char> small,big;
	vector<char>* first=&small;
	vector<char>* second=&big;
	vector<char>* temp;
	first->push_back(d);
	for(int i=0;i<N-1;i++){
		second->resize(0);
		last=first->at(0);
		count=1;
		for(int j=1;j<first->size();j++){
			if(first->at(j)==last){
				count++;
			}else{
				second->push_back(last);
				exchange(second,count);
				last=first->at(j);
				count=1;
			}
		}
		second->push_back(last);
		exchange(second,count);
		temp=second;
		second=first;
		first=temp;
	}
	for(int i=0;i<first->size();i++) cout<<first->at(i);
	return 0;
}


