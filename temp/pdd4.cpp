#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
#define N 100000
int n,m;
int fa[N];
unordered_map<int,int> cnt;
vector<int> hello;
int getHelp(int value,int a)
{
    /*
    若value!(value的阶乘法)=(a**n)*q，本函数求的是n，**表示幂
    */
    if(a==1) return value;
    int tot=0;
    while(value)
    {
        tot+=value/a;
        value/=a;
    }
    return tot;
}

void primeInit()
{
    //素数初始化
    fa[1]=1;
    for(int i=2;i<N;i++)
    {
        if(fa[i]==0)
        {
            for(int j=i;j<N;j+=i) fa[j]=i;
        }
    }
}

void breakDown(int value)
{
    bool breaked=false;
    for(int i=2;i*i<=value && !breaked;i++)
    {
        if(value%i==0)
        {
            hello.push_back(i);
            if(value/i>=N)
            {
                
                breakDown(value/i);
            }else
            {
                hello.push_back(value/i);
                
            }
            breaked=true;
        }
    }
    if(!breaked) hello.push_back(value);
}
void breakToPrime(int v)
{
    //将v拆成素数相乘的模式，需要基于primeInit初始化的结果
    while(v!=1)
    {
        cnt[fa[v]]++;
        v/=fa[v];
    }
}
int main()
{
    primeInit();
    scanf("%d %d",&n,&m);
    int tot=1000000000;
    breakDown(m);
    /*
    把m拆成x1*x2*x3*x4*...*x5*(y1*y2*y3*...*yn)
    其中xi是小于N的素数或非素数，yi是大于等于N的素数
    */
    for(auto&x:hello)
    {
        if(x>=N)
        {
            //大于N，就是素数，不需要拆成素数
            cnt[x]++;
        }else
        {
            //小于N，可能不是素数，要拆成素数
            breakToPrime(x);//将xi拆成素数
        }
    }

    //若m=(p1**e1)*(p2**e2)*...*(pn**en);
    //pi表示素数，ei表示pi出现的次数
    //那么这些元素可以生成一个0


    for(auto&e:cnt)
    {
        int q=getHelp(n,e.first);
        tot=min(tot,q/e.second);
    }
    printf("%d\n",tot);
}