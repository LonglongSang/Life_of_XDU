#include <stdio.h>
#include <iostream>
#include <vector>
#include  <unordered_set>
#include <set>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <ctype.h>
#include <queue>
#include <stack>
#include <string>
using namespace std;
/*统计每个人点赞的不同标签的数量，找出数量最大的前3名，在一行中顺序输出他们的用户名,其间以1个空格分隔,且行末不得有多余空格。
如果有并列，则输出标签出现次数平均值最小的那个，题目保证这样的用户没有并列。若不足3人，则用-补齐缺失，例如mike jenny -就表示只有2人。
*/
short n,k,a,first,second;
bool vis[10005];
short par[10005];
short find(short a){
    while(par[a]!=0 && par[a]!=a){
        a=par[a];
    }
    return a;
}
void uniona(short a,short b){
    short _a=find(a);
    short _b=find(b);
    if(_a!=_b){
        if(_b>_a) swap(_a,_b);
        par[_a]=_b;
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        cin>>first;
        vis[first]=true;
        for(int j=1;j<k;j++){
            cin>>second;
            vis[second]=true;
            uniona(first,second);
        }
    }
    short total=0,cnt=0;
    for(int i=1;i<10005;i++){
        par[i]=find(i);
    }
    for(int i=1;i<10005;i++){
        total+=vis[i];
        if(vis[i] && (par[i]==i || par[i]==0)) cnt++;
    }
    cout<<total<<" "<<cnt<<endl;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>first>>second;
        if(par[first]==par[second]) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}