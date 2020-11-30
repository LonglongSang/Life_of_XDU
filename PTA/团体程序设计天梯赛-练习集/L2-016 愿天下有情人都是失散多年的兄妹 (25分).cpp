#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n,k,a,b,id,m,f;
char typ;
#define N 100005
int mother[N],father[N];
bool ismale[N],vis[N];
int path1[1000],path2[1000],cnt1,cnt2;
vector<int> to[N];
void bfs(int id,int* path,int &cnt){
    queue<int> Q;
    cnt=0;
    Q.push(id);
    Q.push(-1);
    int level=0;
    while(!Q.empty()){
        id=Q.front();
        Q.pop();
        if(id==-1){
            if(Q.empty()) break;
            level++;
            if(level==5) break;
            Q.push(-1);
            continue;
        }
        path[cnt++]=id;
        for(auto& x:to[id]) Q.push(x);
    }
}
bool good(){
    for(int i=0;i<cnt1;i++){
        for(int j=0;j<cnt2;j++){
            if(path1[i]==path2[j]) return false;
        }
    }
    return true;
}

int main(){
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        scanf("%d %c %d %d\n",&id,&typ,&f,&m);
        //getchar();
        if(f!=-1) ismale[f]=true,to[id].push_back(f);
        if(m!=-1) to[id].push_back(m);
        if(typ=='M') ismale[id]=true;
    }
    scanf("%d\n",&k);
    //getchar();
    for(int i=0;i<k;i++){
        scanf("%d %d",&a,&b);
        //getchar();
        if(ismale[a]==ismale[b] || a==b){
            printf("Never Mind\n");
            continue;
        }
        bfs(a,path1,cnt1);
        bfs(b,path2,cnt2);
        if(good()){
            printf("Yes\n");
        }else{
            printf("No\n");
        }

    }
}