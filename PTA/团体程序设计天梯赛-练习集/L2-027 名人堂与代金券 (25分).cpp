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
    string name;
    int grade;
    bool operator <(const node &b)const{
        if(grade!=b.grade) return grade>b.grade;
        else return name<b.name;
    }
}arr;
int main(){
    scanf("%d %d %d\n",&n,&g,&k);
    int ans=0;
    int dp[101]={0};
    priority_queue<node,vector<node>> Q;//小顶堆，排在顶部的元素的分数是最小的
    for(int i=0;i<n;i++){
        cin>>arr.name>>arr.grade;
        if(60<=arr.grade && arr.grade<g) ans+=20;
        else if(arr.grade>=g) ans+=50;

        if(Q.size()<k){//如果堆的大小小于k，直接将这个人添加进去
            Q.push(arr);
            dp[arr.grade]++;
        }else if(arr.grade>=Q.top().grade){
            //如果堆的大小大于等于k时
            //如果当前节点的grade大于堆中分数的最小值
            //就进行更新
            while(Q.size() && Q.top().grade<arr.grade && Q.size()-dp[Q.top().grade]+1>=k){
                //堆不为空，同时堆顶部的节点的分数小于当前节点的grade
                //同时如果将当前节点插入堆中后，他的排名会排在第k名及第k名之后
                dp[Q.top().grade]--;
                Q.pop();
            }
            Q.push(arr);
            dp[arr.grade]++;
        }
    }

    //输出
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
		cout<<cnt<<" "<<temp[i].name<<" "<<temp[i].grade<<endl;
		
	}
}