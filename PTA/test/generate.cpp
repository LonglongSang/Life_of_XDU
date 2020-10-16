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
int n,a;
map<int,int> dp;

int main(){
    freopen("G:\\Life_of_XDU\\PTA\\test\\data","w",stdout);
    int n=100000;
    printf("%d\n",n);
    for(int i=0;i<n-1;i++) printf("%d ",rand()%1000000000);
    printf("%d\n",rand()%1000000000);

    return 0;
} 