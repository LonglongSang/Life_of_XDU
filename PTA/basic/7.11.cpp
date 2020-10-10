#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
long long find_common(long long a,long long b);
void dev(long long &mother,long long &son);
int main(){
	int num;
	cin>>num;
	int num_temp=num;
	long long son=0;
	long long mother=1;
	long long a,b,common;
	while(num!=0){
		scanf("%lld/%lld",&a,&b);
        if(b<0){
            a=-a;
            b=-b;
        }
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
void dev(long long &mother,long long &son){
	if(son==0){
		mother=1;
		return;
	}
	long long min;
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
long long find_common(long long a,long long b){
	if(a==1 && b==1) return 1;
	long long max=a>b?a:b;
	while(1){
		if(max%a==0 && max%b==0) break;
		max++;
	}
	return max;
}