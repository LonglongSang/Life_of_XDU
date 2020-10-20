//4、迷宫问题
#include<stdlib.h>
#include <stdio.h>
#define N 256
/*
使用语言:C++
输入格式
第一行两个空格分隔的正整数r，c
随后r行，每行c个由01组成的字符
例：
5 5
01000
00100
10000
11110
00000
注释：0表示可以走，1表示不可以走
*/
int dir[5][2]={0,0,1,0,0,1,-1,0,0,-1};
//方向数组dir[1 2 3 4]表示向下右上左四个方向
int r,c;
//表示图的行数和列数
bool grid[N][N];
//表示一个r*c的10地图
bool vis[N][N];
//访问标记
char path[N][N];
//路径记录
class linkstack;
//链栈
struct node;
void pri(int i);



int main(){
    //输入部分
	scanf("%d %d\n", &r, &c);
    char a;
    for(int i = 0; i < r ; i++){
        for(int j = 0; j < c; j++){
            scanf("%c", &a);
            grid[i][j] = a == '1' ? false : true;
        }
        getchar();
    }
    //主程序部分
    //如果入口grid[0][0]处就是1，表示被堵死
    if(!grid[0][0]){
        printf("end\n");
        return 0;
    }
    linkstack S;
    //声明链栈
    node cur(0, 0, 1);
    S.push(cur);
    bool find_path = false;
    while(!S.empty()){
        //模拟递归
        cur = S.top();
        S.pop();
        if(cur.i == 5){
            //(cur.x,cur.y)坐标递归完成
            //并将其访问标记重新标记为未访问
            vis[cur.x][cur.y] = false;
            continue;
        }else{
            //标记(cur.x,cur.y)被访问标记
            vis[cur.x][cur.y] = true;
        }
        if(cur.x == r - 1 && cur.y == c -1 ){
            //到达终点（右下角），停止循环
            find_path = true;
            break;
        }
        cur.i++;
        S.push(cur);//重新入站
        cur.i--;
        //next_x和next_y下一个要访问的点
        int next_x = dir[cur.i][0] + cur.x;
        int next_y = dir[cur.i][1] + cur.y;
        if(next_x >= r || next_x < 0 || next_y >= c || next_y < 0) continue;
        if(vis[next_x][next_y] || !grid[next_x][next_y]) continue;
        //如果next_x,next_y出了grid的范围
        //或者本身是一堵墙（即grid[x][y]==false）或者被访问过
        path[next_x][next_y] = cur.i;
        //记录路径
        node next(next_x, next_y, 1);
        S.push(next);
    }
    while(!S.empty()) S.pop();
    cur = {r-1, c-1, path[r-1][c-1]};
    while(cur.x != 0 || cur.y != 0){
        S.push(cur);
        int x = cur.x, y = cur.y;
        cur.x = x - dir[cur.i][0];
        cur.y = y - dir[cur.i][1];
        cur.i = path[cur.x][cur.y];
    }
    S.push(cur);
    while(!S.empty()){
        cur = S.top();
        S.pop();
        if(!S.empty()){
            printf("%d %d ", cur.x, cur.y);
            pri(S.top().i);
        }
        else printf("%d %d end\n", cur.x, cur.y);
    }
	return 0;
}
void pri(int i){
    if(i == 1) printf("down\n");
    else if(i == 2) printf("right\n");
    else if(i == 3) printf("up\n");
    else printf("left\n");
}
struct node{
	int x, y , i;
    //x,y表示坐标
    //i表示要递归哪个方向，初始i为1
    //当i为5的时候表示4个方向已经递归过
	node(int x, int y, int i){
		this->x = x;
		this->y = y;
        this->i = i;
	}
};
class linkstack{
	//链栈
    struct mynode{
        int x, y , i;
        mynode* next;
        mynode(int x, int y, int i){
            this->x = x;
            this->y = y;
            this->i = i;
            this->next = NULL;
        }
        mynode(const node& a){
            mynode(a.x, a.y, a.i);
        }
    };
    private:
	    int mysize;
        mynode* head;
	public:
        linkstack(){
            mysize = 0;
            head = NULL;
        }
        void push(node& a){
            mynode* temp = new mynode(a.x, a.y, a.i);
            mysize++;
            if(head == NULL){
                head = temp;
            }else{
                temp->next = head;
                head = temp;
            }
        }
        node top(){
            node ret(head->x, head->y, head->i);
            return ret;
        }
        void pop(){
            if(!head) return;
            mynode* temp = head->next;
            delete head;
            head = temp;
            mysize--;
        }
        int size(){
            return mysize;
        }
        bool empty(){
            return mysize == 0;
        }
};
//4、迷宫问题 结束


