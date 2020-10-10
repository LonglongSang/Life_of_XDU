#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <queue>
using namespace std;
struct node{
    int next;
    int bad;
};
node edge[20005];
int head[100005],n,m,from,to,cnt,bad_cnt,num,temp;
int bad[10005];
//上面的3行，所有的值都会被默认赋值为0
void add(){//建立线性查询表
    edge[++cnt].next=head[from];
    edge[cnt].bad=bad_cnt;
    head[from]=cnt;
    
    edge[++cnt].next=head[to];
    edge[cnt].bad=bad_cnt++;
    head[to]=cnt;
    
}
int main(){
    scanf("%d %d\n",&n,&m);//第一行输入
    for(int i=0;i<n;i++){//不可互存物品输入
        scanf("%d %d\n",&from,&to);
        add();
    }
    for(int c=0;c<m;c++){//m次迭代
        scanf("%d\n",&num);
        fill(bad,bad+bad_cnt,0);//将bad [0,bad_cnt)这个范围内的值都赋值为0
        bool good=true;
        for(int i=0;i<num;i++){
            scanf("%d",&temp);
            getchar();
            for(int j=head[temp];j;j=edge[j].next){
                bad[edge[j].bad]++;
                if(bad[edge[j].bad]==2){
                    good=false;
                    break;
                }
            }
        }
        if(good) printf("Yes\n");
        else printf("No\n");
    }
	return 0;
}