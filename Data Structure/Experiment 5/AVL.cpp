#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unordered_set>
#include <vector>
using namespace std;

template <class T>
class AVL{
    private:
        struct node{
            T val;
            node* left;
            node* right;
            int height;
            node(){};
            node(T v):val(v),height(1),left(NULL),right(NULL){}
        };
        node* root;
        bool (*cmp)(T&,T&);//排序比较函数
        bool (*eq)(T&,T&);//相等比较函数
        int capacity;
        bool isdel;
        /*
        假如我们遍历到一个节点root，出现了第一次不平衡
        本质：本质height(root->left)-height(root->right)>=2
        1、LL类型不平衡：
            height(root->left->left)>=height(root->left->right);
        2、LR类型不平衡
            height(root->left->right)>=height(root->left->left);
        3、RR类型不平衡
            height(root->right->right)>=height(root->right->left);
        4、RL类型不平衡
            height(root->right->left)>=height(root->right->right);
        */
        void LL(node* &root){
            node* temp=root->left;
            root->left=temp->right;
            temp->right=root;
            root->height=max(height(root->left),height(root->right))+1;
            root=temp;
            root->height=max(height(root->left),height(root->right))+1;
        }
        void RR(node*& root){
            node* temp;
            temp=root->right;
            root->right=temp->left;
            temp->left=root;
            root->height=max(height(root->left),height(root->right))+1;
            root=temp;
            root->height=max(height(root->left),height(root->right))+1;
        }
        void LR(node*& root){
            RR(root->left);
            LL(root);
        }
        void RL(node*& root){
            LL(root->right);
            RR(root);   
        }
        int height(node*& root){
            if(!root) return 0;
            else return root->height;
        }
        void adjust(node*& root){
            //调整root节点
            int dev=height(root->left)-height(root->right);
            if(abs(dev)!=2) return;
            if(dev==2){
                if(height(root->left->left)>=height(root->left->right)) LL(root);
                else LR(root);
            }else{
                if(height(root->right->right)>=height(root->right->left)) RR(root);
                else RL(root);
            }
        }
        void inner_insert(node* &root,T& val){
            //向root中插入val这个值
            if(!root){
                //插入查询到空节点，表明原来的avl树中没有插入值val
                root=new node(val);
                return;
            }
            if(val==root->val){
                //存在该节点取消插入
                capacity--;
                return;
            }else if(cmp(val,root->val)){
                //插到左子树
                inner_insert(root->left,val);
                if(abs(height(root->left)-height(root->right))==2){
                    //不平衡
                    /*
                    方法一进行LL，LR调整
                    if(cmp(val,root->left->val)){
                        //插入到root的左子树的左子树导致不平衡
                        //进行LL调整
                        LL(root);
                    }else{
                        //插入到root的左子树的右子树导致不平衡
                        //进行LR调整
                        //先对root->left进行RR调整
                        //再对root进行LL调整
                        LR(root);
                    }
                    */
                   //方法二
                   adjust(root);
                }
            }else{
                //插到右子树
                inner_insert(root->right,val);
                if(abs(height(root->right)-height(root->left))==2){
                    //不平衡
                    /*
                    方法一进行LL，LR调整
                    if(cmp(root->right->val,val)){
                        //插入到root的右子树的右子树导致不平衡
                        //进行RR调整
                        RR(root);
                    }else{
                        //插入到root的右子树的左子树导致不平衡
                        //进行RL调整
                        //先对root->right进行LL调整
                        //再对root进行RR调整
                        RL(root);
                    }
                    */

                    //方法二
                    adjust(root);
                }

            }
            root->height=max(height(root->left),height(root->right))+1;
            //更新root的高度
        }
        bool inner_find(node* root,T& val){
            //查询root为根的树中是否包含值为val的节点
            if(!root) return false;
            if(root->val==val) return true;
            else if(cmp(val,root->val)) return inner_find(root->left,val);
            else return inner_find(root->right,val);
        }
        void inner_mid_traverse(node* root,vector<T>& ans,int&cnt){
            if(!root) return;
            inner_mid_traverse(root->left,ans,cnt);
            ans[cnt++]=root->val;
            inner_mid_traverse(root->right,ans,cnt);
        }
        node* find_max(node*& root){
            //找到以root为跟子树中的最大值的节点
            if(!root || !root->right){
                return root;
            }else{
                return find_max(root->right);
            }
        }
        node* find_min(node*& root){
            //找到以root为跟子树中的最小值的节点
            if(!root || !root->left){
                return root;
            }else{
                return find_min(root->left); 
            }
        }
        void inner_erase(node*& root,T& val){
            //在root中查找删除val
            if(!root) return;
            if(root->val==val){
                //查找到了要删除的值
                isdel=true;
                if(root->left && root->right){
                    //左右子树均为非空
                    //将root->val的值与root->left为根的子树中的最大值进行替换
                    //然后再递归进行删除
                    //这样就能保证我们最后删除的值一定在叶子结点上
                    node*temp=find_max(root->left);
                    swap(temp->val,root->val);
                    inner_erase(root->left,val);
                }else{
                    //左右子树至少有一个为空树
                    node* temp=root;
                    root=root->left?root->left:root->right;
                    delete temp;
                }
            }else if(cmp(val,root->val)){
                inner_erase(root->left,val);
            }else{
                inner_erase(root->right,val);
            }
            if(root){
                adjust(root);
                root->height=max(height(root->left),height(root->right))+1;
            }
        }
        int is_avl_tree(node*root,bool &good){
            //判断是否是一颗高度平衡的树
            if(!root) return 0;
            int left=0,right=0;
            if(good) left=is_avl_tree(root->left);
            if(good) right=is_avl_tree(root->right);
            if(abs(left-right)>1) good=false;
            return max(left,right)+1;
        }
    public:
        AVL(bool (*cmp)(T&,T&), bool (*eq)(T&,T&)){
            //构造函数2
            root=NULL;
            this->eq=eq;
            this->cmp=cmp;
            capacity=0;
        }
        AVL(bool (*cmp)(T&,T&)){
            //构造函数2
            root=NULL;
            this->cmp=cmp;
            capacity=0;
        }
        void insert(T val){
            //插入val这个值
            capacity++;
            inner_insert(root,val);
        }
        void erase(T val){
            //删除val这个节点
            isdel=false;
            inner_erase(root,val);
            if(isdel) capacity--;
        }
        bool find(T val){
            //查询是否有val这个节点
            return inner_find(root,val); 
        }
        int size(){
            //返回avl树中的节点数
            return capacity;
        }
        int height(){
            //返回avl树的高度
            return height(root);
        }
        void mid_traverse(vector<int>& ans){
            //返回中序遍历
            ans.resize(capacity);
            int cnt=0;
            inner_mid_traverse(root,ans,cnt);
        }
        bool is_avl_tree(){
            //是否是一颗高度平衡的树
            bool good=true;
            is_avl_tree(root,good);
            return good;
        }
};



bool cmp(int& a,int &b){
    return a<b;
}
bool is_ok(vector<int>& num){
    //检查中序遍历数组是否为cmp规定的比较规则
    for(int i=1,n=num.size();i<n;i++){
        if(!cmp(num[i-1],num[i])) return false;
    }
    return true;
}
void test1(){
    //该例子只简介int类型的用法
    AVL<int> avl(cmp);
    srand(time(0));
    int n=100000,dev=10000;
    unordered_set<int> have;
    int del_cnt=0;
    for(int i=0;i<n;i++){
        int v=rand()%dev;
        have.insert(v);
        avl.insert(v);
        v=rand()%dev;
        avl.erase(v);
        if(have.find(v)!=have.end()) have.erase(v),del_cnt++;
    }
    vector<int> ans;
    avl.mid_traverse(ans);
    cout<<"###after manipulate###"<<endl;
    cout<<"avl.size() is: "<<avl.size()<<" avl.height()is: "<<avl.height()<<" unordered_set<int>'s size() is: "<<have.size()<<endl;
    cout<<"In this test totally delete "<<del_cnt<<" times"<<endl;
    if(is_ok(ans)) cout<<"it is a avl(bst) tree"<<endl;
    else cout<<"it is not a avl(bst) tree"<<endl;
}

void introduction(){
    /*
        用法简介
        构造一颗中序遍历序列为cmp函数规定的比较规则的AVL
        1、初始化该类型，必须传入一个比较函数
        2、你的类型T为自定义类型，你必须还要重载运算符==

        AVL<T> avl(cmp);
        bool cmp(T& a,T&b){
            //write your compare rule//
        }
        可用函数
        avl.size() 大小
        avl.height() 树高
        vector<int> ans=avl.mid_traverse();
        avl.find(v) 查询是否有v这个值
        avl.insert(v) 插入v
        avl.erase(v) 删除v
    */
}
int main(){
    test1();
    return 0;
}