#include <stdlib.h>
#include <stdio.h>
//策略模式
class Computer
{
    public:
        typedef int(*Func)(int, int);
        Computer(Func func)
        {
            this->func = func;
        }
        int doSomeOperation(int a, int b)
        {
            return func(a, b);
        }
    private:
        Func func;
};

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}

int main()
{
    Computer* addCom = new Computer(add);
    Computer* subCom = new Computer(sub);
    Computer* mulCom = new Computer(mul);

    int a = 10, b = 5;

    printf("%d %d %d\n", addCom->doSomeOperation(a, b), subCom->doSomeOperation(a, b), mulCom->doSomeOperation(a, b));
    delete addCom;
    delete subCom;
    delete mulCom;
}