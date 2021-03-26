#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <functional>
#include <time.h>
#include <unordered_map>
#include <string>
#include <direct.h>
#include <string.h>
#include <algorithm>

template <typename T>
class Account{
public:
    Account(std::string _name,T _money):name(_name),money(_money){}
    void add(T num){
        //为该账户的钱加上num
        money+=num;
    }
    const char* getName(){
        return name.c_str();
    }
    T getMoney(){
        return money;
    }
    std::mutex& getLock(){
        return myLock;
    }
private:
    T money;
    std::string name;
    std::mutex myLock;
};

template <typename T>
class Bank{
public: 
    Bank(){}
    void insertAccount(std::string& name,Account<T>& account){
        customer[name]=account;
    }
    static bool transferMoneyDeadlock(Account<T>& A,Account<T>& B,T num){
        //账户A向账户B转账num元（num>=0）
        //会出现死锁
        std::lock_guard<std::mutex> LA(A.getLock());//自动锁，在生命周期结束时会自动启动析构函数解锁
        std::lock_guard<std::mutex> LB(B.getLock());
        if(num>A.getMoney()) return false;
        A.add(-num);
        B.add(num);
        return true;
    }
    static bool transferMoneySafe(Account<T>& A,Account<T>& B,T num){
        //账户A向账户B转账num元（num>=0）
        //不会出现死锁
        std::lock(A.getLock(),B.getLock());
        std::lock_guard<std::mutex> LA(A.getLock(),std::adopt_lock);
        std::lock_guard<std::mutex> LB(B.getLock(),std::adopt_lock);
        if(num>A.getMoney()) return false;
        A.add(-num);
        B.add(num);
        return true;  
    }
    static bool transferMoneySafeMethod3(Account<T>& A,Account<T>& B,T num){
        //账户A向账户B转账num元（num>=0）
        //不会出现死锁
        std::lock(A.getLock(),B.getLock());
        if(num>A.getMoney()){
            A.getLock().unlock();
            B.getLock().unlock();
            return false;
        }
        A.add(-num);
        B.add(num);
        A.getLock().unlock();
        B.getLock().unlock();
        return true;  
    }    
    static bool transferMoneySafeMethod2(Account<T>& A,Account<T>& B,T num){
        //账户A向账户B转账num元（num>=0）
        //不会出现死锁
        A.getLock().lock();
        if(num>A.getMoney()){
            A.getLock().unlock();
            return false;
        }
        A.add(-num);
        A.getLock().unlock();

        B.getLock().lock();
        B.add(num);
        B.getLock().unlock();
        return true;  
    }
    T totalyMoney()const{
        //获得该银行存款总数
        T sum=0;
        for(auto&e:customer){
            sum+=e.getMoney();
        }
        return sum;
    }
private:
    std::unordered_map<std::string,Account<T>&> customer;
};


#define N 100

template <typename T>
void print(std::thread::id Id,bool& ok,Account<T>&A,Account<T>&B,T num){
    std::cout<<"thread ID: "<<Id;
    printf(", transfer %d money from [%s](%d) to [%s](%d),",(int)num,A.getName(),A.getMoney(),B.getName(),B.getMoney());
    if(ok) printf(" success\n");
    else printf(" failed\n");
};
std::mutex ex;
int cnt;
FILE* file;
void pri(){
    ex.lock();
    if(cnt && cnt%20==0) fputc('\n',file);
    fprintf(file,"%d",cnt);
    cnt++;
    ex.unlock();
}
template <typename T>
void randomTransferTest(bool(*transferMoney)(Account<T>&,Account<T>&,T),Bank<T>& bank,Account<T>& A,Account<T>&B){

    int circle=20000000;
    bool ok;
    int typ;
    T num;
    auto threadID=std::this_thread::get_id();
    while(circle--){
        num=rand()%N;
        typ=rand()%2;
        if(typ){
            ok=transferMoney(A,B,num);
            //print(threadID,ok,A,B,num);
            //pri();
        }else{
            ok=transferMoney(B,A,num);
            //print(threadID,ok,B,A,num);
            //pri();
        }

    }
}

void openFile(char* filename){
    printf("%s\n",filename);
    char cwd[1000];
    _getcwd(cwd,1000);
    int len=strlen(cwd);
    cwd[len]=0;
    printf("%s\n",cwd);
    auto func=[](char* s)->char{
        int i=0;
        while(s[i]){
            if(s[i]=='\\' || s[i]=='/') return s[i];
            i++;
        }
        return '\\';
    };
    cwd[len++]=func(filename);
    int flen=strlen(filename);
    int cur=len;
    while(flen>0 && filename[flen-1]!='\\' && filename[flen-1]!='/'){
        cwd[len++]=filename[--flen];
    }
    std::reverse(cwd+cur,cwd+len);
    cwd[len]=0;
    strcat(cwd,".out");
    printf("%s\n",cwd);
    file=fopen(cwd,"w+");
}
class timer{
public:
    unsigned int beg;
    timer(){
        beg=clock();
    }
    ~timer(){
        int end=clock();
        printf("totally time:%.2lf ms\n",(double)(end-beg)/CLOCKS_PER_SEC*1000);
    }
};
int main(int argv,char* argc[]){
    timer _timer;
    int typ=4;
    if(argv>=1) typ=atoi(argc[1]);
    printf("--%d\n",typ);
    srand(time(0));
    openFile(argc[0]);
    Bank<int> bank;
    Account<int>* A=new Account<int>("sang",3000);
    Account<int> B("zhu",3000);
    bank.transferMoneyDeadlock(*A,B,10);
    std::thread t1;
    std::thread t2;
    if(typ==1){
        t1=std::thread(randomTransferTest<int>,Bank<int>::transferMoneyDeadlock,std::ref(bank),std::ref(*A),std::ref(B));
        t2=std::thread(randomTransferTest<int>,Bank<int>::transferMoneyDeadlock,std::ref(bank),std::ref(*A),std::ref(B));
    }else if(typ==2){
        t1=std::thread(randomTransferTest<int>,Bank<int>::transferMoneySafe,std::ref(bank),std::ref(*A),std::ref(B));
        t2=std::thread(randomTransferTest<int>,Bank<int>::transferMoneySafe,std::ref(bank),std::ref(*A),std::ref(B));
    }else if(typ==3){
        t1=std::thread(randomTransferTest<int>,Bank<int>::transferMoneySafeMethod2,std::ref(bank),std::ref(*A),std::ref(B));
        t2=std::thread(randomTransferTest<int>,Bank<int>::transferMoneySafeMethod2,std::ref(bank),std::ref(*A),std::ref(B));
    }else if(typ==4){
        t1=std::thread(randomTransferTest<int>,Bank<int>::transferMoneySafeMethod3,std::ref(bank),std::ref(*A),std::ref(B));
        t2=std::thread(randomTransferTest<int>,Bank<int>::transferMoneySafeMethod3,std::ref(bank),std::ref(*A),std::ref(B));
    }else{
        return 0;
    }
    t1.join();
    t2.join();

    if(file) fclose(file);
    return 0;
}

 