#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <mutex>
//单例模式（线程安全）
class singleton
{
    //单例模式（线程安全）
    public:
        int val;
        static singleton* getInstance();
        static void removeInstance();
    private:
        static std::mutex m;
        static singleton* instance;
        singleton():val(10){}
        singleton(const singleton& a) = delete;
        singleton& operator=(const singleton& a) = delete;
        ~singleton(){}
};

singleton* singleton::instance = NULL;

singleton* singleton::getInstance()
{
    std::unique_lock<std::mutex> lm(m);//线程安全
    if(instance == NULL)
    {
        instance = new singleton();
    }
    return instance;
}
void singleton::removeInstance()
{
    std::unique_lock<std::mutex> lm(m);
    if(instance != NULL) delete instance;
    instance = NULL;
}

int main(int argc, char* argv[])
{
    singleton* a = singleton::getInstance();
    singleton* b = singleton::getInstance();
    
    std::cout << a->val << " " << b->val << std::endl;
    a->val = 100;
    std::cout << a->val << " " << b->val << std::endl;
    
    return 0;
}