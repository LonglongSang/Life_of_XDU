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
#include <unordered_set>
#include <bitset>
#include "websocket.h"
#include "semaphoreQueue.h"
#include "clientMap.h"
#include "delayQueue.h"
#define EPOLL_EVENT_SIZE 1024
//EPOLL返回队列的最大数量设置
#define OPEN_FILES_NUM 65536
//表示能打开文件句柄的最大数目，本文件中就是clientFd的打开数量
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
        int errorEvent(epoll_event& e);

        int acceptEvent();
        int initializeClient(int clientFd,sockaddr_in& clientInfor);

        void readEvent(epoll_event& e,char* buffer,int sizeOfBuffer);

        void parseIp(int ip);
        void sayHello(int ip,int port);
        void sayGoodBye(int ip,int port);
        void eraseClient(int clientFd);


        void bufferMonitor();
        void messageQMonitor();
        void haveMessageMonitor();
        void closeMonitor();

        void finBufferMonitor();
        void broadcast(unsigned short clientFd,char* sendBuffer,int resultLen,bool isHandshake);
        bool isHaveError(int n);
        void output();
        std::mutex clientLock;
    private:
        bool initOk;//标识初试化是否成功
        int listenFd;//服务器监听的文件描述符
        int epollFd;//epoll管理的文件描述符
        int port;
        bool* UnShutdown;
        FILE* log;
        std::mutex* mutex_log;
        sockaddr_in serverInfor;
        epoll_event* event;
        epoll_event ev;
        std::unordered_map<unsigned int,sockaddr_in> client;
        //std::vector<WebSocket*> clientMp;
        sang::clientMap<WebSocket*,OPEN_FILES_NUM> clientMp;
        
        sang::semaphoreQueue<unsigned short,OPEN_FILES_NUM> comingQ;
        sang::semaphoreQueue<unsigned short,OPEN_FILES_NUM> bufferQ;
        sang::semaphoreQueue<unsigned short,OPEN_FILES_NUM> messageQ;
        sang::semaphoreQueue<unsigned short,OPEN_FILES_NUM> finBufferQ;
        //sang::semaphoreQueue<unsigned short,OPEN_FILES_NUM> closeQ;
        sang::delayQueue<unsigned short> closeQ;
};




#endif