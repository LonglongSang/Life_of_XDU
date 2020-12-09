#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
template <class T,class V>
class myhash{
    private:
        int(*hash_mapping)(T&);
        int n,cap;
        struct node{
            T first;
            V second;
            node* next;
            node(T& a,V& b):first(a),second(b),next(NULL){}
        };
        node** head;
        pair<node*,node*> find_inner(T& key){
            //上一个，a
            int index=hash_mapping(key)%n;
            node* cur=head[index];
            node* last=NULL;
            bool vis=false;
            while(cur && !vis){
                if(cur->first==key){
                    vis=true;
                    break;
                }
                last=cur;
                cur=cur->next;
            }
            if(vis) return {last,cur};
            else return {NULL,NULL};
        }
    public:
        void initialize(){
            cap=0;
            head=new node*[n];
            for(int i=0;i<n;i++) head[i]=NULL;
        }
        myhash(int(*hash_mapping)(T&)){
            n=10000;
            initialize();
            this->hash_mapping=hash_mapping;
        }
        myhash(int(*hash_mapping)(T&),int cap){
            n=cap;
            initialize();
            this->hash_mapping=hash_mapping;
        }
        void insert(T& key,V& val){
            int index=hash_mapping(key)%n;
            node* cur=head[index];
            bool vis=false;
            while(cur && !vis){
                if(cur->first==key){
                    vis=true;
                    break;
                }
                cur=cur->next;
            }
            if(!vis){
                node* temp=new node(key,val);
                temp->next=head[index];
                head[index]=temp;
                cap++;//大小加一
            }else{
                cur->second=val;
            }
        }
        void erase(T& key){
            int index=hash_mapping(key)%n;
            pair<node*,node*> temp=find_inner(key);
            if(temp.second && temp.first){
                temp.first=temp.second->next;
                delete temp.second;
                cap--;//大小减1
            }else if(temp.second){
                head[index]=temp.second->next;
                delete temp.second;
                cap--;//大小减1
            }
        }
        node* find(T key){ 
            return find_inner(key).second;
        }
        V& operator[](T key){
            V val;
            if(find(key)==NULL) insert(key,val);
            return find(key)->second;
        }
        int size(){
            return cap;
        }
        node* end(){
            return NULL;
        }
        pair<myhash<T,V>::node**,int> begin(){
            return {head,n};
        }
        
};

template <class T,class V>
class iterator:public myhash<T,V>{
    friend class myhash<T,V>;
    public:
        
        //myhash<T,V>::node** arr;
        //myhash<T,V>::node* ptr;
        (myhash<T,V>::node)** arr;
        (myhash<T,V>::node) * ptr;
        int n;
        int cur;
        iterator(pair<myhash<T,V>::node**,int> temp){
            
            ptr=NULL;
            cur=0,n=temp.second;
            forward();
        }
        iterator& operator=(iterator& a){
            if(this!=&a) *this=a;
            return *this;
        }
        iterator& operator=(pair<myhash<T,V>::node**,int> temp){
            iterator(temp);
            return *this;
        }
        bool operator==(iterator& a){
            return ptr==a.ptr;
        }
        bool opeartor!=(iterator& a){
            return ptr!=a.ptr;
        }
        void forward(){
            if(ptr && ptr->next){
                ptr=ptr->next;
                return;
            }
            ptr=NULL;
            while(cur!=n && ptr==NULL){
                ptr=arr[cur++];
            }
        }
        void operator++(){
            forward();
        }
};
int mapping(int &a){
    return a;
}
void test1(){
    myhash<int,int> dp(mapping);
    dp[10]=10;
    dp[12]=123;
    cout<<dp.size()<<endl;
    cout<<dp[10]<<" "<<dp[13]<<endl;
    cout<<dp.size()<<endl;
}
struct node{
    char name[10];
    int grade;
    bool operator == (node &b){
        return grade==b.grade;
    }
};
int mapping1(node& a){
    return a.grade;
}
void test2(){
    myhash<node,int> dp(mapping1);
    node temp;
    temp.grade=10;
    dp[temp]=33;
    cout<<dp[temp]<<endl;
}
int main(){
    test2();
}