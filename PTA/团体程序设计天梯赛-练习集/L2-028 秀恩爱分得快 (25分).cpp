#include <stdio.h>
#include <iostream>
#include <vector>
#include  <unordered_set>
#include <set>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <ctype.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define abs(a) (a>0?a:-a)
using namespace std;
int n,m;
int path[1000][1000];
double dist_a[1000],dist_b[1000];
bool is_male[1005];
char line[100];
int k[1000];
int read(){
    bool male=true;
    int ans=0;
    scanf("%s",line);
    if(line[0]=='-') male=false;
    for(int i=male?0:1;line[i];i++){
        ans=ans*10+line[i]-'0';
    }
    is_male[ans]=male;
    return ans;
}
vector<int> ans1;
vector<int> ans2;
void get_ans(int a,double* dist,vector<int>& ans){
    double max_val=0.0;
    for(int i=0;i<n;i++){
        if(is_male[a]==is_male[i]) continue;
        if(dist[i]>max_val){
            ans.resize(0);
            max_val=dist[i];
            ans.push_back(i);
        }else if(max_val==dist[i]){
            ans.push_back(i);
        }
    }
    sort(ans.begin(),ans.end());
}
void pri(int a,int b){
    if(is_male[a]) printf("%d -%d\n",a,b);
    else printf("-%d %d\n",a,b);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d",&k[i]);
        path[i][0]=read();
        for(int j=1;j<k[i];j++){
            path[i][j]=read();
        }
    }
    int a=3,b=2;
    a=read();
    b=read();
    for(int i=0;i<m;i++){
        int index_a=-1;
        int index_b=-1;
        for(int j=0;j<k[i];j++){
            if(path[i][j]==a) index_a=j;
            if(path[i][j]==b) index_b=j;
        }
        if(index_a!=-1){
            for(int j=0;j<k[i];j++) dist_a[path[i][j]]+=1.0/k[i];
        }
        if(index_b!=-1){
            for(int j=0;j<k[i];j++) dist_b[path[i][j]]+=1.0/k[i];
        }        
    }
    dist_a[a]=0.0;
    dist_b[b]=0.0;
    get_ans(a,dist_a,ans1);
    get_ans(b,dist_b,ans2);
    
    if(ans1.size() && ans2.size() && dist_a[b]==dist_a[ans1[0]] && dist_a[b]==dist_b[ans2[0]]){
        pri(a,b);
        return 0;
    }
    for(int i=0;i<ans1.size();i++) pri(a,ans1[i]);
    for(int i=0;i<ans2.size();i++) pri(b,ans2[i]);

    return 0;
}