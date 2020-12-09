#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
#define N 10000
#define M 200


/*
铁子们，有一个题，我们有一个字符串集合words，其中每个字符串word都是小写字母组成（非空）并且有一个权值，现在我们想要将一个字符串tar拆分成k个字符串a1、a2、...、ak
使得a1+a2+...+ak=tar，并且ai均来自于words，请返回一个整数使得拆分后的权值和最大，如果不存在请返回-1
数据范围（盲猜）：
words.size()<100
words[i].length()<20
tar.length()<10000
1<=k<=word.size()
*/
int dp[N][M];

int dfs(unordered_map<string,int> &words,string tar,int k){
    //将tar拆分为from中的k个字符串能获得的最大值
    int n=tar.length();
    for(int i=0;i<n+1;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=-1;
        }
    }
    dp[0][0]=0;

    for(int t=0;t<k;t++){
        //迭代k次
        for(auto &s:words){
            //对from中的字符串进行迭代
            int m=s.first.length();
            for(int i=m;i<=n;i++){
                //对每个位置可能的进行迭代
                bool good=true;
                for(int x=0;x<m && good;x++){
                    if(s.first[x]!=tar[i-m+x]) good=false;
                }
                if(!good) continue;
                for(int j=0;j<k;j++){
                    //对每种可能进行迭代
                    if(dp[i-m][j]==-1) continue;
                    dp[i][j+1]=max(dp[i][j+1],dp[i-m][j]+s.second);
                    //cout<<i<<" "<<j+1<<" "<<dp[i][j+1]<<endl;
                }
            }
        }
    }

    return dp[n][k];
}
int main ()
{
    unordered_map<string,int> words;
    words["aab"]=1;
    words["baa"]=2;
    words["abc"]=3;
    words["aa"]=3;
    words["bb"]=12213;
    words["a"]=1;
    string tar="aabbaa";
    int ans=dfs(words,tar,3);
    cout<<ans<<endl;
  return 0;
}