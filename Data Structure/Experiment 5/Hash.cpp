//3、hash表
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
template <class T,class V>
class myhash{
    public:
        struct node{
            T first;
            V second;
            node* next;
            node(T& a,V& b):first(a),second(b),next(NULL){}
        };
    private:
        int(*hash_mapping)(T&);
        int n,cap;
        node** head;
        pair<node*,node*> find_inner(T& key){
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
        void initialize(){
            cap=0;
            head=new node*[n];
            for(int i=0;i<n;i++) head[i]=NULL;
        }
    public:

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
        void insert(T key,V val){
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
        void erase(T key){
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
        pair<node**,int> begin(){
            return {head,n};
        }

        public:
            class iterator{
                public:
                    node** arr;
                    node* ptr;
                    int n,cur;
                    iterator();
                    bool operator==(iterator& a);
                    bool operator!=(iterator& a);
                    bool operator!=(node* a);
                    void forward();
                    void operator++();
                    void operator++(int);
                    iterator& operator=(pair<node**,int> temp);
                    iterator& operator=(iterator& temp);
                    node* operator->();

            };   
};
template <class T,class V>
bool myhash<T,V>::iterator::operator==(myhash<T,V>::iterator& a){
    return ptr==a.ptr;
}
template <class T,class V>
bool myhash<T,V>::iterator::operator!=(myhash<T,V>::iterator& a){
    return ptr!=a.ptr;
}
template <class T,class V>
bool myhash<T,V>::iterator::operator!=(node* a){
    return ptr!=a;
}
template <class T,class V>
void myhash<T,V>::iterator::forward(){
    if(ptr && ptr->next){
        ptr=ptr->next;
        return;
    }
    ptr=NULL;
    while(cur!=n && ptr==NULL){
        ptr=arr[cur++];
    }
}

template <class T,class V>
void myhash<T,V>::iterator::operator++(){
    forward();
}
template <class T,class V>
void myhash<T,V>::iterator::operator++(int){
    forward();
}

template <class T,class V>
typename myhash<T,V>::iterator& myhash<T,V>::iterator::operator=(pair< myhash<T,V>::node **,int> temp){
    this->arr=temp.first;
    this->n=temp.second;
    this->cur=0;
    this->ptr=NULL;
    forward();
    return *this;
}
template <class T,class V>
typename myhash<T,V>::iterator& myhash<T,V>::iterator::operator=(myhash<T,V>::iterator& temp){
    memcpy(this,&temp,sizeof(temp));
    return *this;
}
template <class T,class V>
myhash<T,V>::iterator::iterator(){
    arr=NULL,ptr=NULL;
    n=0,cur=0;
}
template <class T,class V>
typename myhash<T,V>::node* myhash<T,V>::iterator::operator->(){
    return this->ptr;
}



struct infor{
    char name[21];
    char phone[12];
    char add[51];
}arr[10000];
int n;
int mapping_phone(char*& phone){
    //hash映射函数
    int ans=0;
    int dev=1e9+7;
    for(int i=0;phone[i];i++){
        ans=(ans*10+phone[i]-'0')%dev;
    }
    return ans;
}
void test1(){
    //以电话号码作为键
    myhash<char*,pair<char*,char*>> dp(mapping_phone);
    for(int i=0;i<n;i++){
        dp[(char*)arr[i].phone]={(char*)arr[i].add,(char*)arr[i].name};
    }
    myhash<char*,pair<char*,char*>>::iterator it;
    for(it=dp.begin();it!=dp.end();it++){
        printf("phone num:%s address:%s name:%s\n",it->first,it->second.first,it->second.second);
    }
    dp.erase((char*)arr[0].phone);
    printf("after delete one items\n");
    for(it=dp.begin();it!=dp.end();it++){
        printf("phone num:%s address:%s name:%s\n",it->first,it->second.first,it->second.second);
    }    
}
void input(){
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        scanf("%s %s %s",arr[i].name,arr[i].phone,arr[i].add);
    }
    /*
    3
    sanglonglong 12345 xidian
    wangyifa 110 xidainnan
    lixiaofei 120 xidianbei
    */
}
int main(){
    input();
    test1();
}