#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int n,m;
#define N 100005
//vector<int> stop[N];
//vector<int> bus[N];
int dist[N];
struct q
{
    int cur;
    int next;
}stop[N*2],bus[N*2];
int stopHead[N],busHead[N];
int stopCnt,busCnt;
void addStop(int a,int b)
{
    stop[++stopCnt].next=stopHead[a];
    stop[stopCnt].cur=b;
    stopHead[a]=stopCnt;
}
void addBus(int a,int b)
{
    bus[++busCnt].next=busHead[a];
    bus[busCnt].cur=b;
    busHead[a]=busCnt;
}
struct node
{
    int stop;
    int bus;
    int cost;
    bool operator<(const node&b)const
    {
        return cost>b.cost;
    }
};
int main()
{
    int t,a;
    memset(dist,0x3f,sizeof(dist));
    scanf("%d %d",&n,&m);
    getchar();
    for(int i=0;i<m;i++)
    {
        scanf("%d",&t);
        getchar();
        for(int j=0;j<t;j++)
        {
            scanf("%d",&a);
            getchar();
            addStop(a,i);
            addBus(i,a);
        }
    }
    priority_queue<node,vector<node>> Q;
    Q.push({1,-1,0});
    node cur;
    while(!Q.empty())
    {
        cur=Q.top();
        Q.pop();
        if(cur.cost>=dist[cur.stop]) continue;
        if(cur.stop==n)
        {
            printf("%d\n",cur.cost);
            return 0;
        }
        dist[cur.stop]=cur.cost;
        static int _bus,_stop,dis;
        for(int i=stopHead[cur.stop];i;i=stop[i].next)
        {
            _bus=stop[i].cur;
            for(int j=busHead[_bus];j;j=bus[j].next)
            {
                _stop=bus[j].cur;
                dis=cur.cost+(_bus!=cur.bus);
                if(dis<dist[_stop])
                {
                    
                    dist[_stop]=dis;
                    Q.push({_stop,_bus,dis});
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}

