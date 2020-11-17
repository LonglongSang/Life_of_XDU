#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
using namespace std;
int n,m,k,cnt;
char v;
int main(){
    scanf("%d\n",&n);
    for(int i=0;i<4;i++){
        if(i) printf(" ");
        int acc=0;
        int total=0;
        //时间翻倍
        for(int j=0;j<n;j++){
            v=getchar();
            switch(v){
                case '.':{
                    if(acc>=1) total++;
                    else total+=2;
                    acc=max(0,acc-1);
                    break;
                }
                case 'w':{
                    if(acc>=2) total+=2;
                    else if(acc==1) total+=3;
                    else total+=4;
                    acc=max(0,acc-2);
                    break;
                }
                case '>':{
                    acc=9;
                    total++;
                    break;
                }
                case 's':{
                    total+=2;
                    acc=max(0,acc-2);
                    if(acc>=1) total++;
                    else total+=2;
                    acc=max(0,acc-1);
                    break;
                }
                case 'm':{
                    total+=4;
                    acc=max(0,acc-4);
                    if(acc>=1) total++;
                    else total+=2;
                    acc=max(0,acc-1);
                    break;
                }
            }
        }
        getchar();
        printf("%.1f",(float)total/2);
    }
    return 0;
}