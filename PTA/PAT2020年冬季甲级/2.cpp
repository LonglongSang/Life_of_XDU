#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main() {
    string str, sub, ans;
    int length = 1000000000;
    getline(cin, str);
    getline(cin, sub);
    for(int i = 0; i <= str.length() - sub.length(); i++) {
        if(str[i] != sub[0]) continue;
        int j = i;
        int k = 0;
        while( k < sub.length() && j - i < length) {
            if(str[j] == sub[k]){
                k++;
            }
            j++;
        }
        if( j - i < length) {
            length = j - i;
            ans = str.substr(i, j - i);
        }
    }
    cout << ans;
}
