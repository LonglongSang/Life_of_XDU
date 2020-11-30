#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
//http://acm.xidian.edu.cn/problem.php?cid=1068&pid=1
using namespace std;
using ll=long long;
int n,k,t;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        printf("%d\n",n%k);
        for(int i=0,j=n%k;i<j;i++){
            if(i) printf(" ");
            printf("%d",n-j+i+1);
        }
        if(n%k) printf("\n");
    }
    return 0;
}


