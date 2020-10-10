#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	int num;
	cin>>num;
	string name[num];
	string birth[num];
	char sex[num];
	string phone[num];
	string mobile[num];
	int count=0;
	while(count!=num){
		cin>>name[count]>>birth[count]>>sex[count]>>phone[count]>>mobile[count];
		count++;
	}
	int check_num;
	cin>>check_num;
	int check_order[check_num];
	count=0;
	while(count!=check_num){
		cin>>check_order[count++];
	}
	int j;
	for(int i=0;i<check_num;i++){
		j=check_order[i];
		if(j>=0 && j<num){
			cout<<name[j]<<" "<<phone[j]<<" "<<mobile[j]<<" "<<sex[j]<<" "<<birth[j];
		}else{
			cout<<"Not found";
		}
		if(i!=(check_num-1)) cout<<endl;
	}
	return 0;
}