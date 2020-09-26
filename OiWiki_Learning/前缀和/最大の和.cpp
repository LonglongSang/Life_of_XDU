/*https://vjudge.net/problem/AtCoder-joi2007ho_a#author=wuyudi
读入 n 个整数的数列 a1，a2，…，an 和正整数 k（1<=k<=n），请输出连续排列的 k 个整数的和的最大值
输入：第一行是正整数 n (1<=n<=100000) 和正整数 k（1<=k<=n） 第二行以后的第 1+i（1<=i<=n）至最后一行为数列
输出：仅一行，仅包括最大值。
*/
#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a>b?a:b)
int main(void){
    int n,k;
    scanf("%d %d\n",&n,&k);
    int q[k],front=0,rear=0,total=0,cur;
    for(int i=0;i<k;i++){
        scanf("%d\n",q+i);
        total+=q[rear++];
    }
    int ans=max(0,total);
    for(int i=k;i<n;i++){
        scanf("%d\n",&cur);
        total-=q[(front++)%k];
        total+=(q[(rear++)%k]=cur);
        ans=max(ans,total);
    }
    printf("%d\n",ans);
    return 0;
}


