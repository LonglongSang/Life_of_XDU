#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
long long find_common(long long a,long long b);
void dev(long long &mother,long long &son);
int main(){
	long long a,b,c,d,mother,son;
	scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
    if(b<0){
		a=-a;
		b=-b;
    }
	if(d<0){
		c=-c;
		d=-d;
	}
	if(a==0) b=1;
	if(c==0) d=1;
	mother=find_common(b,d);
	son=mother/b*a+mother/d*c;
	if(son==0) mother=1;
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