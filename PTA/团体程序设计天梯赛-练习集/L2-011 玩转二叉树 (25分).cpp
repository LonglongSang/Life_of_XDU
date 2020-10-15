#include <stdio.h>
#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
//中
int pre[100],inor[100];
int n;
struct node{
    node* left;
    node* right;
    int val;
    node(int _val): val(_val),left(NULL),right(NULL){}
};

int main(){
    node* root=NULL;
    scanf("%d\n",&n);
    
}