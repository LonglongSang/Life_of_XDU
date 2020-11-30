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
char name1[20],name2[20],name3[20];
bool good;
int main(){
    int i=1;
    while(1){
        scanf("%s",name1);
        getchar();
        if(strcmp(name1,".")==0) break;
        if(i==2){
            strcpy(name2,name1);
            good=true;
        }else if(i==14){
            printf("%s and %s are inviting you to dinner...\n",name2,name1);
            return 0;
        }
        i++;
    }
    if(good){
        printf("%s is the only one for you...\n",name2);
    }else{
        printf("Momo... No one is for you ...\n");
    }
    return 0;

}
