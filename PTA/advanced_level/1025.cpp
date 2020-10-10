#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <map>
using namespace std;
void input(map< int,map<string,int> > &dp,int count){
	string num;
	int grade;
	cin>>num>>grade;
	scanf("\n");
	dp[grade][num]=count;
}
int main(){
	int n,m,total=0,sum=0,a=0;
	scanf("%d\n",&n);
	map< int,map<string,int> > dp;
	for(int i=0;i<n;i++){
		scanf("%d\n",&m);
		total+=m;
		for(int j=0;j<m;j++) input(dp,i);
	}
	map< int,map<string,int> >::reverse_iterator down;
	map<string,int>::iterator up;
	vector<int> count(n,0),count_temp;
	cout<<total<<endl;
	for(down=dp.rbegin();down!=dp.rend();down++){
		a=sum+1;
		count_temp=count;
		for(up=down->second.begin();up!=down->second.end();up++){
			cout<<up->first;
			printf(" %d %d %d\n",a,up->second+1,count_temp[up->second]+1);
			sum++;
			count[up->second]++;
		}
	}
	return 0;
}
