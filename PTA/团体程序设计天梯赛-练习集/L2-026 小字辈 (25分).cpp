#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int n,cnt,from,to,root;
int head[100005];
struct node{
    int next;
    int to;
}arr[100005];
inline void add(){
    arr[++cnt].to=to;
    arr[cnt].next=head[from];
    head[from]=cnt;
}
int ans[100005];
int ans_cnt;
int main(){
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&from);
        to=i;
        if(from==-1){
            root=i;
            continue;
        }
        add();
    }
    queue<int> Q;
    Q.push(root);
    Q.push(-1);
    int level=1;
    while(!Q.empty()){
        int cur=Q.front();
        Q.pop();
        if(cur==-1){
            if(Q.empty()) break;
            ans_cnt=0;
            level++;
            Q.push(-1);
            continue;
        }
        ans[ans_cnt++]=cur;
        for(int i=head[cur];i;i=arr[i].next){
            Q.push(arr[i].to);
        }
    }
    printf("%d\n",level);
    sort(ans,ans+ans_cnt);
    printf("%d",ans[0]);
    for(int i=1;i<ans_cnt;i++) printf(" %d",ans[i]);
    printf("\n");
}