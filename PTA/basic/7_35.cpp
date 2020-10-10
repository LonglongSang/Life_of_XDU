#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
long find_common(long a,long b);
void dev(long &mother,long &son);
int main(){
	int num;
	cin>>num;
	int num_temp=num;
	long son=0;
	long mother=1;
	long a,b,common;
	while(num!=0){
		scanf("%ld/%ld",&a,&b);
		if(a==0) b=1;
		common=find_common(b,mother);
		son=common/mother*son+common/b*a;
		mother=common;
		if(son==0) mother=1;
		dev(mother,son);
		num--;
	}
	mother*=num_temp;
	dev(mother,son);
	if(mother==1){
		cout<<son<<endl;
	}else{
		cout<<son<<"/"<<mother;
	}
	return 0;
}
void dev(long &mother,long &son){
	if(son==0) return;
	long min;
	int flag=0;
	while(1){
		min=mother>son?son:mother;
		for(int i=2;i<=min;i++){
			if(mother%i==0 && son%i==0){
				flag=1;
				mother/=i;
				son/=i;
				break;
			}
		}
		if(flag==0) break;
		flag=0;
	}
}
long find_common(long a,long b){
	long max=a>b?a:b;
	while(1){
		if(max%a==0 && max%b==0) break;
		max++;
	}
	return max;
}