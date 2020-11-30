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
int n,num[100],al[100],cnt,total,seat[100][100],x=1;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",num+i);
        num[i]*=10;
        total+=num[i];
    }
    while(cnt!=total){
        for(int i=0;cnt!=total;i++){
            for(int j=0;j<n;j++){
                if(al[j]==num[j]) continue;
                if(al[j] && x-seat[j][al[j]-1]<=1) seat[j][al[j]]=x=seat[j][al[j]-1]+2;
                else  seat[j][al[j]]=x++;
                al[j]++;
                cnt++;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("#%d\n",i+1);
        for(int j=0;j<num[i];j++){
            if(j && j%10==0) printf("\n");
            if(j%10) printf(" ");
            printf("%d",seat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
