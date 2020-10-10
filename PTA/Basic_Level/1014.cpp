#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <set>
#include <ctype.h>
using namespace std;
int get_upper(string &a,string &b){
	int small=a.length()>b.length()?b.length():a.length();
	for(int i=0;i<small;i++){
		if(a[i]==b[i] && a[i]>='A' && a[i]<='Z') return a[i]-'A';
	}
	return -1;
}
int get_hour(string &a,string &b){
	int small=a.length()>b.length()?b.length():a.length();
	int sum=0;
	for(int i=0;i<small;i++){
		if(a[i]==b[i]){
			sum++;
			cout<<sum<<" "<<a[i]<<endl;
			if(sum==2){
				if(a[i]>='0' && a[i]<='9'){
					return a[i]-'0';
				}else{
					//cout<<sum<<a[i]<<endl;
					return a[i]-'A'+10;
				}
			}
		}
	}
	return -1;
}
int get_same(string &a,string &b){
	int small=a.length()>b.length()?b.length():a.length();
	for(int i=0;i<small;i++){
		if(a[i]==b[i] && isalpha(a[i])) return i;
	}
	return -1;
} 
int main(){
	//string hour="0123456789ABCDEFGHIJKLMN";
	vector<string> day(7);
	//day={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<d<<endl;
	int week=get_upper(a,b);
	int hou=get_hour(a,b);
	int min=get_same(c,d);
	//day[week].c_str()
	cout<<week<<endl;
	cout<<hou<<endl;
	cout<<min<<endl;
	printf("%d %.2d:%.2d\n",week,hou,min);
	return 0;
}
