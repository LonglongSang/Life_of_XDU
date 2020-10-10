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
int main(){
	//double cc=-1.875;
	//cc=(double)(int)(cc*100+0.5)/100;
	//cout<<cc<<endl;
	int n;
	cin>>n;
	string a;
	int count=0;
	double ret,sum=0;
	while(n!=0){
		cin>>a;
		ret=check(a);
		if(ret==1001){
			cout<<"ERROR: "<<a<<" is not a legal number"<<endl;
		}else{
			count++;
			sum+=ret;
		}
		n--;
	}
	if(count>0){
		sum=sum/count;
		if(sum>0){
			sum=(double)(int)(sum*100+0.5)/100;
		}else{
			sum=(double)(int)(sum*100-0.5)/100;
		}
		if(count>1) cout<<"The average of "<<count<<" numbers is ";
		if(count==1) cout<<"The average of "<<count<<" number is ";
		printf("%.2lf\n",sum);
	}else{
		cout<<"The average of 0 numbers is Undefined"<<endl;
	}
	return 0;
}
double check(string a){
	int count_minus=0,count_dot=0,bad=0,count_digit=0;
	double ret;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0' && a[i]<='9'){
			count_digit++;
		}else if(a[i]=='-'){
			count_minus++;
			if(i!=0 || count_minus==2){
				bad=1;
				break;
			}
		}else if(a[i]=='.'){
			count_dot++;
			if(count_dot==2 || i==0 || i==a.length()-1 || a.length()-i>3 || (a[0]=='-' && i==1)){
				bad=1;
				break;
			}
		}else{
			bad=1;
			break;
		}
	}
	if(bad==0 && a.size()>2){
		if(a[0]=='0' && a[1]!='.') bad=1;
	}
	if(bad==0 && count_digit!=0){
		istringstream h(a);
		h>>ret;
		if(ret>=-1000 && ret<=1000) return ret;
	}
	return 1001;
}



