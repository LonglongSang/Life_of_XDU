#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <unordered_map>
#include <stack>
using namespace std;
int n,m,v,x,a,k=2,cnt,root,total_word,want_num;
#define N 500000
int trie[N][37];
int num[N];
bool isend[N];
int change(char &a){
    if(isalpha(a)) return a-'a';
    else if(a=='_') return 26;
    else return 27+a-'0';
}
char rev_change(int a){
    if(a<26) return a+'a';
    else if(a==26) return '_';
    else return a-27+'0';
}
char path[15];
/*
而合法的“单词字符”为大小写字母、数字和下划线，其它字符均认为是单词分隔符。
*/
void build(){
    int step=0;
    root=1;
    while(step!=cnt){
        if(isupper(path[step])) path[step]=tolower(path[step]);
        int mp=change(path[step]);
        if(!trie[root][mp]) trie[root][mp]=k++;
        root=trie[root][mp];
        step++;
        if(step==cnt){
            if(!isend[root]) isend[root]=true,total_word++;
            num[root]++;
        }
    }
    cnt=0;
}
string word;
struct node{
    string word;
    int cnt;
};
struct cmp{
    bool operator ()(const node&a,const node&b){
        if(a.cnt!=b.cnt) return a.cnt>b.cnt;
        else return a.word<b.word;
    }
};
int d;
priority_queue<node,vector<node>,cmp> Q;
void dfs(int cur){
    if(isend[cur]){
        if(Q.size()<want_num){
            Q.push({word,num[cur]});
        }else if(num[cur]>Q.top().cnt || (num[cur]==Q.top().cnt && word<Q.top().word)){
            Q.pop();
            
            Q.push({word,num[cur]});
        }
    }
    for(int i=0;i<37;i++){
        if(trie[cur][i]==0) continue;
        word.push_back(rev_change(i));
        dfs(trie[cur][i]);
        word.pop_back();
    }
}
int main(){
    char v;
    while((v=getchar())!='#'){
        if(isdigit(v) || isalpha(v) || v=='_'){
            if(cnt<15) path[cnt++]=v;
        }else{
            if(cnt) build();
        }
    }
    if(cnt) build();
    want_num=total_word*0.1;
    dfs(1);
    printf("%d\n",total_word);
    stack<node> S;
    while(!Q.empty()) S.push(Q.top()),Q.pop();
    while(!S.empty()){
        printf("%d:%s\n",S.top().cnt,S.top().word.data());
        S.pop();
    }
    return 0;
}