#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;
unordered_map<string,int> mp;
string city,start,des,from,to;
int n,k,cnt,dist;
struct inf{
    string last;
    int dist;
    int ways;
    int head;
    int solider;
};
unordered_map<string,inf> infor;
struct edge{
    string to;
    int dist;
    int next;
}arr[50000];
void add(){
    arr[++cnt].to=to;
    arr[cnt].dist=dist;
    arr[cnt].next=infor[from].head;
    //head[from]=cnt;
    infor[from].head=cnt;

    arr[++cnt].to=from;
    arr[cnt].dist=dist;
    arr[cnt].next=infor[to].head;
    infor[to].head=cnt;
}
struct node{
    string from;
    string to;
    int dist;
    int solid;
    int passed;
};
string my_head="head";

struct cmp{
    bool operator()(const node&a,const node&b){
        if(a.dist!=b.dist) return a.dist>b.dist;
        else if(a.passed!=b.passed) return a.passed<b.passed;
        else return a.solid<b.solid;
    }
};
void help(){
    priority_queue<node,vector<node>,cmp> Q;
    Q.push({my_head,start,0,0,0});
    while(!Q.empty()){
        node cur=Q.top();
        Q.pop();
        if(infor[cur.to].last!=""){
            if(cur.dist==infor[cur.to].dist) infor[cur.to].ways+=infor[cur.from].ways;
            continue;
        }
        infor[cur.to].dist=cur.dist;
        infor[cur.to].last=cur.from;
        infor[cur.to].ways+=infor[cur.from].ways;
        infor[cur.to].solider=cur.solid;
        for(int i=infor[cur.to].head;i;i=arr[i].next){
            if(infor[arr[i].to].last=="" || arr[i].dist+cur.dist==infor[arr[i].to].dist){
                Q.push({cur.to,arr[i].to,arr[i].dist+cur.dist,cur.solid+infor[arr[i].to].solider,cur.passed+1});
            }
        }
    }
    string now=des;
    int cnt=0;
    stack<string> S;
    while(now!=my_head){
        S.push(now);
        now=infor[now].last;
    }
    while(!S.empty()){
        if(cnt) printf("->%s",S.top().c_str());
        else printf("%s",S.top().c_str());
        S.pop();
        cnt++;
    }

    printf("\n%d %d %d\n",infor[des].ways,infor[des].dist,infor[des].solider);
}
/*
struct inf{
    string last;
    int dist;
    int ways;
    int head;
    int solider;
};
*/
int main(){
    int solid;
    cin>>n>>k>>start>>des;
    if(start==des){
        cout<<start<<"->"<<des<<endl;
        cout<<1<<" "<<0<<" "<<0<<endl;
        return 0;
    }
    infor[start]={"",0,0,0,0};
    for(int i=0;i<n-1;i++){
        cin>>city>>solid;
        infor[city]={"",0,0,0,solid};
    }
    for(int i=0;i<k;i++){
        cin>>from>>to>>dist;
        add();
    }
    arr[++cnt].to=start;
    arr[cnt].dist=0;
    arr[cnt].next=0;
    infor[my_head]={"",0,1,cnt,0};
    help();
}