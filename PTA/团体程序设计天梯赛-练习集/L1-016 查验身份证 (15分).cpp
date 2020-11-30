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
int n,cnt;
char id[20];
int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int mapping[11]={'1','0','X','9','8','7','6','5','4','3','2'};
bool check(){
    int ans=0;
    for(int i=0;i<17;i++) ans+=weight[i]*(id[i]-'0');
    return id[17]==mapping[ans%11];
}
char bad[100][20];
int main(){
    scanf("%d",&n);
    getchar();
    while(n--){
        scanf("%s",id);
        getchar();
        if(!check()){
            strcpy(bad[cnt++],id);
        }
    }
    if(cnt==0) printf("All passed\n");
    else{
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i++) printf("%s\n",bad[i]);
    }
}
