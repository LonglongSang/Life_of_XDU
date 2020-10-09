#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,k,temp,last;
int father[1005];
int head[1005];
int cnt[1005];
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
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%d:",&k);
        scanf(" %d",&head[i]);
        for(int j=1;j<k;j++){
            scanf(" %d",&temp);
            uni(head[i],temp);
        }
        getchar();
    }
    for(int i=0;i<n;i++){
        cnt[find(head[i])]++;
    }
    int arr[1005];
    int a=0;
    for(int i=0;i<1005;i++){
        if(cnt[i]!=0) arr[a++]=cnt[i];
    }
    printf("%d\n",a);
    qsort(arr,a,sizeof(int),cmp);
    printf("%d",arr[0]);
    for(int i=1;i<a;i++) printf(" %d",arr[i]);
    printf("\n");
}