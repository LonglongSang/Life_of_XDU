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
#define N 1005
int n,cnt,ti[N],id,h,m,total;
bool jiechu[N];
char typ;
int gettime(){
    return h*60+m;
}
int main(){
    scanf("%d",&n);
    getchar();
    while(n){
        scanf("%d %c %d:%d",&id,&typ,&h,&m);
        getchar();
        if(id==0){
            printf("%d %.0lf\n",cnt,cnt==0?0.0:((double)total/(double)cnt));
            n--;
            if(n==0) return 0;
            memset(jiechu,0,N);
            memset(ti,0,N*4);
            total=0,cnt=0;
            continue;
        }
        if(typ=='S'){
            ti[id]=gettime();
            jiechu[id]=true;
        }else if(typ=='E'){
            if(jiechu[id]){
                cnt++;
                total+=gettime()-ti[id];
                jiechu[id]=false;
            }
        }
    }
    return 0;
}
