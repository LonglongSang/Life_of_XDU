//https://www.luogu.com.cn/problem/P2880
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 50005
#define X 31
int n,m,a,b,t,lg,low[N][16],high[N][16],bin[X],lg2[N];
int max_one(int &a,int &b){
    return a>b?a:b;
}
int min_one(int &a,int &b){
    return a>b?b:a;
}
void build(){
    for(int i=1;i<=lg2[n];i++){
        //列
        for(int j=1;j<=n;j++){
            //行
            if(j+bin[i]-1<=n){
                low[j][i]=min(low[j][i-1],low[j+bin[i-1]][i-1]);
                high[j][i]=max(high[j][i-1],high[j+bin[i-1]][i-1]);
            }
        }
    }
}
void build_dependency(){
    bin[0]=1;
    for(int i=1;i<X;i++) bin[i]=bin[i-1]*2;
    lg2[0]=-1;
    for(int i=1;i<N;i++) lg2[i]=lg2[i/2]+1;
}
int main(){
    scanf("%d %d\n",&n,&m);
    build_dependency();
    for(int i=1;i<=n;i++){
        scanf("%d\n",&low[i][0]);
        high[i][0]=low[i][0];
    }
    build();
    for(int i=0;i<m;i++){
        scanf("%d %d\n",&a,&b);
        t=b-a+1,lg=lg2[t];
        printf("%d\n",max(high[a][lg],high[b-bin[lg]+1][lg])-min(low[a][lg],low[b-bin[lg]+1][lg]));
    }
    return 0;
}