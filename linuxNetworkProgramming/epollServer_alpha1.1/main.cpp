#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>//socket函数
#include <arpa/inet.h>
#include <time.h>
#include <mutex>
#include <sys/epoll.h>
#include <unordered_map>
#include <thread>
#include <chrono>
#include "serverA.h"


FILE* conf;
char confStr[1000];
static const char* ShutdownCmd="shutdown";

static bool UnShutdown=true;
std::mutex logMutex;
static int port;

void monitor();//监视是否关闭该进程
bool shouldShutdown();
void openConf();//打开控制文件
int main(int argv,char* argc[])
{


    if(argv!=2 || (port=atoi(argc[1]))>=65536 || port<=1024){
        fprintf(stdout,"please running like this \"./server 5005\"\n");
        exit(-1);
    }
    
    openConf();
    std::thread moni(monitor);
    
    Server* a=new Server(port,stdout,&logMutex,&UnShutdown);
    a->Initialize();
    a->main();
    delete a;

    if(moni.joinable()) moni.join();
    fclose(conf);

    return 0;
}




void openConf()
{
    conf=fopen("./conf","w+");
    if(conf==nullptr)
    {
        fprintf(stdout,"oepn control file failed, running failed,please check file ./conf\n");
        exit(-1);
    }
}
bool shouldShutdown()
{
    fseek(conf,0L,SEEK_SET);
    fscanf(conf,"%[^\n]",confStr);
    if(strcmp(confStr,ShutdownCmd)==0) return true;
    else return false;
}
void monitor()
{
    while(UnShutdown)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if(shouldShutdown())
        {
            UnShutdown=false;
        }
    }
}