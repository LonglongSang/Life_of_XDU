#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	string a;
	getline(cin,a);
	reverse(a.begin(),a.end());
	vector<int> temp;
	int sum=0,count=0;
	int total_count=-1;
	for(int i=0;i<a.size()-1;i++){
		if(a[i]!=' '){
			sum+=(a[i]-'0')*(int)pow(10,count);
			count++;
		}else{
			total_count++;
			if(total_count==n){
				cout<<sum<<endl;
				return 0;
			}
			count=0;
			sum=0;
		}
	}
	if(total_count+1==n){
		cout<<sum<<endl;
	}else{
		cout<<"NULL"<<endl;
	}
	return 0;
}



