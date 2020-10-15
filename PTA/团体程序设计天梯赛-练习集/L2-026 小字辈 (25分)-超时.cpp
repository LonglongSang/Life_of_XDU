#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;
int n,a,b;
int par[100005];
vector<int> ans;
int max_leve=0;
int find(int a){
    int cnt=1;
    while(par[a]!=-1){
        a=par[a];
        cnt++;
    }
    return cnt;
}
int main(){
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        par[i]=a;
    }
    for(int i=1;i<=n;i++){
        b=find(i);
        if(b>max_leve){
            max_leve=b;
            ans.resize(0);
            ans.push_back(i);
        }else if(b==max_leve){
            ans.push_back(i);
        }
    }
    printf("%d\n",max_leve);
    printf("%d",ans[0]);
    for(int i=1;i<ans.size();i++){
        printf(" %d",ans[i]);
    }
    printf("\n");
}