using namespace std;
#include <iostream>
double cal(double a);
int main(){
	double th;
	cin>>th;
	double sum=0;
	int n=0;
	double now=cal(n);
	while(now>=th){
		sum+=now;
		n++;
		now=cal(n);
		//cout<<now<<endl;
	}
	sum+=now;
	printf("%.6f\n",2*sum);
    return 0;
}
double cal(double a){
	double ret=1;
	if(a==0){
		return ret;
	}else{
		while(a!=0){
			ret*=a/(2*a+1);
			a--;
		}
		return ret;
	}
}