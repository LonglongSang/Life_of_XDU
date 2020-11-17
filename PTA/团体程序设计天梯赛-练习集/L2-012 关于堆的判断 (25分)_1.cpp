#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <unordered_map>
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
    //pos[h[i]+offset]=i;
    while(i!=1 && h[i]<h[i/2]){
        swap(h[i],h[i/2]);
        //pos[h[i]+offset]=i;
        //pos[h[i/2]+offset]=i/2;
        i/=2;
    }
    h[i]=v;
    //for(int i=1;i<=cnt;i++) printf("%d ",h[i]);
    //printf("\n");
}
#define p 100
string a,b,c,d,e,f;
int toint(string &a){
    int ans=0;
    for(int i=a[0]=='-'?1:0;i<a.length();i++) ans=ans*10+a[i]-'0';
    return a[0]=='-'?-ans:ans;
}
unordered_map<int,int> mp;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>v;
        insert(v);
    }
    for(int i=1;i<=n;i++) mp[h[i]]=i;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c>>d;
        if(d!="root") cin>>e;
        if(d=="root"){
            x=toint(a);
            if(cnt && mp[x]==1) printf("T\n");
            else printf("F\n");
        }else if(d=="are"){
            x=toint(a),y=toint(c);
            if(cnt>=2 && mp[x]/2==mp[y]/2) printf("T\n");
            else printf("F\n");
        }else{
            cin>>f;
            x=toint(a),y=toint(f);
            if(d=="child") swap(x,y);
            if(cnt>=2 && mp[y]/2==mp[x]) printf("T\n");
            else printf("F\n");
        }
    }
}