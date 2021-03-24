#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    int* k=new int[n];
    if(k==nullptr) printf("new failed\n");
    else printf("new success\n");
    if(k==nullptr) return 1;
    srand(time(0));
    for(int i=0;i<n;i++) k[i]=rand()%100;
    printf("%.2lfMB\n",(double)sizeof(int)*n/1024/1024);
    printf("%.2lfMB\n",(double)sizeof(int)*n/1000/1000);
    printf("%d\n",k[100000]);

    getchar();
    getchar();
    printf("will delete");
    delete []k;
    getchar();
}