#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	int num;
	cin>>num;
	int dp[3][num];
	int want[num];
	int top[3];
	top[0]=num-1;
	top[1]=-1;
	top[2]=-1;
	for(i=0;i<num;i++) dp[0][i]=i;
	int a=1;
	for(int i=0;i<num;i++){
		want[i]=a+1;
		a=a^1;
	}
	int finish=0;
	int want_go;
	while(finish!=num){
		want_go=top[dp[i][top[i]]];
		for(int i=0;i<3;i++){
			if(top[i]==-1) next;
			want_go=want[dp[i][top[i]]];//想去哪个柱子
			want_go_first=dp[want_go][top[want_go]];//想要去的柱子的第一个
			while(top[want_go]==-1 || dp[i][top[i]]>want_go_first){
				if(top[want_go]==-1
			}
		}
	}
	return 0;
}





















