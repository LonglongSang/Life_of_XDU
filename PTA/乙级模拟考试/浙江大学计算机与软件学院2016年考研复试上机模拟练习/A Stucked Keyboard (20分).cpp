#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
int main(){
	int num;
	scanf("%d\n",&num);
	string line;
	getline(cin,line);
	vector<int> dp(128,1);
	int count=1;
	for(int i=1;i<line.length();i++){
		if(line[i]==line[i-1]){
			count++;
		}else{
            if(count%num==0 && dp[line[i-1]]==1){
				dp[line[i-1]]=0;
			}else if(count%num!=0){
				dp[line[i-1]]=2;
			}
			count=1;
		}
	}
    if(count%num==0 && dp[line[line.length()-1]]==1){
		dp[line[line.length()-1]]=0;;
	}else if(count%num==0){
		dp[line[line.length()-1]]=2;
	}
	int index=0;
	string out;
	out.resize(1500);
	count=0;
	set<char> check;
	while(index<line.length()){
		if(dp[line[index]]==0){
			if(check.find(line[index])==check.end()){ 
				printf("%c",line[index]);
				check.insert(line[index]);
			}
			out[count++]=line[index];
			index+=num;
		}else{
			out[count++]=line[index++];
		}
	}
	printf("\n");
	for(int i=0;i<count;i++) printf("%c",out[i]);
	return 0;
}



