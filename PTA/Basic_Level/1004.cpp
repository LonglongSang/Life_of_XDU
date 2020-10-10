#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main(){
	int n;
	cin>>n;
	map<int,string> name;
	map<int,string> ID;
	string na,I;
	int gr;
	int max=-1;
	int min=1000;
	while(n!=0){
		cin>>na>>I>>gr;
		if(gr>max) max=gr;
		if(gr<min) min=gr;
		name[gr]=na;
		ID[gr]=I;
		n--;
	}
	cout<<name[max]<<" "<<ID[max]<<endl;
	cout<<name[min]<<" "<<ID[min]<<endl;
	return 0;
}