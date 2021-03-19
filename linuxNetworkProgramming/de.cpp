#include <thread>
#include <atomic>
#include <string.h>
#include <iostream>
#include <netdb.h>
#include <unistd.h>
using namespace std;
int main() {

}

int isGood(char* ip,char* port){
    /**
     * 1、请检查字符串ip是否为如下格式 a.b.c.d
     * 0<=a,b,c,d<=255
     * 2、port
     *  0<=port<=65535
     * 例1： ip="123.12.u.213" port="238"
     * ip不符合
     * 例2: ip="122" port=""
     * ip不符合格式 port为空不符合格式
     * 
     * 返回值：
     * 如果ip和port规范请返回0，否则返回-1
     */
}





















