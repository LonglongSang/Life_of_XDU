#include <stdio.h>
#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
int n;
double z,r;
struct node{
    int next;
    int to;
}arr[100000];
int head[100005];
int super_man[100005];
double gongli[100005];
bool super[100005];
int from,to,cnt,k;
void add(){
    arr[++cnt].to=to;
    arr[cnt].next=head[from];
    head[from]=cnt;
}
int main(){
    scanf("%d %lf %lf\n",&n,&gongli[1],&r);
    r=(100.0-r)/100.0;
    for(int i=1;i<=n;i++){
        scanf("%d ",&k);
        from=i;
        if(k==0){
            scanf("%d\n",&super_man[i]);
            super[i]=true;
        }else{
            for(int j=0;j<k;j++){
                scanf("%d",&to);
                to++;
                getchar();
                add();
            }
        }
    }
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int from=Q.front();
        Q.pop();
        for(int i=head[from];i;i=arr[i].next){
            int to=arr[i].to;
            
            if(super[to]){
                gongli[to]=super_man[to]*gongli[from]*r;
            }else{
                gongli[to]=gongli[from]*r;
            }
            Q.push(to);
        }
    }
    if(super[1]){
        printf("%d\n",(int)(gongli[1]*super_man[1]));
        return 0;
    }
    double ans=0.0;
    for(int i=1;i<=n;i++){
        if(super[i])ans+=gongli[i];
    }
    printf("%lld\n",(long long)ans);
}