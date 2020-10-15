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
//后中
/*
按照收入金额从高到低的递减顺序输出每个人的编号和收入金额（以元为单位，输出小数点后2位）。
每个人的信息占一行，两数字间有1个空格。如果收入金额有并列，则按抢到红包的个数递减输出；
如果还有并列，则按个人编号递增输出。
*/
/*
10
3 2 22 10 58 8 125
5 1 345 3 211 5 233 7 13 8 101
1 7 8800
2 1 1000 2 1000
2 4 250 10 320
6 5 11 9 22 8 33 7 44 10 55 4 2
1 3 8800
2 1 23 2 123
1 8 250
4 2 121 4 516 7 112 9 10
*/
struct node{
    int index;
    int time;
    int get;
}arr[10005];
int n,k,p,g;
int main(){
    scanf("%d\n",&n);
    for(int i=0;i<n;i++) arr[i].index=i+1;
    for(int i=0;i<n;i++){
        scanf("%d ",&k);
        int sum=0;
        //cout<<k<<endl;
        for(int j=0;j<k;j++){
            scanf("%d %d",&p,&g);
            getchar();
            sum+=g;
            arr[p-1].time++;
            arr[p-1].get+=g;
        }
        arr[i].get-=sum;
        
    }
    sort(arr,arr+n,[](const node&a,const node&b){
        if(a.get!=b.get) return a.get>b.get;
        else if(a.time!=b.time) return a.time>b.time;
        else return a.index<b.index;
    });
    for(int i=0;i<n;i++){
        printf("%d %.2f\n",arr[i].index,(float)arr[i].get/100);
    }
}