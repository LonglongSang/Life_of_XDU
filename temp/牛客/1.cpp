#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;



#define N 100000

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param x string字符串 
     * @return int整型
     */
    int Maximumlength(string x) {
        // write code here
        int n=x.length();
        int low=0,high=3/n,mid,ans=0;
        while(high>=low){
            mid=(low+high)/2;
            int cur=0,cnt=0;
            for(int i=0;i<n && cur!=3;i++){
                if(x[i]-'a'==cur) cnt++;
                if(cnt==mid) cur++,cnt=0;
            }
            if(cur==3){
                low=mid+1;
                ans=mid;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};
















int main(){

}