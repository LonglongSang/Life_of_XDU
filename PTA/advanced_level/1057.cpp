#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>//printf
#include <algorithm>
using namespace std;
void input(vector<int> &stack,int n){
	string type;
	int a,count=0;
	for(int i=1;i<=n;i++){
		//cout<<"ROUND "<<i<<"##"<<endl;
		cin>>type;
		if(type=="Pop"){
			//cout<<"Pop"<<endl;
			if(count==0){
				cout<<"Invalid"<<endl;
			}else{
				count--;
				cout<<stack[count]<<endl;
				stack.resize(count);
			}
		}else if(type=="PeekMedian"){
			//cout<<"PeekMiand"<<endl;
			if(count==0){
				cout<<"Invalid"<<endl;
			}else{
				vector<int> have(stack);
				sort(have.begin(),have.end());
				if(count%2==1){
					cout<<have[(count+1)/2-1]<<endl;
				}else{
					cout<<have[count/2-1]<<endl;
				}
			}
		}else{
			cin>>a;
			//cout<<"Push "<<a<<endl;
			count++;
			stack.resize(count);
			stack[count-1]=a;
		}
		//cout<<"stack have: ";
		//for(int j=0;j<stack.size();j++){
		//	cout<<" "<<stack[j];
		//}
		//cout<<endl;
	}
}
int main(){
	int count=0,n;
	scanf("%d\n",&n);
	vector<int> stack;
	input(stack,n);
	
	return 0;
}


