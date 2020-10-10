#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <queue>
using namespace std;
int dist[201][201];
int n,m,k,from,to,temp,t,a[1000];
int main(){
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d\n",&from,&to,&temp);
        dist[from][to]=temp;
        dist[to][from]=temp;
    }
    scanf("%d\n",&k);
    int vis[1000];
    int index=0;
    int min_dist=100000000;
    for(int c=1;c<=k;c++){
        scanf("%d",&t);
        fill(vis,vis+n+1,0);
        for(int i=0;i<t;i++){
            scanf("%d",a+i);
            vis[a[i]]++;
        }
        bool tong=true;
        int total_dist=0;
        for(int i=0;i<t-1;i++){
            if(!dist[a[i]][a[i+1]]){
                tong=false;
                break;
            }
            total_dist+=dist[a[i]][a[i+1]];
        }
        if(!tong){
            printf("Path %d: NA (Not a TS cycle)\n",c);
            continue;
        }
        bool good=true;
        for(int i=1;i<=n;i++){
            if(!vis[i]) good=false;
        }
        if(a[0] != a[t-1]) good=false;
        if(!good){
            printf("Path %d: %d (Not a TS cycle)\n",c,total_dist);
            continue;
        }
        if(total_dist<min_dist){
            min_dist=total_dist;
            index=c;
        }
        if(t==n+1 && vis[a[0]]==2){
            printf("Path %d: %d (TS simple cycle)\n",c,total_dist);
            continue;
        }
        printf("Path %d: %d (TS cycle)\n",c,total_dist);
    }
    printf("Shortest Dist(%d) = %d",index,min_dist);
	return 0;
}