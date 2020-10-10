#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
using namespace std;
int to_int(string a){
	istringstream h(a);
	int aa;
	h>>aa;
	return aa;
}
int main(){
	int n,already=0;
	vector<int> Madle(10000,-1);
	cin>>n;
	int count=1;
	string temp_string;
	int temp_int;
	while(n!=0){
		cin>>temp_string;
		temp_int=to_int(temp_string);
		Madle[temp_int]=count;
		count++;
		n--;
	}
	cin>>n;
	while(n!=0){
		cin>>temp_string;
		temp_int=to_int(temp_string);
		//cout<<Madle[temp_int]<<endl;
		if(Madle[temp_int]<=1){
			if(Madle[temp_int]==0) cout<<temp_string<<": Checked"<<endl;
			if(Madle[temp_int]==-1) cout<<temp_string<<": Are you kidding?"<<endl;
			if(Madle[temp_int]==1){
				cout<<temp_string<<": Mystery Award"<<endl;
				Madle[temp_int]=0;
			}
		}else{
			for(int i=2;i<=(int)sqrt(Madle[temp_int]);i++){
				if(Madle[temp_int]%i==0){
					already=1;
					break;
				}
			}
			if(already==1){
				cout<<temp_string<<": Chocolate"<<endl;
			}else{
				cout<<temp_string<<": Minion"<<endl;
			}
			Madle[temp_int]=0;
			already=0;
		}
		n--;
	}
	return 0;
}





