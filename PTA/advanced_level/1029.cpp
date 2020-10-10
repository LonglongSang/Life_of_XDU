#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;
void input(vector<int> &a){
	int n;
	scanf("%d",&n);
	a.resize(n);
	for(int i=0;i<n;i++) scanf(" %d",&a[i]);
	scanf("\n");
}
int main(){
	vector<int> a,b;
	input(a);
	input(b);
	int a_size=a.size(),b_size=b.size();
	bool right=true;
	int target;
	if((a_size+b_size)%2==0){
		target=(a_size+b_size)/2-1;
	}else{
		target=(a_size+b_size)/2;
	}
	//cout<<target<<"is"<<endl;
	vector<int> c;
	int count=0;
	int i=0,j=0;
	while(1){
		if(i<a_size && j<b_size){
		if(a[i]<b[j]) c.push_back(a[i++]);
		else c.push_back(b[j++]);
		}else if(i==a_size && j<b_size){
			c.push_back(b[j++]);
		}else if(i<a_size && j==b_size){
			c.push_back(a[i++]);
		}else{
			break;
		}
		if(c.size()-1==target) break;
	}
	printf("%d\n",c[target]);
	return 0;
}


