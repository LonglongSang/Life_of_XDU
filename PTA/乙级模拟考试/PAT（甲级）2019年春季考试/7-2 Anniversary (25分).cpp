#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
set<string> alumi;
int main(){
	int num;
	scanf("%d\n",&num);
	string temp;
	for(int i=0;i<num;i++){
		cin>>temp;
		alumi.insert(temp);
		scanf("\n");
	}
	int count=0;
	scanf("%d\n",&num);
	string oldest="370205300000005042";
	string old_guest=oldest;
	for(int i=0;i<num;i++){
		cin>>temp;
		scanf("\n");
		if(alumi.find(temp)!=alumi.end()){
			count++;
			if(temp.substr(6,8)<oldest.substr(6,8)) oldest=temp;
		}else{
			if(temp.substr(6,8)<old_guest.substr(6,8)) old_guest=temp;
		}
	}
	cout<<count<<endl;
	if(count) cout<<oldest<<endl;
	else cout<<old_guest<<endl;
	return 0;
}
