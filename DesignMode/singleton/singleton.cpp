#include <stdio.h>
#include <stdlib.h>
#include <iostream>
class singleton
{
    //单例模式
    public:
        int val;
        static singleton* getInstance();
        ~singleton();
    private:
        static singleton* instance;
        singleton():val(10){};
        singleton(const singleton& a) = delete;
};

singleton* singleton::instance = NULL;

singleton* singleton::getInstance()
{
    if(instance == NULL)
    {
        instance = new singleton();
    }
    return instance;
}
singleton::~singleton()
{
    if(instance != NULL) delete instance;
}

int main(int argc, char* argv[])
{
    singleton* a = singleton::getInstance();
    singleton* b = singleton::getInstance();
    
    std::cout << a->val << " " << b->val << std::endl;
    a->val = 100;
    std::cout << a->val << " " << b->val << std::endl;
    delete a;
    
    return 0;
}