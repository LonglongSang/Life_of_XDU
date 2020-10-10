#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
int main(){
	string a;
	cin>>a;
	vector<string> cp={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int sum=0;
	for(int i=a.length()-1;i>=0;i--) sum+=(a[i]-'0');
	vector<string> out;
	while(sum!=0){
		out.push_back(cp[sum%10]);
		sum/=10;
	}
	if(out.size()==0){
		cout<<cp[0]<<endl;
	}else{
		for(int i=out.size()-1;i>=0;i--){
			if(sum){
				cout<<" "<<out[i];
			}else{
				cout<<out[i];
			}
			sum++;
		}
	}
	return 0;
}