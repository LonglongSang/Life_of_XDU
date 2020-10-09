#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,k,temp,m,last,a,b;
typedef struct noode node;
struct noode{
    int father;
    int mother;
    char is_male;
}arr[100005];
int a_path[256];
int b_path[256];
int a_cnt;
int b_cnt;
void build_path(int now,int* cnt,int *path,int step){
    if(step==4) return;
    if(arr[now].father!=-1) path[(*cnt)++]=arr[now].father;
    if(arr[now].mother!=-1) path[(*cnt)++]=arr[now].mother;
    if(arr[now].father) build_path(arr[now].father,cnt,path,step+1);
}
int is_ok(){
    a_cnt=0;b_cnt=0;
    a_path[a_cnt++]=a;
    b_path[b_cnt++]=b;
    build_path(a,&a_cnt,a_path,1);
    build_path(b,&b_cnt,b_path,1);
    for(int i=0;i<a_cnt;i++){
        for(int j=0;j<b_cnt;j++){
            if(a_path[i]==b_path[j]) return 0;
        }
    }
    return 1;
}
int main(){
    scanf("%d\n",&n);
    for(int i=0;i<100005;i++){
        arr[i].mother=-1;
        arr[i].father=-1;
    }
    for(int i=0;i<n;i++){
        scanf("%d ",&temp);
        scanf("%c %d %d\n",&arr[temp].is_male,&arr[temp].father,&arr[temp].mother);
    }
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d\n",&a,&b);
        //printf("%d %d\n",a,b);
        //printf("%c %c\n",arr[a].is_male,arr[b].is_male);
        if(arr[a].is_male==arr[b].is_male){
            printf("Never Mind\n");
            continue;
        }
        //break;
        if(is_ok()){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

}