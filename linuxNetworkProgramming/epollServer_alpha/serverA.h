#ifndef SERVERA_HHHH
#define SERVERA_HHHH
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
#include <sys/epoll.h>
#include <mutex>
#include <unordered_map>
#define EPOLL_EVENT_SIZE 1024
//EPOLL返回队列的最大数量设置
class Server
{
    public:
        Server(int port,FILE* log,std::mutex* mutex_log,bool* UnShutdown);
        ~Server();
        void Initialize();
        int setSocket();
        int setServerInfo(int port);
        int setListen();
        int setEpoll();
        void main();
        void parseIp(int ip);
        void sayHello(int ip,int port);
        void sayGoodBye(int ip,int port);
        void eraseClient(int clientFd);
    private:
        bool initOk;//标识初试化是否成功
        int listenFd;//服务器监听的文件描述符
        int epollFd;//epoll管理的文件描述符
        int port;
        bool* UnShutdown;
        FILE* log;
        std::mutex* mutex_log;
        sockaddr_in serverInfor;
        epoll_event event[EPOLL_EVENT_SIZE];
        epoll_event ev;

        std::unordered_map<int,sockaddr_in> client;
};


#endif