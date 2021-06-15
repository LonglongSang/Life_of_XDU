#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <memory>
//工厂模式
class Tank
{
    public:
        int infor;
        virtual void printInfor() = 0;
};
class Tank96: public Tank
{
    public:
        void printInfor() override
        {
            printf("I am 96 Tank\n");
        }
};
class Tank98: public Tank
{
    public:
        void printInfor() override
        {
            printf("I am 98 Tank\n");
        }
};

class TankFactory
{
    public:
        virtual Tank* produceTank() = 0;
};
class Tank96Factory: public TankFactory
{
    public:
        Tank* produceTank()
        {
            return new Tank96();
        }
};
class Tank98Factory: public TankFactory
{
    public:
        Tank* produceTank()
        {
            return new Tank98();
        }
};
/**
 * 
 *          ------- Tank96Factory //生产96坦克
 * TankFactory---
 *          ------- Tank98Factory  //生产98坦克
 * 
 *         -------  Tank98
 * Tank ---
 *         -------  Tank96
 */

void test()
{
    TankFactory* factory96 = new Tank96Factory();
    TankFactory* factory98 = new Tank98Factory();
    Tank* tank1 = factory96->produceTank();
    Tank* tank2 = factory98->produceTank();
    tank1->printInfor();
    tank2->printInfor();
    delete factory96;
    delete factory98;
    delete tank1;
    delete tank2;
}
int main(int argc, char* argv[])
{
    test();
    return 0;
}