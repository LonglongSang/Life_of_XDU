#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <ctype.h>
using namespace std;
#define N 10005
int cnt[100];
struct node{
    int product;
    vector<vector<int>> from;
	//from[i]中的元素能够合成一个product
}arr[100];
int tot,n,m,v,k;
char s[10000];
int temp[1000],ans[1000];
unordered_map<int,int> mp;
bool ok;//标记是否已经找到答案
void build(){//处理equation的函数
	//00 + 01 -> 02
    int cnt=0,i=0,v;
    while(s[i]){
        if(isdigit(s[i])){
            v=0;
            while(s[i] && isdigit(s[i])) v=v*10+s[i++]-'0';
            temp[cnt++]=v;
        }else{
            i++;
        }
    }
    int tar=temp[cnt-1];
    if(mp.find(tar)==mp.end()) return;
    arr[mp[tar]].from.push_back({});
    for(int i=0;i<cnt-1;i++) arr[mp[tar]].from.back().push_back(temp[i]);
}
void sorting(){//排序
	//对能合成arr[i].product的原料进行字典序排序
    for(int i=0;i<n;i++){
        sort(arr[i].from.begin(),arr[i].from.end(),[](const vector<int>&a,const vector<int>&b){
            for(int i=0,m=min((int)a.size(),(int)b.size());i<m;i++){
                if(a[i]!=b[i]) return a[i]<b[i];
            }
            return a.size()<b.size();
        });
    }
}

void add(int i,int j,int add){
    for(auto&v:arr[i].from[j]){
        cnt[v]+=add;
    }    
}
bool isok(int i,int j){//检查能否向下递归
    for(auto&v:arr[i].from[j]){
        if(cnt[v]==0) return false;
    }
    return true;
}
void dfs(int step){//深度搜索
    if(step==n){
        for(int i=0;i<n;i++) ans[i]=temp[i];
        ok=true;
        return;
    }
    for(int i=0,m=arr[step].from.size();i<m && !ok;i++){
        if(!isok(step,i)) continue;
        temp[step]=i;
        add(step,i,-1);
        dfs(step+1);
        add(step,i,1);
    }
}
void pri(int index){//输出函数
    int i=0;
    for(auto &v:arr[index].from[ans[index]]){
        if(i++) printf(" + ");
        printf("%0.2d",v);
    }
    printf(" -> %0.2d\n",arr[index].product);
}
int main(){
    //freopen("C:\\Users\\Administrator\\Desktop\\PAT\\input.txt","r+",stdin);

    scanf("%d",&m);
    getchar();
    for(int i=0;i<m;i++){//拥有的
        scanf("%d",&v);
        getchar();
        cnt[v]++;
    }
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){//想要产生的
        scanf("%d",&arr[i].product);
        mp[arr[i].product]=i;
        getchar();
        arr[i].from.push_back({arr[i].product});
    }
    scanf("%d",&k);
    getchar();
    for(int i=0;i<k;i++){
        scanf("%[^\n]",s);
        getchar();
        build();
    }
    sorting();
    dfs(0);
	
    for(int i=0;i<n;i++) pri(i);
    return 0;
}