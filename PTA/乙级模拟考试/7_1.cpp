#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;
double get(string &a){
	istringstream h(a);
	double ret;
	h>>ret;
	return ret;
}
int main(){
	string a;
	int n;
	cin>>a>>n;
	if(n==a.length()){
		printf("1.00\n");
		return 0;
	}else{
		double a_o,a_n;
		a_o=get(a);
		string b=a.substr(a.length()-n);
		a=a.substr(0,a.length()-n);
		a=b+a;
		a_n=get(a);
		//cout<<a_o<<" "<<a_n<<endl;
		a_o=a_n/a_o;
		printf("%.2lf\n",a_o);
	}
	return 0;
}