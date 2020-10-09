#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,k,temp,m,last;
int father[30005];
int head[1005];
int cnt[30005];
int find(int a){
    while(father[a]){
        a=father[a];
    }
    return a;
}
void uni(int a,int b){
    int _a=find(a);
    int _b=find(b);
    if(_a!=_b){
        father[_a]=_b;
    }
}
int cmp(const void* a,const void* b){
    return *((int*)b)-*((int*)a);
}
int main(){
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        scanf(" %d",&last);
        for(int j=1;j<k;j++){
            scanf(" %d",&temp);
            uni(last,temp);
        }
        getchar();
    }
    for(int i=1;i<=n;i++){
        int a=find(i);
        father[i]=a;
        cnt[father[i]]++;
    }
    int ans=0;
    for(int i=1;i<30005;i++){
        ans=ans>cnt[i]?ans:cnt[i];

    }
    printf("%d\n",ans);
}