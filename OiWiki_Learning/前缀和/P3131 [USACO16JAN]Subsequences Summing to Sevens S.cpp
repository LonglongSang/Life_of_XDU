/*
P3131 [USACO16JAN]Subsequences Summing to Sevens S
https://www.luogu.com.cn/problem/P3131
给你n个数，分别是a[1],a[2],...,a[n]。求一个最长的区间[x,y]，
使得区间中的数(a[x],a[x+1],a[x+2],...,a[y-1],a[y])的和能被7整除。
输出区间长度。若没有符合要求的区间，输出0。
输入：The first line of input contains NN (1 \leq N \leq 50,0001≤N≤50,000). 
The next N lines each contain the NN integer IDs of the cows 
*/
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a>b?a:b)
int main(void){
    int n,cur,cnt[7],total=0,ans=0;
    for(int i=0;i<7;i++) cnt[i]=-1;
    cnt[0]=0;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        scanf("%d\n",&cur);
        total=(total+cur)%7;
        if(cnt[total]!=-1){
            ans=max(ans,i-cnt[total]);    
        }else{
            cnt[total]=i;
        }
    }
    printf("%d\n",ans);
    return 0;
}


