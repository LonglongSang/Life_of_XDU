#include<bits/stdc++.h>
using namespace std;
#define N 300005
int n,from,to,cnt;

int indeg[N];
int head[N];
struct node{
    int to;
    int next;
}arr[N<<1];
void add(){
    arr[++cnt].to=to;
    arr[cnt].next=head[from];
    head[from]=cnt;

    arr[++cnt].to=from;
    arr[cnt].next=head[to];
    head[to]=cnt;
}
int main() {
    scanf("%d\n",&n);
    int total=n;
    for(int i=0;i<n;i++){
        scanf("%d %d\n",&from,&to);
        indeg[from]++;
        indeg[to]++;
        if(indeg[from]==1 || indeg[to]==1) total--;
        add();
    }
    int cnt=0;
    for(int a=1;a<=n;a++){
        if(indeg[a]==0){
            if(cnt++) printf(" ");
            printf("%d",total-1);
            continue;
        }
        int minus=0;
        for(int i=head[a];i;i=arr[i].next){
            indeg[arr[i].to]--;
            if(indeg[arr[i].to]==0) minus++;
        }
        if(cnt++) printf(" ");
        printf("%d",minus!=0?total+minus-1:total);
        for(int i=head[a];i;i=arr[i].next){
            indeg[arr[i].to]++;
        }        
    }
    printf("\n");
	return 0;
}