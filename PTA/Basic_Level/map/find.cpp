#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(){
	multimap<int, int> mapStudent;
	mapStudent.insert(pair<int,int>(3, 10));
	mapStudent.insert(pair<int,int>(2, 10));
	mapStudent.insert(pair<int,int>(2, 11));
	mapStudent.insert(pair<int,int>(3, 12));

	
	for(auto it=mapStudent.rbegin();it!=mapStudent.rend();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
}