#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,k,temp,m,last,a,b;
int arr[1005];
int path[1000];
int cnt;
int find(int val){
    for(int i=0;i<cnt;i++) if(val==path[i]) return 1;
    return 0;
}
int main(){
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",arr+i);
    }
    scanf("%d%d",&a,&b);
    if(arr[a]==0 || arr[b]==0){
        printf("ERROR: T[%d] is NULL",arr[a]==0?a:b);
        return 0;
    }

    int cur=a;
    while(cur!=1){
        path[cnt++]=cur;
        cur/=2;
    }
    path[cnt++]=1;
    cur=b;
    while(cur!=1){
        if(find(cur)){
            printf("%d %d",cur,arr[cur]);
            return 0;
        }
        cur/=2;
    }
    printf("1 %d\n",arr[1]);
    return 0;
}