//https://www.luogu.com.cn/problem/P1352
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define N 6005
int n,happy[N],indeg[N],s,f,tot,head[N];
pair<int,int> son[N];
struct edge{
    int to;
    int next;
}e[N];
void add(int from,int to){
    e[++tot].to=to;
    e[tot].next=head[from];
    head[from]=tot;
}
pair<int,int> get_ans(int root){
    //first表示root去的最大值，second表示root不去的最大值
    if(root==0) return {0,0};
    int a=happy[root],b=0;
    pair<int,int> temp;
    for(int i=head[root];i;i=e[i].next){
        temp=get_ans(e[i].to);
        a+=temp.second;
        b+=max(temp.first,temp.second);
    }
    return {a,b};
}
int main(){
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        scanf("%d",happy+i);
        getchar();
    }
    for(int i=1;i<n;i++){
        scanf("%d %d",&s,&f);
        indeg[s]++;
        add(f,s);
    }
    int root;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            root=i;
            break;
        }
    }
    pair<int,int> ans=get_ans(root);
    printf("%d\n",max(ans.first,ans.second));
}


