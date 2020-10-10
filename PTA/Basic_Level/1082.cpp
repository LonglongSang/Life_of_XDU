#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
using namespace std;
int main(){
	int x,y;
	string best;
	string bad;
	int best_grade=-1;
	int bad_grade=10000;
	int n;
	cin>>n;
	string now_name;
	while(n!=0){
		cin>>now_name>>x>>y;
		x=(int)pow(x,2)+(int)pow(y,2);
		if(x>best_grade){
			best_grade=x;
			best=now_name;
		}
		if(x<bad_grade){
			bad_grade=x;
			bad=now_name;
		}
		n--;
	}
	cout<<bad<<" "<<best<<endl;
	return 0;
}