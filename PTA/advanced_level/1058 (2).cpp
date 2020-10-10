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
#include <iomanip>
using namespace std;
int main(){
	long s_a,s_b,s_c,m_a,m_b,m_c;
	scanf("%ld.%ld.%ld %ld.%ld.%ld\n",&s_a,&s_b,&s_c,&m_a,&m_b,&m_c);
	long sum_s=s_a*17*29+s_b*29+s_c;
	long sum_m=m_a*17*29+m_b*29+m_c;
	sum_m=sum_m+sum_s;
	m_c=sum_m%29;
	sum_m=(sum_m-m_c)/29;
	m_b=sum_m%17;
	m_a=(sum_m-m_b)/17;
	cout<<m_a<<"."<<m_b<<"."<<m_c<<endl;
	return 0;
}

