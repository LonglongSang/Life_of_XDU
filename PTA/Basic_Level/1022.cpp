#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
bool is_o(int n);
int main(){
	vector<char> out;
	long A,B;
	int C;
	cin>>A>>B>>C;
	A+=B;
	while(A>=C){
		out.push_back('0'+A%C);
		A/=C;
	}
	out.push_back('0'+A);
	for(int i=out.size()-1;i>=0;i--) cout<<out[i];
	return 0;
}
