	#include <iostream>
	#include <cstdlib>
	#include <string>
	#include <vector>
	#include <math.h>
	#include <stdio.h>//printf
	#include <map>
	using namespace std;
	int main(){
		string m="10X98765432";
		int weight[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
		string input;
		int n,count=0,sum=0;
		cin>>n;
		scanf("\n");
		vector<string> problem;
		while(n!=0){
			getline(cin,input);
			//cout<<input<<endl;
			for(int i=0;i<17;i++){
				sum+=(input[i]-'0')*weight[i];
			}
			//cout<<sum<<endl;
			//cout<<m[sum%11]<<"-"<<input[17]<<endl;
			if(m[sum%11]!=input[17]){
				count++;
				problem.push_back(input);
			}
			input.resize(0);
			sum=0;
			n--;
		}
		if(count==0){
			cout<<"All passed"<<endl;
		}else{
			for(int i=0;i<count;i++){
				cout<<problem[i]<<endl;
			}
		}
		return 0;
	}
