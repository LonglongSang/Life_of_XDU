#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <functional>
#include <time.h>
#include <unordered_map>
#include <string>

using namespace std;
using ll=long long;


/*
ll dp[1004];
class Solution {
public:
    int numDistinct(string s, string t) {
        for(int i=0;i<1004;i++) dp[i]=1;
        for(int i=0;i<t.length();i++){  
            for(int j=s.length()-1;j>=0;j--){
                if(t[i]==s[j]) dp[j+1]=dp[j];
                else dp[j+1]=0;
            }
            dp[0]=0;
            for(int j=0;j<s.length();j++) dp[j+1]+=dp[j];
        }
        return dp[s.length()];
    }
};
*/

ll dp[1005][1005];
//dp[i+1][j+1]表示的是字符串s.substr(0,i)的子串中有多少个t.substr(0,j);
class Solution {
public:
    int numDistinct(string s, string t) {
        for(int i=0;i<s.length();i++){
            for(int j=0;j<t.length();j++){
                if(s[i]==t[j]){
                    dp[i+1][j+1]+=dp[i][j];
                }
            }
        }
        return dp[s.length()][t.length()];
    }
};