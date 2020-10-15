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
int par[10005];
int cnt[10005];
int my,fa,mo,k,son,area;
int find(int a){
    while(par[a]!=a){
        a=par[a];
    }
    return a;
}
void uniona(int a,int b){
    int _a=find(a);
    int _b=find(b);
    if(a!=b){
        if(_b>_a) swap(_a,_b);
        par[_a]=_b;
    }
}
struct node{
    int index;
    int area;
    int f;
}arr[1005];
struct infor{
    int f;
    int i;
    int p;
    float a;
}fangzi[1000];
int main(){
    scanf("%d\n",&n);
    for(int i=0;i<10000;i++){
        par[i]=i;
    }
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d ",&my,&fa,&mo,&k);
        //cout<<my<<" "<<fa<<endl;
        //cout<<my<<" "<<mo<<endl;
        if(fa!=-1) uniona(my,fa);
        if(mo!=-1) uniona(my,mo);
        for(int j=0;j<k;j++){
            scanf("%d ",&son);
            uniona(my,son);
        }
        scanf("%d %d\n",&arr[i].f,&arr[i].area);
        //cout<<arr[i].f<<" "<<arr[i].area<<endl;
        arr[i].index=my;
    }
    int ds[]={6666,5551,5552,1,7777,1234,5678,9012,2};
    for(int i=0;i<10000;i++){
        par[i]=find(i);
        cnt[par[i]]++;
    }
    //for(int i=0;i<9;i++) cout<<ds[i]<<" "<<par[ds[i]]<<endl;
    map<int,infor> dp;
    for(int i=0;i<n;i++){
        int p=par[arr[i].index];
        dp[p].a+=arr[i].area;
        dp[p].i=p;
        dp[p].f+=arr[i].f;
        dp[p].p=cnt[p];
    }
    int t=0;
    for(auto i:dp){
        fangzi[t]=i.second;
        fangzi[t].a/=fangzi[t].p;
        t++;
    }
    sort(fangzi,fangzi+t,[](const infor&a, const infor &b){
        if(a.a!=b.a) return a.a>b.a;
        else return a.i<b.i;
    });
    printf("%d\n",t);
    for(int i=0;i<t;i++){
        //家庭成员的最小编号 家庭人口数 人均房产套数 人均房产面积

        printf("%0.4d %d %.3f %.3f\n",fangzi[i].i,fangzi[i].p,(float)fangzi[i].f/fangzi[i].p,fangzi[i].a);
    }
    
}