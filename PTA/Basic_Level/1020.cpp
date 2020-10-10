#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
#include <sstream>
using namespace std;
void input(vector<double> &arr,int num){
	double temp;
	while(num!=0){
		cin>>temp;
		arr.push_back(temp);
		num--;
	}
}
int main(){
	double type_num,max_need,type_num_temp;
	cin>>type_num>>max_need;
	vector<double> have,money;
	input(have,type_num);
	input(money,type_num);
	multimap<double,double> dp;
	for(int i=0;i<have.size();i++) dp.insert(pair<double,double>(money[i]/have[i],have[i]));
	multimap<double,double>::reverse_iterator down;
	double sum=0;
	for(down=dp.rbegin();down!=dp.rend();down++){
		if(max_need>down->second){
			sum+=down->second*down->first;
			max_need = max_need - down->second;
		}else{
			sum+=max_need*down->first;
			break;
		}
	}
	printf("%.2lf\n",sum);
	return 0;
}

