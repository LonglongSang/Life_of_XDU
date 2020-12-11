/*
This file please name as "xx.cpp"
Then you can follow the input standard
in the tail of this file to run kruskal algorithm
Author:
Long long Sang 
Date:
2020-12-11
Email:
llsang@foxmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define N 10000
int fa[N], ans[N], ranking[N];
namespace unionFind{
    int find(int a){
        if(fa[a] == a) return a;
        else return fa[a] = find(fa[a]);
        //路径压缩
    }
    bool merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(ranking[a] > ranking[b]) std::swap(a, b);
        //按秩合并
        fa[a] = b;
        ranking[b] += ranking[a];
        return true;
    }
};
class kruskal{
    private:
        int n, cnt, ans_cnt,m, tot_weight;
        struct edge{
            int from, to, weight;
        }e[N];
        void initialize(){
            for(int i = 0; i <= n; i++) fa[i] = i,ranking[i] = 1;
            cnt = n, ans_cnt=0, tot_weight=0;
        }
        bool isFinish(){
            return cnt == 1;
        }
        void input(){
            scanf("%d %d", &n, &m);
            getchar();
            for(int i = 0; i < m; i++){
                scanf("%d %d %d", &e[i].from, &e[i].to, &e[i].weight);
                getchar();
            }
        }
        void print(){
            if(cnt == 1) printf("This is a Minimum Spanning Tree(MST)\n");
            else printf("This is a Minimum Spanning Forest\n");
            printf("Total weight is %d\n", tot_weight);
            printf("We will choose %d path below:\n", ans_cnt);
            for(int i = 0; i < ans_cnt; i++){
                printf("City %d <-> City %d weight: %d\n", e[ans[i]].from, e[ans[i]].to, e[ans[i]].weight);
            }
        }
    public:

        kruskal(){}
        void running(){
            input();
            initialize();
            std::sort(e, e + n, [&](edge& a, edge& b){
                return a.weight < b.weight;
            });
            for(int i = 0; i < m && !isFinish(); i++){
                if(unionFind::merge(e[i].from, e[i].to)){
                    cnt--;
                    ans[ans_cnt++] = i;
                    tot_weight += e[i].weight;
                }
            }
            print();
        }
};
/*
input standard:
first line tow decimal number:
n m
n meaning number of vertex and m menaing number of edge
Then m line follow, and each line include three num like:
city1 city2 weight
city1 and city2 range from 1 to n meaning the city index.
weight meaing the weight between this two city

Example:
4 4
0 1 12
3 2 12
0 2 1
3 1 2


 （0）---12---（1）
  |             |
  1             2
  |             |
 （2）---12---（3）
*/
int main(){
    kruskal console;//kruskal的实例化
    console.running();//运行一个kruskal的运算
}