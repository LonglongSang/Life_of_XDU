#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;



int dp[1000][128];
class Solution {
public:
    /**
     * 
     * @param k int整型 表示最多的操作次数
     * @param s string字符串 表示一个仅包含小写字母的字符串
     * @return int整型
     */
    bool ok(char v,int index,string &s){
        if((index==0 || v==s[index-1]) && (index+1==s.length() || s[index+1]==v)) return true;
        return false;
    }
    int string2(int k, string s) {
        int ans=0,n=s.length();
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                dp[i+1][s[i]]=max(dp[i+1][s[i]],dp[j][s[i]]+1),ans=max(ans,dp[i+1][s[i]]);
                if(s[i]+1<='z' && ok(s[i]+1,i,s)) dp[i+1][s[i]+1]=max(dp[i+1][s[i]+1],dp[j][s[i]+1]+1),ans=max(ans,dp[i+1][s[i]+1]);
                if(s[i]-1>='a' && ok(s[i]-1,i,s)) dp[i+1][s[i]-1]=max(dp[i+1][s[i]-1],dp[j][s[i]-1]+1),ans=max(ans,dp[i+1][s[i]-1]);
            }

        }
        return ans;
    }

};






int main(){

}







