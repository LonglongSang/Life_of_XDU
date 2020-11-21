#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define N 200005
int n,lef=0x7fffffff,righ=0x80000000,upper=0x80000000,lower=0x7fffffff,cnt;
struct node{
    int x,y1,y2;//y1>y2;
}e[10005];
int uni[N],uni_cnt;
bool vis[N];
int isok(int i){
    int low=0,high=uni_cnt-1,mid,v;
    cout<<low<<" "<<high<<endl;
    double k,b,a,u,l;
    memset(vis,0,uni_cnt);
    while(high>=low){
        mid=(low+high)/2;
        v=uni[mid];
        if(vis[mid]) return -1;
        vis[mid]=true;
        k=(double)(v-i)/(double)(righ-lef);
        b=(double)i-k*lef;
        bool good=true;
        for(int i=0;i<cnt;i++){
            a=k*e[i].x+b;
            if(a>(double)e[i].y1){
                good=false;
                high=mid-1;
                break;
            }else if(a<(double)e[i].y2){
                good=false;
                low=mid+1;
                break;
            }
        }
        if(good) return mid;
    }
    return -1;
}
int main(){
    
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d\n",&e[i].x,&e[i].y1,&e[i].y2);
    }
    sort(e,e+n,[&](node&a,node&b){
        return a.x<b.x;
    });
    cnt=1;
    for(int i=1;i<n;i++){
        if(e[i].x==e[cnt-1].x){
            e[cnt-1].y1=min(e[cnt-1].y1,e[i].y1);
            e[cnt-1].y2=max(e[cnt-1].y2,e[i].y2);
        }else{
            e[cnt++]=e[i];
        }
    }
    for(int i=0;i<cnt;i++){
        uni[uni_cnt++]=e[i].y1;
        uni[uni_cnt++]=e[i].y2;
        lef=min(lef,e[i].x);
        righ=max(righ,e[i].x);
        //lower=min(lower,e[i].y2);
        //upper=max(upper,e[i].y1);
    }
    sort(uni,uni+uni_cnt);
    uni_cnt=unique(uni,uni+uni_cnt)-uni;
    if(uni_cnt==1){
        printf("%d %d %d %d\n",lef,e[0].y1,lef+1,e[0].y1);
        return 0;
    }
    int v;
    for(int i=0;i<uni_cnt;i++){
        v=isok(uni[i]);
        if(v!=-1){
            printf("%d %d %d %d\n",lef,uni[i],righ,uni[v]);
            break;
        }
    }
}


