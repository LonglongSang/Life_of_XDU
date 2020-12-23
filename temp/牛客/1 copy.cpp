//https://ac.nowcoder.com/acm/contest/10167/C
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
#include <string.h>
using namespace std;


const int N = 2e5 + 5, mod = 1e9 + 7;
int p[N];
struct node{
    int v, i;
    bool operator < (const node & A) const{
        return v < A.v;
    }
}d[N];
int fac[N], inv[N];
typedef long long LL;
LL z = 1;
int ksm(int a, int b, int p){
	int s = 1;
	while(b){
		if(b & 1) s = z * s * a % p;
		a = z * a * a % p;
		b >>= 1;
	}
	return s;
}
int C(int n, int m){
    return z * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param n int整型 
     * @param k int整型 
     * @param Point int整型vector 
     * @return int整型vector
     */
    vector<int> v;
    vector<int> city(int n, int k, vector<int>& Point) {
        // write code here
        fac[0] = 1;
        for(int i = 1; i <= n; i++) fac[i] = z * fac[i - 1] * i % mod;
        inv[n] = ksm(fac[n], mod - 2, mod);
        for(int i = n - 1; i >= 0; i--) inv[i] = z * inv[i + 1] * (i + 1) % mod;
        for(int i = 1; i <= n; i++) d[i] = {Point[i - 1], i};
        sort(d + 1, d + n + 1);
        int t = ksm(C(n, k), mod - 2, mod);
        for(int i = k; i <= n; i++){
            p[d[i].i] = z * C(i - 1, k - 1) * t % mod;
        }
        for(int i = 1; i <= n; i++) v.push_back(p[i]);
        return v;
    }
};









int main(){

}