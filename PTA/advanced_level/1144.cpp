#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <queue>
using namespace std;
int cnt[100002];
int main(){
    int n,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        if(temp<1 || temp >100001) continue;
        cnt[temp]++;
    }
    for(int i=1;i<100002;i++){
        if(!cnt[i]){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}