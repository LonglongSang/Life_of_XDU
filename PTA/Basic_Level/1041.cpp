#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
using namespace std;
double check(string a);
struct infor{
	string name;
	int exam_num;
};
int main(){
	int n,test_num,exam_num;
	cin>>n;
	string name;
	vector<infor> dp(n+1);
	while(n!=0){
		cin>>name>>test_num>>exam_num;
		dp[test_num].name=name;
		dp[test_num].exam_num=exam_num;
		n--;
	}
	cin>>n;
	while(n!=0){
		cin>>test_num;
		cout<<dp[test_num].name<<" "<<dp[test_num].exam_num<<endl;
		n--;
	}
	return 0;
}



