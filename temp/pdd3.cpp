#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string.h>
using namespace std;
int k,n;
char s[1000005];
int input()
{
    int i=0;
    while((s[i]=getchar())!=EOF && s[i]!='\n')
    {
        i++;
    }
    return i;
}
int cnt[128];
int func()
{
    int tot=0;
    int pos=-1;
    for(int i=0;i<n;i++)
    {
        cnt[s[i]]++;
        if(cnt[s[i]]%k==1)
        {
            tot++;
        }
        if(tot*k<n) pos=i+1;
        else if(tot*k==n)
        {
            bool good=false;
            if(i+1==n) good=true;
            else
            {
                for(char j='a';j<=s[i+1] && !good;j++)
                {
                    if((cnt[j]+1)%k==0) good=true;
                }
            }
            if(good) pos=i+1;
            else break;
        }else
        {
            break;
        }
    }
    return pos;
}
void process(int pos)
{
    if(pos==n) return;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<pos;i++) cnt[s[i]]++;
    int tot=0;
    for(int i=0;i<128;i++)
    {
        tot+=cnt[i]/k+(cnt[i]%k?1:0);
    }
    for(int j=0;j<n-tot*k;j++) cnt['z']++;
    for(char j=s[pos]-1;j>='a';j--)
    {
        if(cnt[j]){
            s[pos++]=j;
            cnt[j]--;
            break;
        }
    }
    for(char j='z';j>='a';j--)
    {
        while(cnt[j])
        {
            s[pos++]=j;
            cnt[j]--;
        }
    }
    s[n]=0;

    
}
int main()
{
    scanf("%d",&k);
    getchar();
    n=input();
    if(n%k!=0)
    {
        printf("%d\n",-1);
        return 0;
    }else if(k==1)
    {
        printf("%s\n",s);
        return 0;
    }
    process(func());
    s[n]=0;
    printf("%s\n",s);
    return 0;
}