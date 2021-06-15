#include <stdio.h>
#include <iostream>
//简单工厂模式
enum TankType
{
    TANK96,
    TANK98
};
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
        Tank* produceTank(TankType type)
        {
            //生产坦克
            switch(type)
            {
                case TANK96:
                    return new Tank96();
                case TANK98:
                    return new Tank98();
                default:
                    return NULL;
            }
        }
};
/**
 * 
 * 
 * Factory类：生产Tank98或Tank96
 * 
 *         -------  Tank98
 * Tank ---
 *         -------  Tank96
 */
int main(int argc, char* argv[])
{
    TankFactory factory;
    Tank* tank1 = factory.produceTank(TANK96);
    Tank* tank2 = factory.produceTank(TANK98);
    tank1->printInfor();
    tank2->printInfor();
    delete tank1;
    delete tank2;
    return 0;
}