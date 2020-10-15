#include <stdio.h>
#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
int n,g,k;
struct node{
    char name[16];
    int grade;
    bool operator <(const node &b)const{
        if(grade!=b.grade) return grade>b.grade;
        else return strcmp(name,b.name)>0?false:true;
    }
}arr;
int main(){
    scanf("%d %d %d\n",&n,&g,&k);
    int ans=0;
    int dp[101]={0};
    priority_queue<node,vector<node>> Q;
    for(int i=0;i<n;i++){
        scanf("%s %d\n",&arr.name,&arr.grade);
        if(60<=arr.grade && arr.grade<g) ans+=20;
        else if(arr.grade>=g) ans+=50;
		
        if(Q.size()<k){
            Q.push(arr);
            dp[arr.grade]++;
        }else if(arr.grade>=Q.top().grade){
            while(Q.size() && Q.top().grade<arr.grade && Q.size()-dp[Q.top().grade]+1>=k){
                dp[Q.top().grade]--;
                Q.pop();
            }
            Q.push(arr);
            dp[arr.grade]++;
        }
    }
    cout<<ans<<endl;
    int size=Q.size();
    node temp[size];
    int cnt=0;
    while(!Q.empty()){
        temp[cnt++]=Q.top();
        Q.pop();
    }
    cnt=1;
    for(int i=size-1;i>=0;i--){
		if(i!=size-1 &&  temp[i].grade!=temp[i+1].grade) cnt=size-1-i+1;
		printf("%d %s %d\n",cnt,temp[i].name,temp[i].grade);
	}
}