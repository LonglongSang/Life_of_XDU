#include <stdio.h>
#include <stdlib.h>
//模板模式
//定义了算法的实现过程，但是对具体实现方法在基类中声明


class Computer
{
    public:
        void assemble()
        {
            installBoard();//安装主板
            installCpu();//安装cpu
            installGpu();//安装gpu
        }
        void show()
        {
            printf("board: %d cpu: %d gpu: %d\n", board, cpu, gpu);
        }
        ~Computer()
        {

        }
    protected:
        int cpu;
        int gpu;
        int board;//主板
        Computer(){};
        virtual void installCpu() = 0;
        virtual void installGpu() = 0;
        virtual void installBoard() = 0;
};
class HUAWEI:public Computer
{
    protected:
        void installBoard() override
        {
            board = 3;
        }
        void installCpu() override
        {
            cpu = 2;
        }
        void installGpu() override
        {
            gpu = 1080;
        }
};
class XIAOMI:public Computer
{
    protected:
        void installBoard() override
        {
            board = 1;
        }
        void installCpu() override
        {
            cpu = 2;
        }
        void installGpu() override
        {
            gpu = 960;
        }
};
int main()
{
    Computer* huawei = new HUAWEI();
    Computer* xiaomi = new XIAOMI();
    huawei->assemble();
    xiaomi->assemble();
    huawei->show();
    xiaomi->show();
    delete huawei;
    delete xiaomi;
}