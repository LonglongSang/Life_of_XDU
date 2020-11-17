#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#define N 200005
int h[N],pos[N],cnt,n,m,v,x,y;
/*
5 4
46 23 26 24 10
24 is the root
26 and 23 are siblings
46 is the parent of 23
23 is a child of 10
*/
int offset=10005;
void insert(int v){
    h[++cnt]=v;
    int i=cnt;
    pos[h[i]+offset]=i;
    while(i!=1 && h[i]<h[i/2]){
        swap(h[i],h[i/2]);
        pos[h[i]+offset]=i;
        pos[h[i/2]+offset]=i/2;
        i/=2;
    }
    //for(int i=1;i<=cnt;i++) printf("%d ",h[i]);
    //printf("\n");
}

char a[10],b[10],c[10],d[10],e[10],f[10];
int toint(char* a){
    int ans=0;
    bool neg=false;
    if(*a=='-') a++,neg=true;
    while(*a) ans=ans*10+*a-'0',a++;
    return neg?-ans:ans;
}
int main(){
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&v);
        getchar();
        insert(v);
    }
    for(int i=0;i<m;i++){
        scanf("%s %s %s %s",a,b,c,d);
        //printf("%s %s %s %s\n",a,b,c,d);
        getchar();
        if(strcmp(d,"root")!=0) scanf("%s",e),getchar();
        if(strcmp(d,"root")==0){
            x=toint(a);
            if(cnt && x==h[1]) printf("T\n");
            else printf("F\n");
        }else if(strcmp(d,"are")==0){
            x=toint(a),y=toint(c);
            if(cnt>=2 && (pos[x+offset]/2==pos[y+offset]/2)) printf("T\n");
            else printf("F\n");
        }else{
            scanf("%s",f);
            getchar();
            x=toint(a),y=toint(f);
            if(strcmp(d,"child")==0) swap(x,y);
            if(cnt>=2 && pos[y+offset]/2==pos[x+offset]) printf("T\n");
            else printf("F\n");
        }
    }
}