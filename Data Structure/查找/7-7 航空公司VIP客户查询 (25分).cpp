//https://blog.csdn.net/kid1402/article/details/109649815
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <unordered_map>
using namespace std;
int n,m,v,x,k,a,cnt=2;
#define N 1000005
int trie[N][12];
int mp(char a){
    return isdigit(a)?(a-'0'):10;
}
char path[19];
int main(){
    scanf("%d %d\n",&n,&k);
    int root=1;
    int step;
    int rel;
    for(int i=0;i<n;i++){
        scanf("%s %d\n",path,&a);
        step=0;
        root=1;
        while(step!=18){
            rel=mp(path[step]);
            if(!trie[root][rel]) trie[root][rel]=cnt++;
            root=trie[root][rel];
            step++;
            if(step==18) trie[root][11]+=a<k?k:a;
        }
    }
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%[^\n]\n",path);
        step=0;
        root=1;
        while(step!=18){
            rel=mp(path[step]);
            if(!trie[root][rel]){
                printf("No Info\n");
                break;
            }
            root=trie[root][rel];
            step++;
            if(step==18) printf("%d\n",trie[root][11]);
        }
    }
    return 0;
}