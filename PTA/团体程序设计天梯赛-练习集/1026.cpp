#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
struct infor{
	string arrive;
	int time;
	int counter;
	
};
struct table{
	string open;
	int sum;
};
bool cmp(const infor &a,const infor &b){
	return a.arrive<b.arrive;
}
int main(){
	vector<infor> vip,unvip;
	int n,type,time,t_num,vip_num;
	string arrive;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arrive>>time>>type;
		if(type==1) vip.push_back({arrive,time});
		else unvip.push_back({arrive,time});
	}
	sort(vip.begin(),vip.end(),cmp);
	sort(unvip.begin(),unvip.end(),cmp);
	cin>>t_num>>vip_num;
	vector<table> vip_table(num);
	vector<table> unvip(num);
	return 0;
}