#pragma comment(linker, "/STACK:65536,65536") 
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
FILE* log;
char confStr[128];
static const char* ShutdownCmd="shutdown";
static const char* outputCmd="output";

static bool UnShutdown=true;
std::mutex logMutex;
static int port;
Server* thisServer;

void monitor();//监视是否关闭该进程
int shouldShutdown();
void openConf();//打开控制文件
void openLog();
int main(int argv,char* argc[])
{


    if(argv!=2 || (port=atoi(argc[1]))>=65536 || port<=1024){
        fprintf(stdout,"please running like this \"./server 5005\"\n");
        exit(-1);
    }
    
    openConf();
    openLog();
    std::thread moni(monitor);
    moni.detach();
    thisServer=new Server(port,log,&logMutex,&UnShutdown);
    thisServer->Initialize();
    thisServer->main();
    delete thisServer;
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
void openLog()
{
    //log=fopen("./log.txt","w+");
    log=stdout;
    if(log==nullptr)
    {
        fprintf(stdout,"open log failed\n");
        exit(-1);
    }
}
int shouldShutdown()
{
    fseek(conf,0L,SEEK_SET);
    confStr[0]=0;
    fscanf(conf,"%[^\n]",confStr);
    if(strcmp(confStr,ShutdownCmd)==0) return 0;
    else if(strcmp(confStr,outputCmd)==0) return 1;
    else if(strlen(confStr)!=0)
    {
        return 3;
    }
    else return 2;
}

void monitor()
{
    static int typ;
    while(UnShutdown)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if((typ=shouldShutdown())==0)
        {
            UnShutdown=false;
        }else if(typ==1)
        {
            fclose(conf);
            openConf();
            //std::cout<<"main running "<<shouldShutdown()<<std::endl;
            std::thread t(&Server::output,thisServer);
            t.detach();
        }else if(typ==3)
        {
            fclose(conf);
            openConf();            
        }
    }
}