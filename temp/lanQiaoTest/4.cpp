#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int dfs(int step,int last){
    if(step==5) return 1;
    int sum=0;
    for(int i=last;i<=10;i++){
        sum+=dfs(step+1,i);
    }
    return sum;
}
int main(){
    cout<<dfs(0,1);

}