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
char cai[10];
int main(){
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        scanf("%s",cai);
        getchar();
        if(cai[0]+cai[1]+cai[2]==cai[3]+cai[4]+cai[5]){
            printf("You are lucky!\n");
        }else{
            printf("Wish you good luck.\n");
        }
    
    }
}
