#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
		
int main (){
	vector<int> address(100001,-1);
	int b1,b2,num,cur,next;
	char data;
	scanf("%d %d %d\n",&b1,&b2,&num);
	for(int i=0;i<num;i++){
		scanf("%d %c %d\n",&cur,&data,&next);
		address[cur]=next;
	}
	set<int> dp;
	cur=b1;
	while(cur!=-1){
		dp.insert(cur);
		cur=address[cur];
	}
	cur=b2;
	while(cur!=-1){
		if(dp.find(cur)!=dp.end()){
			printf("%0.5d\n",cur);
			return 0;
		}
		cur=address[cur];
	}
	cout<<-1<<endl;
	return 0;
}