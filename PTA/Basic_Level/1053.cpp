#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>//printf
#include <map>
using namespace std;
int main(){
	double n,e,D,n_temp;
	cin>>n>>e>>D;
	n_temp=n;
	double m_empty=0,empty=0;
	double day_num,day_num_temp;
	double use;
	double count=0;
	while(n!=0){
		cin>>day_num;
		day_num_temp=day_num;
		while(day_num_temp!=0){
			cin>>use;
			if(use<e) count++;
			day_num_temp--;
		}
		if(count/day_num>0.5){
			if(day_num>D){
				empty++;
			}else{
				m_empty++;
			}
		}
		count=0;
		n--;
	}
	//cout<<m_empty<<empty<<n<<endl;
	m_empty=m_empty*100/n_temp;
	empty=empty*100/n_temp;
	
	printf("%.1lf%% %.1lf%%",m_empty,empty);
	return 0;
}