#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <queue>
#include <stack>
using namespace std;
using ll=long long;
#define N 10005
int par[N],n,k,num,lev;
int level[1000];
char id[100];
bool vis[N];
int getlevel(char* s){
    int ans=0;
    while(*s && *s==' ') ans++,s++;
    return ans;
}
int getid(char* s){
    while(*s && *s==' '){
        s++;
    }
    int ans=0;
    while(*s){
        ans=ans*10+*s-'0';
        s++;
    }
    return ans;
}
int main(){
    freopen("C:\\Users\\Administrator\\Desktop\\PAT\\input.txt","r+",stdin);
    scanf("%d",&n);
    getchar();
    //return 0;
    for(int i=0;i<n;i++){
        scanf("%[^\n]",id);
        getchar();
        num=getid((char*)id)+1;
        lev=getlevel((char*)id);
        vis[num]=true;
        if(lev) par[num]=level[lev-1];
        level[lev]=num;
    }
    scanf("%d",&k);
    getchar();
    stack<int> Q;
    for(int i=0;i<k;i++){
        scanf("%d",&num);
        num++;
        getchar();
        if(!vis[num]){
            printf("Error: %0.4d is not found.\n",num-1);
            continue;
        }
        while(num){
            Q.push(num);
            num=par[num];
        }
        int j=0;
        while(!Q.empty()){
            if(j++) printf("->");
            printf("%0.4d",Q.top()-1);
            Q.pop();
        }
        putchar('\n');
    }
    return 0;
}