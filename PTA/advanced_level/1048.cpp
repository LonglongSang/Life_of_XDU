#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int main() {
    vector<int> dp(501,0);
    int num,target,temp;
    cin>>num>>target;
    for(int i=0;i<num;i++){
        cin>>temp;
        dp[temp]++;
    }
    for(int i=1;i<501;i++){
        if(dp[i]>1 && target%i==0 && target/i==2){
            printf("%d %d\n",i,i);
            return 0;
        }
        if(target-i<=500 && target-i>i && dp[i]!=0 && dp[target-i]!=0){
            printf("%d %d\n",i,target-i);
            return 0;
        }
    }
    printf("No Solution");
    
}