#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//Constant area
const int MAXN=1000000;
const int MIN_INF=0x80000000;
const int MAX_INF=0x7fffffff;
//Variable area
int n,te,m,st,ed,e;
//链式前向星起手4数组
int beg[20010];
int to[200100];
int nex[200100];
int weight[200100];
//标记该边隶属于哪条线路
int type[200100];
int tmp[105];
int path[10005];//记录路径
int take[10005];//记录这条路径经过的路线
int disw[10005];//记录最短距离
bool vis[10005];
int huancheng[10005];//记录换乘次数
vector<int> types;
vector<int> names;
struct p{
	int self;
	int val;
	bool operator <(const p &b)const{
		return val>b.val;
	}
};
priority_queue<p> q;
//Initialization area
void init(){
	e=0;
	memset(beg,-1,sizeof(beg));
    return;
}
//Function area

void add(int x,int y,int t,int ty){
	nex[++e]=beg[x];
	beg[x]=e;
	to[e]=y;
	weight[e]=t;
	type[e]=ty;
}
void dijkstra(){
	memset(vis,0,sizeof(vis));
	memset(disw,0x3f3f3f3f,sizeof(disw));
	memset(path,-1,sizeof(path));
	memset(take,-1,sizeof(take));
	memset(huancheng,0x3f3f3f3f,sizeof(huancheng));
	disw[st]=0;
	huancheng[st]=0;
	q.push({st,0});
	while(q.size()){
		p now=q.top();
		q.pop();
		if(vis[now.self])
			continue;
		vis[now.self]=true;
		for(int i=beg[now.self];i!=-1;i=nex[i]){
			int too=to[i];
			if(disw[too]>disw[now.self]+weight[i]){
				disw[too]=disw[now.self]+weight[i];
				path[too]=now.self;
				take[too]=type[i];
				if(now.self==st||take[too]==take[now.self])
				    huancheng[too]=huancheng[now.self];
				else
				    huancheng[too]=huancheng[now.self]+1;
				q.push({too,disw[too]});
			}else if(disw[too]==disw[now.self]+weight[i]){
				if(now.self==st||take[now.self]==type[i]){
					if(huancheng[too]>huancheng[now.self]){
						huancheng[too]=huancheng[now.self];
						path[too]=now.self;
						take[too]=type[i];
					}
				}else{
					if(huancheng[too]>huancheng[now.self]+1){
						huancheng[too]=huancheng[now.self]+1;
						path[too]=now.self;
						take[too]=type[i];
					}
				}
			}
		}
	}
	if(disw[ed]!=0x3f3f3f3f){
		cout<<disw[ed]<<endl;
		names.clear();
		types.clear();
		int lasttype=-2;
		for(int i=ed;i!=-1;i=path[i]){
			if(take[i]!=lasttype){
				names.push_back(i);
				types.push_back(take[i]);
				lasttype=take[i];
			}
		}
		for(int i=types.size()-1;i!=0;i--)
			printf("Go by the line of company #%d from %04d to %04d.\n",types[i-1],names[i],names[i-1]);
	}
	else
		printf("Sorry, no line is available.\n");
}
int main(){
    init();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>te;
		cin>>tmp[1];
		for(int j=2;j<=te;j++){
			cin>>tmp[j];
			add(tmp[j],tmp[j-1],1,i);
			add(tmp[j-1],tmp[j],1,i);
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>st>>ed;
		dijkstra();
	}
}
