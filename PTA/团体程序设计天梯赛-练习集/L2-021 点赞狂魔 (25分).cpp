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
int n,k,a;
string name;
struct node{
    string name;
    int num;
    double avg;
    bool operator < (const node&a)const{
        if(num!=a.num) return num<a.num;
        else return avg>a.avg;
    }
    node(string _name,int _num,double _avg): name(_name),num(_num),avg(_avg){}
};
struct cmp{
    bool operator () (const node&a,const node&b)const{
        if(a.num!=b.num) return a.num>b.num;
        else return a.avg<b.avg;    
    }    
};

int main(){
    priority_queue<node,vector<node>,cmp> Q;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>name;
        cin>>k;
        unordered_set<int> vis;
        for(int j=0;j<k;j++){
            cin>>a;
            vis.insert(a);
        }
        node now(name,vis.size(),(double)k/vis.size());
        if(Q.size()<3){
            Q.push(now);
        }else if(Q.top()<now){
            Q.pop();
            Q.push(now);
        }
        
    }
    int cnt=0;
    stack<string> S;
    while(!Q.empty()){
        S.push(Q.top().name);
        Q.pop();
    }
    while(!S.empty()){
        if(cnt++) cout<<" "<<S.top();
        else cout<<S.top();
        S.pop();
    }
    for(int i=cnt;i<3;i++){
        if(i) cout<<" -";
        else cout<<"-";
    }
    cout<<endl;
    return 0;
}