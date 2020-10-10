#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <map>
#include<set>
using namespace std;
int main(){
	vector< vector<int> > a(10001);
	for(int i=0;i<10001;i++) a[i].resize(2,0);
	int n,temp;
	cin>>n;
	int count=1;
	for(int i=0;i<n;i++){
		cin>>temp;
		if(a[temp][0]==0){
			a[temp][1]=count;
			count++;
		}
		a[temp][0]++;
	}
	int index=100001;
	count=100001;
	for(int i=0;i<10001;i++){
		if(a[i][0]==1 && a[i][1]<count) index=i,count=a[i][1];
	}
	if(index==100001) cout<<"None"<<endl;
	else cout<<index<<endl;
	return 0;
}


