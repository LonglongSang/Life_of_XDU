#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <queue>
using namespace std;
#define MAXM 10005
#define MAXN 1005
int indeg[MAXN],head[MAXM],to[MAXM],nex[MAXM],cnt,level[MAXN],n,m;
bool vis[MAXN];
void add(int from,int t){
	to[++cnt]=t;
	nex[cnt]=head[from];
	head[from]=cnt;
}
int main(){
    int from,t,k,cur;
    scanf("%d %d\n",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d\n",&from,&t);
		add(from,t);
		indeg[t]++;
	}
	scanf("%d\n",&k);
    cnt=0;
	int indeg_temp[MAXN];
	for(int c=0;c<k;c++){
		bool good=true;
		for(int i=1;i<=n;i++) indeg_temp[i]=indeg[i];
		for(int i=0;i<n;i++){
			scanf("%d",&cur);
			getchar();
			if(good && indeg_temp[cur]!=0) good=false;
			if(good){
				for(int j=head[cur];j;j=nex[j]){
					indeg_temp[to[j]]--;
				}
			}
		}
		if(!good){
            if(cnt) printf(" ");
			printf(" %d",c);
			cnt++;
        }
	}
	if(cnt)printf("\n");
	return 0;
}