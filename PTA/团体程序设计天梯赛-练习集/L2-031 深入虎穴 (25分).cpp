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
int n,cnt,k,from,to;
int head[100005];
bool indeg[100005];
struct node{
    int next;
    int to;
}arr[100005];
void add(){
    arr[++cnt].to=to;
    arr[cnt].next=head[from];
    head[from]=cnt;
}
int main(){
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        getchar();
        from=i;
        for(int j=0;j<k;j++){
            scanf("%d",&to);
            getchar();
            indeg[to]=true;
            add();
        }
    }
    int root=1;
    for(int i=1;i<=n;i++){
        if(!indeg[i]){
            root=i;
            break;
        }
    }
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        root=Q.front();
        Q.pop();
        for(int i=head[root];i;i=arr[i].next){
            Q.push(arr[i].to);
        }
    }
    cout<<root<<endl;
    return 0;
}