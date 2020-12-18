#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#define N 1000
int n,m;
bool vis[N];
template <class T>
class Graph{
    private:
        struct node{
            T val;
            int vertex;
            node* next;
            node(int to,T v):vertex(to),val(v),next(NULL){}
        };
        node** arcs;
    public:
        int vecnum,arcnum;
        Graph(int vecnum){
            arcs=new node*[vecnum];
            memset(arcs,0,sizeof(node*)*vecnum);
        }
        ~Graph(){
            node* cur;
            node* next;
            for(int i=0;i<vecnum;i++){
                cur=arcs[i];
                while(cur){
                    next=cur->next;
                    delete cur;
                    cur=next;
                }
            }
            delete []arcs;
        }
        void push(int from,int to,T val){
            node* temp=new node(to,val);
            temp->next=arcs[from];
            arcs[from]=temp;
        }
        node* operator[](int pos){
            return arcs[pos];
        }
        node* end(){
            return NULL;
        }
        class iterator{
            private:
                node* it=NULL;
            public:
                iterator(){}
                void operator++(){
                    it=it->next;
                }
                iterator& operator=(node* temp){
                    it=temp;
                    return *this;
                }
                node* operator->(){
                    return it;
                }
                bool operator!=(node* temp){
                    return it!=temp;
                }
        };
};




void input(Graph<bool>&g){
    scanf("%d %d\n",&g.vecnum,&g.arcnum);
    int from,to;
    for(int i=0;i<g.arcnum;i++){
        scanf("%d %d\n",&from,&to);
        g.push(from,to,true);
        cout<<from<<" "<<to<<endl;
    }
}
void print(int to,int depth){
    for(int i=0,n=depth*4;i<n;i++) putchar(' ');
    printf("%d\n",to);
}
void dfs(int cur,Graph<bool>&g,int fa,int depth){
    vis[cur]=true;
    Graph<bool>::iterator it;
    print(cur,depth);
    for(it=g[cur];it!=g.end();++it){
        if(vis[it->vertex]) continue;
        dfs(it->vertex,g,cur,depth+1);
    }
    vis[cur]=false;
}
int main(){
    Graph<bool> g(100);
    input(g);
    dfs(0,g,-1,0);
}