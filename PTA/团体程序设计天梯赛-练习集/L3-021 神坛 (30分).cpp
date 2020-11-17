#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
using namespace std;
using ll=long long;
struct edge{
    ll x,y;
}e[5000];
int n;
unordered_map<ll,int> gongxian1,gongxian2;
unordered_set<ll> same;
ll index(int x,int y){
    return (ll)x*100000000+(ll)y;
}
double changdu(int i,int j){
    return sqrt((e[i].x-e[j].x)*(ll)(e[i].x-e[j].x)+(e[i].x-e[j].x)*(e[i].x-e[j].x));
}
double area(int i,int j,int k){
    double a=changdu(i,j);
    double b=changdu(i,k);
    double c=changdu(j,k);
    double s=(a+b+c)*0.5;
    return s*(s-a)*(s-c)*(s-b);
}
int main(){
    scanf("%d\n",&n);
    bool stop=false;
    ll temp;
    for(int i=0;i<n;i++){
        scanf("%lld %lld\n",&e[i].x,&e[i].y);
        gongxian1[e[i].x]++;
        if(gongxian1[e[i].x]==3) stop=true;
        gongxian2[e[i].y]++;
        if(gongxian2[e[i].y]==3) stop=true;
        temp=index(e[i].x,e[i].y);
        if(same.find(temp)!=same.end()) stop=true;
        same.insert(temp);
        if(stop) break;
    }
    if(stop){
        printf("0.000\n");
        return 0;
    }
    double ans=1000000000000.0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                ans=min(ans,area(i,j,k));
            }
        }
    }
    printf("%.3lf\n",ans);
}
