#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define N 100
using namespace std;
char lef[1000],righ[1000];
int temp[N*2+5];
void mul(char*m,char* s,char* a){
    if(m[0]=='0' || s[0]=='0'){
        strcpy(a,m);
        return;
    }
    memset(temp,0,8*N+20);
    int len1=strlen(s),len2=strlen(m);
    for(int i=0;s[i];i++){
        if(s[i]=='0') continue;
        for(int j=0;m[j];j++){
            temp[len1-i-1+len2-j-1]+=(m[j]-'0')*(s[i]-'0');
        }
    }
    int upper=len1+len2-1;
    int add=0;
    int i=0;
    while(i<upper || add!=0){
        int t=temp[i]+add;
        //cout<<t<<endl;
        a[i]=t%10+'0';
        add=t/10;
        i++;
    }
    a[i]=0;
    reverse(a,a+strlen(a));
    printf("%s",a);

    
}
int main(){
    char a[N];
    char b[N];
    char c[N];
    char d[N];
    while(scanf("%s %s %s %s\n",a,b,c,d)!=EOF){
        mul(a,d,lef);
        mul(b,c,righ);
        int val=strcmp(lef,righ);
        if(val==0) printf("=\n");
        else if(val>0) printf("<\n");
        else printf(">\n");
    }
}