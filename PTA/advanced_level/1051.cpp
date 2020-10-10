#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
int main(){
	int m,n,k,temp,count;
	cin>>m>>n>>k;
	//scanf("%d %d %d\n",&m,&n,&k);
	stack<int> sta;
	bool right;
	vector<int> save(n);
	for(int i=0;i<k;i++){
		count=1;
		right=true;
		for(int j=0;j<n;j++) cin>>save[i];
		for(int j=0;j<n;j++){
			temp=save[i];
			if(temp>=count){
				for(int c=count;c<=temp;c++){
					if(sta.size()==m){
						right=false;
						break;
					}
					sta.push(c);
					cout<<c<<" in"<<endl;
				}
				count=temp+1;
				cout<<sta.top()<<" out"<<endl;
				sta.pop();

			}else{
				if(sta.top()==temp){
					sta.pop();
					cout<<temp<<" out"<<endl;
				}else{
					right=false;
				}
			}
			if(right==false) break;
		}
		if(right==true){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
		while(sta.size()!=0) sta.pop();
	}
	return 0;
}


