#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int h[100000],cnt;
void insert(int v){
    h[++cnt]=v;
    int i=cnt;
    while(i!=1 && h[i]>h[i/2]){
        swap(h[i],h[i/2]);
        i=i/2;
    }
}
bool empty(){
    return cnt==0;
}
void pop(){
    swap(h[1],h[cnt--]);
    int i=1;
    while(i*2<=cnt){
        int j=i*2;
        if(j+1<=cnt && h[j+1]>h[j]) j++;
        if(h[i]==h[j]) break;
        swap(h[i],h[j]);
        i=j;
    }
}

int main(){
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        int v=rand()%100;
        printf("insert %d\n",v);
        insert(v);
        for(int j=1;j<=cnt;j++) printf("%d ",h[j]);
        printf("\n");
    }

}