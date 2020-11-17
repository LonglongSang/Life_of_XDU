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
int n,m,a,b,cnt;
#define N 100005
int coup[N],temp[N];
bool coming[N];
int main(){
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d\n",&a,&b);
        coup[a+1]=b+1;
        coup[b+1]=a+1;
    }
    scanf("%d\n",&m);
    for(int i=0;i<m;i++){
        scanf("%d",temp+i);
        temp[i]++;
        coming[temp[i]]=true;
        getchar();
    }
    for(int i=0;i<m;i++){
        if(coup[temp[i]]==0 || !coming[coup[temp[i]]]) temp[cnt++]=temp[i];
    }
    printf("%d\n",cnt);
    sort(temp,temp+cnt);
    if(cnt) printf("%0.5d",temp[0]-1);
    for(int i=1;i<cnt;i++) printf(" %0.5d",temp[i]-1);
    return 0;
}