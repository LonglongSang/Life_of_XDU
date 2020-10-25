#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <math.h>
#define N 100
using namespace std;
int n;
int arr[200005];
vector<int> prime;
void get_prime(int upper){
    //upper=3000;
    prime.push_back(1);
    prime.push_back(2);
    for(int i=3;i*i<=upper;i++){
        bool is_prime=true;
        for(int j=1;j<prime.size();j++){
            if(i%prime[j]==0){
                is_prime=false;
                break;
            }
        }
        if(is_prime)prime.push_back(i);
    }
}
struct node{
    int cnt;
    int val;
    node():cnt(0),val(0){}
};
unordered_map<int,node> dp;
int main(){
    scanf("%d\n",&n);
    
    int upper=0;
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
        dp[arr[i]].cnt++;
        upper=max(upper,arr[i]);
    }
    get_prime(upper);
    sort(arr,arr+n);
    n=unique(arr,arr+n)-arr;
    int ans=0;
    int a=arr[0]==1?1:0;
    int add=0;
    if(dp.find(1)!=dp.end()){
        add=dp[1].cnt;
        dp[1].val=dp[1].cnt;
        ans=dp[1].cnt;
    }
    for(;a<n;a++){
        dp[arr[a]].val=dp[arr[a]].cnt;
        for(int i=a-1;i>=0;i--){
            if(arr[a]%arr[i]!=0) continue;           
            if(dp.find(arr[i])!=dp.end()){
                dp[arr[a]].val=max(dp[arr[a]].cnt+dp[arr[i]].val,dp[arr[a]].val);
                break;
            }
        }       
        ans=max(ans,dp[arr[a]].val);
    }
    cout<<ans<<endl;
}