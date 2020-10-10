#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a,b,c,d,a_good=0,b_good=0;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c>>d;
		if(b==a+c && d!=a+c){
			b_good++;
		}else if(b!=a+c && d==a+c){
			a_good++;
		}
	}
	cout<<a_good<<" "<<b_good<<endl;
	
	return 0;
}



