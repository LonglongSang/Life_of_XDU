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
#include "serverA.h"
#define EPOLL_EVENT_SIZE 1024
//EPOLL返回队列的最大数量设置
#define TIMEOUT 20
//TIMEOUT -1表示设置为阻塞模式
//TIMEOUT>0 表示阻塞最长时长为ms
//TIMEOUT=0 不阻塞



Server::Server(int port,FILE* log,std::mutex* mutex_log,bool* UnShutdown)
{
    //port 服务器要使用的端口号，要使用的日志文件，对日志文件的锁
    //log 对应的日志文件句柄
    //Unshutdown,全局标记程序不退出
    fprintf(log,"Constructor: Server::Server(int port,FILE* log,std::mutex* mutex_log,bool* UnShutdown) Running\n");
    initOk=true;
    listenFd=-1;
    epollFd=-1;
    this->port=port;
    this->log=log;
    this->mutex_log=mutex_log;
    this->UnShutdown=UnShutdown;
}
Server::~Server()
{
    for(auto e:client)
    {
        close(e.first);
    }
    close(listenFd);
    fprintf(log,"Shutdown the server ~Server()\n");
}
void Server::Initialize()
{
    fprintf(log,"Initializing..........\n");
    if(*UnShutdown && initOk && setSocket()==-1) initOk=false;
    if(*UnShutdown && initOk && setServerInfo(port)==-1) initOk=false;
    if(*UnShutdown && initOk && setListen()==-1) initOk=false;
    if(*UnShutdown && initOk && setEpoll()==-1)
    {
        if(epollFd!=-1) close(epollFd);
        initOk=false;
    }
    if(!initOk)
    {
        fprintf(this->log,"\tServer initialize failed\n");
    }
    else if(!(*UnShutdown))
    {
        fprintf(log,"\tOverall command coming: will close the system\n");
    }else
    {
        fprintf(log,"\tInitialize success will running main console\n");
    }
}

int Server::setSocket()
{
    fprintf(log,"\tStep1: int Server::setSocket()\n");

    listenFd=socket(AF_INET,SOCK_STREAM,0);
    if(listenFd==-1)
    {
        perror("\t\tFailed setSocket() failed\n");
        return -1;
    }else
    {
        int opt=1;
        if(setsockopt(listenFd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt))==-1)
        {
            fprintf(log,"\t\tFailed setsockopt failed\n");
            return -1;
        }else
        {
            fprintf(log,"\t\tSuccess listenFd is:%d\n",listenFd);
            return 0;
        }
        
        
    }
}

int Server::setServerInfo(int port)
{
    fprintf(log,"\tStep2: int Server::setServerInfo(int port)\n");
    // 第2步：把服务端用于通信的地址和端口绑定到socket上。
    memset(&serverInfor,0,sizeof(sockaddr_in));
    serverInfor.sin_family=AF_INET;
    serverInfor.sin_port=htons(port);//绑定5005端口，htons位于arpa/inet.h
    serverInfor.sin_addr.s_addr=htonl(INADDR_ANY);//位于sys/socket.h表示0.0.0.0这种ip地址,实际就是0
    if(bind(listenFd,(sockaddr*)&serverInfor,sizeof(serverInfor))!=0)
    {//绑定地址信息到socket套接字的文件句柄（serverFh)
        //绑定失败
        fprintf(log,"\t\tFailed:bind failed\n");
        close(listenFd);
        return -1;
    }else
    {
        fprintf(log, "\t\tSuccess\n");
        return 0;
    }
}
int Server::setListen(){
    //第三步，设置为监听
    fprintf(log,"\tStep3: int Server::setListen()\n");
    if(listen(listenFd,SOMAXCONN)!=0)
    {//将服务器设置为监听模式
        //可以使用SOMAXCONN宏定义
        fprintf(log,"\t\tFailed listen set failed\n");
        close(listenFd);
        return -1;
    }else
    {
        fprintf(log,"\t\tSuccess\n");
        return 0;
    }
}
/*
int epoll_create(int size);
	参数: 
		size: 没意义, 随便写个数就行（早期epoll数据结构为hash表，需要指定表长，但后面改为红黑树后其实树节点个数就没有什么意义了）
	返回值;
		>0: 文件描述符, 操作epoll树的根节点
	Epoll检测的事件:
	- EPOLLIN
	- EPOLOUT
	- EPOLLERR
    // 对epoll树进行管理: 添加节点, 删除节点, 修改已有的节点属性
*/

/*
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
	参数:
		- epfd: epoll_create的返回值, 通过这个值就可以找到红黑树
		- op: 要进行什么样的操作
			EPOLL_CTL_ADD: 注册新节点, 添加到红黑树上
			EPOLL_CTL_MOD: 修改检测的文件描述符的属性
			EPOLL_CTL_DEL: 从红黑树上删除节点
		- fd: 要检测的文件描述符的值
		- event: 检测文件描述符的什么事件
*/


int Server::setEpoll()
{
    fprintf(log,"\tStep4: int Server::setEpoll()\n");
    epollFd=epoll_create(10000);
    if(epollFd==-1)
    {
        fprintf(log,"\t\tFailed epoll_create failed\n");
        return -1;
    }
    ev.data.fd=listenFd;
    ev.events=EPOLLIN;//边缘触发模式，也可以设置为EPOLLIN | EPOLLET为水平触发模式
    if(epoll_ctl(epollFd,EPOLL_CTL_ADD,listenFd,&ev)==-1)
    {
        fprintf(log,"\t\tFailed add listenFd to epoll failed\n");
        return -1;
    }
    //1 epoll的文件描述符
    //2 事件描述
    //3 要检测的文件描述符
    //4 描述文件描述的时间
    fprintf(log,"\t\tSuccess\n");
    return 0;
}
/*

int epoll_wait(int epfd, struct epoll_event *events, int maxevents, int timeout);
	参数:
		- epfd: epoll_create的返回值（这棵红黑树的根节点）, 通过这个值就可以找到红黑树
		- events: 传出参数, 保存了发生变化的文件描述符的信息（数组形式）
		- maxevents: 第二个参数结构体数组的大小
		- timeout: 阻塞时间
			- 0: 不阻塞
			- -1: 一直阻塞, 知道检测的fd有状态变化, 解除阻塞
			- >0: 阻塞的时长(毫秒)
     返回值:
		- 成功: 有多少个文件描述符状态发生了变化 > 0
        - 失败: -1
*/

void Server::eraseClient(int clientFd)
{
    epoll_ctl(epollFd,EPOLL_CTL_DEL,clientFd,NULL);
    close(clientFd);
    std::unordered_map<int,sockaddr_in>::iterator it=client.find(clientFd);
    if(it==client.end()) return;
    sayGoodBye(it->second.sin_addr.s_addr,it->second.sin_port);
    client.erase(it);
}
void Server::main()
{
    int num;
    struct sockaddr_in clientInfor;
    unsigned int sockaddrLen=sizeof(sockaddr_in);
    int clientFd;
    int n;
    char buffer[10000];
    while(*UnShutdown && initOk)
    {
        //fprintf(log,"new circle wait for epoll wait\n");
        num=epoll_wait(epollFd,event,EPOLL_EVENT_SIZE,TIMEOUT);
        //fprintf(log,"after epoll wait %d\n",num);
        //fprintf(log,"client size %d\n",(int)client.size());
        if(num==-1)
        {
            //epoll_wait 出错了
            fprintf(log,"epoll_wait error\n");
            initOk=false;
            continue;
        }


        for(int i=0;i<num;i++)
        {

            if( (event[i].events & EPOLLERR) || (event[i].events & EPOLLHUP) || !(event[i].events & EPOLLIN))
            {
                //EPOLLERR出现错误
                //EPOLLHUP，出现挂断，
                //所有非读的事件
                if(event[i].data.fd==listenFd)
                {
                    initOk=true;
                    break;
                }else
                {
                    fprintf(log,"close it 111\n");
                    eraseClient(event[i].data.fd);
                }
            }else if(event[i].data.fd==listenFd)
            {
                //accept接受连接
                clientFd=accept(listenFd,(struct sockaddr*)&clientInfor,&sockaddrLen);
                if(clientFd==-1) continue;
                sayHello(clientInfor.sin_addr.s_addr,clientInfor.sin_port);
                ev.data.fd=clientFd;
                ev.events=EPOLLIN;//和listenFd设置的一样
                epoll_ctl(epollFd,EPOLL_CTL_ADD,clientFd,&ev);
                client[clientFd]=clientInfor;
            }else
            {
                bool end=false;
                /*
                while(1)
                {
                    
                    n=read(event[i].data.fd,buffer,sizeof(buffer));
                    if(n==-1)
                    {
                        //出错或者无数据可读
                        if(errno != EAGAIN) end=true;
                        break;
                    }else if(n==0)
                    {
                        //event[i].data.fd连接已经中断
                        end=true;
                        break;
                    }else
                    {
                        fprintf(log,"clientFd:%d, %s\n",event[i].data.fd,buffer);
                    }
                }
                */
                memset(buffer,0,sizeof(buffer));
                n=read(event[i].data.fd,buffer,sizeof(buffer));
                if(n==-1)
                {
                    //出错或者无数据可读
                    if(errno != EAGAIN) end=true;
                }else if(n==0)
                {
                    //event[i].data.fd连接已经中断
                    end=true;
                }else
                {
                    fprintf(log,"clientFd:%d, %s\n",event[i].data.fd,buffer);
                    //下边的if为群发测试
                    if(1)
                    {
                        int arr[100];
                        int cnt=0,n;
                        int len=strlen(buffer);
                        for(auto e:client)
                        {
                            if(e.first!=event[i].data.fd)
                            {
                                n=send(e.first,buffer,len,0);
                                if(n<=0) arr[cnt++]=e.first;
                            }
                        }
                        for(int i=0;i<cnt;i++) eraseClient(arr[i]);
                    }
                }
                if(end) 
                {
                    eraseClient(event[i].data.fd);
                    fprintf(log,"close it 222\n");
                }
            }
        }
    }
}
void Server::parseIp(int ip)
{
	fprintf(log,"%d.%d.%d.%d",ip>>24&255,ip>>16&255,ip>>8&255,ip&255);
}
void Server::sayHello(int ip,int port)
{
    port=ntohs(port);
    ip=ntohl(ip);
    parseIp(ip);
    fprintf(log,":%d has coonect to our server\n",port);
}

void Server::sayGoodBye(int ip,int port)
{
    port=ntohs(port);
    ip=ntohl(ip);
    parseIp(ip);
    fprintf(log,":%d has disconnect to our server\n",port);    
}


