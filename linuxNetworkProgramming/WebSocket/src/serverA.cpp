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
#include "semaphoreQueue.h"
#include <sys/syscall.h>
#define gettidv1() syscall(__NR_gettid)  
#define gettidv2() syscall(SYS_gettid)
#define DELAY_SECONDS 10

#define EPOLL_EVENT_SIZE 1024
//EPOLL返回队列的最大数量设置
#define TIMEOUT 1000
//TIMEOUT=-1表示设置为阻塞模式
//TIMEOUT>0 表示阻塞最长时长为ms
//TIMEOUT=0 不阻塞
#define BUFFER_SIZE 65536


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
    for(sang::clientMap<WebSocket*,OPEN_FILES_NUM>::iterator it=clientMp.begin();it!=clientMp.end();it++)
    {
        delete (*it);
    }
    close(listenFd);
    close(epollFd);
    fprintf(log,"Shutdown the server ~Server()\n");
}
void Server::Initialize()
{
    fprintf(log,"Initializing..........\n");
    if(*UnShutdown && initOk)
    {
        this->event=new epoll_event[EPOLL_EVENT_SIZE];
        if(this->event==nullptr) initOk=false;
    }
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
    ev.events=EPOLLIN|EPOLLET;//边缘触发模式，也可以设置为EPOLLIN | EPOLLET为水平触发模式
    if(epoll_ctl(epollFd,EPOLL_CTL_ADD,listenFd,&ev)==-1)
    {
        fprintf(log,"\t\tFailed add listenFd to epoll failed\n");
        return -1;
    }
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


int Server::errorEvent(epoll_event& thisEvent)
{
    fprintf(log,"Error: EPOLLERR or EPOLLHUP or Non-EPOLLIN happened wille close");
    if(thisEvent.data.fd==listenFd)
    {
        initOk=false;
        return -1;
    }else
    {
        closeQ.V((unsigned short)thisEvent.data.fd,DELAY_SECONDS);
        return 0;
    }
}


int Server::initializeClient(int clientFd,sockaddr_in& clientInfor)
{
    //客户端的文件句柄clientFd
    //clientInfor 客户端的连接信息
    std::unique_lock<std::mutex> lm(clientLock);
    if(clientMp.find(clientFd)!=clientMp.end())
    {
        //新来的连接需要创建新的websocket，但是上次连接未删除该websocket
        delete clientMp[clientFd];
    }
    clientMp[clientFd]=new WebSocket(clientFd,clientInfor);//创建
    client[clientFd]=clientInfor;//暂时使用
    ev.data.fd=clientFd;
    ev.events=EPOLLIN|EPOLLET;//和listenFd设置的一样
    epoll_ctl(epollFd,EPOLL_CTL_ADD,clientFd,&ev);
    return 1;
}
int Server::acceptEvent()
{
    //accept接受连接
    struct sockaddr_in clientInfor;
    unsigned int sockaddrLen=sizeof(sockaddr_in);
    int clientFd;
    fprintf(log,"accept connect: ");
    clientFd=accept(listenFd,(struct sockaddr*)&clientInfor,&sockaddrLen);
    if(clientFd==-1)
    {
        fprintf(log,"failed\n\n");
        return -1;
    }
    fprintf(log,"success\n");
    initializeClient(clientFd,clientInfor);
    sayHello(clientMp[clientFd]->ip,clientMp[clientFd]->port);
    return 0;
}

bool  Server::isHaveError(int n)
{
    if(n==-1)
    {
        //出错或者无数据可读
        if(!(errno==EAGAIN || errno==EINTR || errno==EWOULDBLOCK)) return true;
        //EAGAIN 被标记为非阻塞，或者是阻塞模式但是接受超时
        //EINTR 被中断，还可以继续读
        //EWOULDBLOCK 同EAGAIN
        return false;
    }else if(n==0)
    {
        return true;
    }else
    {
        return false;
    }
}





void Server::bufferMonitor()
{

    /*该程序是以线程运行，与服务器的生存周期相同。
    会检测comingQ这个生产者队列里是否有客户端的文件描述符，如果有，
    表示该客户端有数据到来，需要我们去取数据，如果数据正常取出，我们需要将
    该客户端的描述符添加至bufferQ中，表示该客户端buffer中有数据
    */
    unsigned short clientFd;
    int n;
    unsigned int pid=gettidv1();
    while(initOk && *UnShutdown)
    {
        clientFd=comingQ.P();
        if(comingQ.haveShutdown()) break;//程序要结束了
        if(clientMp.find(clientFd)==clientMp.end() || closeQ.inQueue(clientFd))
        {
            comingQ.pop(clientFd);
            continue;
        }
        fprintf(log,"bufferMonitor now process clientFd: %u %u\n",clientFd,pid);
        //clientFd的信息已经被删除，clientFd在关闭队列中
        n=clientMp[clientFd]->recvMessage();//调用接受消息方法
        if(n==-2)
        {
            //如果返回-2表示接受队列正在被占用，把clientFd重新放入comingQ中
            comingQ.pop(clientFd);
            comingQ.V(clientFd);
        }else if(isHaveError(n)){
            //连接出问题，将clientFd放入关闭队列中
            comingQ.pop(clientFd);
            closeQ.V(clientFd,DELAY_SECONDS);
        }else
        {
            comingQ.pop(clientFd);
            bufferQ.V(clientFd);
        }
        fprintf(log,"bufferMonitor have end clientFd: %u\n",clientFd);
    }
}
void Server::messageQMonitor()
{
    /*
    该线程会检测bufferQ中是否有文件描述符，如果bufferQ中存在文件描述符
    我们需要将该客户端文件描述符中buffer中的数据转移至该客户端的message中去
    同时需要将该客户端的文件描述符添加至messageQ中
    */
    unsigned short clientFd;
    unsigned int pid=gettidv1();
    int n;
    while(initOk && *UnShutdown)
    {
        clientFd=bufferQ.P();
        if(bufferQ.haveShutdown()) break;//程序要结束了
        if(clientMp.find(clientFd)==clientMp.end() || closeQ.inQueue(clientFd))
        {
            bufferQ.pop(clientFd);
            continue;
        }
        fprintf(log,"messageQMonitor now process clientFd: %u %u\n",clientFd,pid);
        //clientFd的信息已经被删除，clientFd在关闭队列中
        n=clientMp[clientFd]->moveFromBufferToMessage();
        //调用moveFromBufferToMessageQ,将数据从buffer转移到message中
        //返回值 -1： 标志该客户端的buffer数据为空，误报，不作处理
        //返回值 0：表示转移从客户端的buffer转移至客户端message，这需要将clientFd放如服务器的messageQ中
        //返回值 -2：表示客户端的message正在被占用，转移失败，将clientFd重新放入服务器的bufferQ中
        if(n==0)
        {
            //返回值为0，表示转移成功
            bufferQ.pop(clientFd);
            messageQ.V(clientFd);
        }else if(n==-2)
        {
            bufferQ.pop(clientFd);
            bufferQ.V(clientFd);
        }else
        {
            bufferQ.pop(clientFd);
        }
        fprintf(log,"messageQMonitor have end clientFd: %u\n",clientFd);
    }
}
void Server::haveMessageMonitor()
{
    /*
    该线程用于检测messageQ中是否存在客户端的文件描述符，如果存在，
    我们需要去检查该客户端的message中的信息是否能组装陈websocket报文
    如果可以，我们将会将该客户端的文件描述符添加至finBufferQ中去
    */
    unsigned short clientFd;
    int n;
    unsigned int pid=gettidv1();
    while(initOk && *UnShutdown)
    {
        clientFd=messageQ.P();
        if(messageQ.haveShutdown()) break;//程序要结束了
        if(clientMp.find(clientFd)==clientMp.end() || closeQ.inQueue(clientFd))
        {
            messageQ.pop(clientFd);
            continue;
        }
        fprintf(log,"haveMessageMonitor now process clientFd: %u %u\n",clientFd,pid);
        //clientFd的信息已经被删除，clientFd在关闭队列中
        n=clientMp[clientFd]->checkIsHaveMessageSegment();
        if(n==0)
        {
            messageQ.pop(clientFd);
            finBufferQ.V(clientFd);
        }else if(n==-2)
        {
            messageQ.pop(clientFd);
            messageQ.V(clientFd);
        }else{
            messageQ.pop(clientFd);
            //n==-1
        }
        fprintf(log,"haveMessageMonitor have end clientFd: %u\n",clientFd);
    }
}
void Server::finBufferMonitor()
{
    unsigned short clientFd;
    int n,resultLen;
    char* sendBuffer=new char[BUFFER_SIZE];
    bool isHandshake;
    unsigned int pid=gettidv1();
    while(initOk && *UnShutdown)
    {
        clientFd=finBufferQ.P();
        if(finBufferQ.haveShutdown()) break;//程序要结束了
        if(clientMp.find(clientFd)==clientMp.end() || closeQ.inQueue(clientFd))
        {
            finBufferQ.pop(clientFd);
            continue;
        }

        n=clientMp[clientFd]->sendMessage(sendBuffer,resultLen,BUFFER_SIZE,isHandshake);

        if(n==0)
        {
            broadcast(clientFd,sendBuffer,resultLen,isHandshake);
            finBufferQ.pop(clientFd);
        }else if(n==-2)
        {
            finBufferQ.pop(clientFd);
            finBufferQ.V(clientFd);   
        }else if(n==-3)
        {
            finBufferQ.pop(clientFd);
            closeQ.V(clientFd,DELAY_SECONDS);
        }else
        {
            finBufferQ.pop(clientFd);
        }
        fprintf(log,"finBufferMonitor have end clientFd: %u\n",clientFd);
        
    }
    delete []sendBuffer;    
}

void Server::broadcast(unsigned short clientFd,char* sendBuffer,int resultLen,bool isHandshake)
{
    int n;
    if(isHandshake)
    {
        fprintf(log,"handshake\n");
        //for(int i=0;i<resultLen;i++) fputc(sendBuffer[i],log);
        //fputc('\n',log);
        n=send(clientFd,sendBuffer,resultLen,0);
        if(n<=0) closeQ.V(clientFd,DELAY_SECONDS);
    }else
    {
        fprintf(log,"non-handshake\n");
        //for(int i=0;i<resultLen;i++) fputc(sendBuffer[i],log);
        //fputc('\n',log);
        for(sang::clientMap<WebSocket*,OPEN_FILES_NUM>::iterator it=clientMp.begin();it!=clientMp.end();it++)
        {
            if(closeQ.inQueue((*it)->clientFd)==false && (*it)->Verified==true && (*it)->clientFd!=clientFd)
            {
                printf("%u send to %d\n",clientFd,(*it)->clientFd);
                n=send((*it)->clientFd,sendBuffer,resultLen,0);
                if(n<=0) closeQ.V((*it)->clientFd,DELAY_SECONDS);
            }
        }
    }
}

void Server::closeMonitor()
{
    unsigned short clientFd;
    unsigned int pid=gettidv1();
    while(initOk && *UnShutdown)
    {
        clientFd=closeQ.P();
        if(closeQ.haveShutdown()) break;
        std::unique_lock<std::mutex> lm(clientLock);
        epoll_ctl(epollFd,EPOLL_CTL_DEL,clientFd,NULL);
        close(clientFd);
        sayGoodBye(clientMp[clientFd]->ip,clientMp[clientFd]->port);
        delete clientMp[clientFd];
        clientMp.erase(clientFd);
        
    }
}

void Server::main()
{
    if(!*UnShutdown || !initOk) return;
    fprintf(log,"\tServer on running\n");
    fflush(log);//将之前所有的日志信息刷出去
    int num;
    unsigned int pid=gettidv1();
    std::vector<std::thread> threadRunning;
    threadRunning.push_back(std::thread(&Server::bufferMonitor,this));

    threadRunning.push_back(std::thread(&Server::messageQMonitor,this));

    threadRunning.push_back(std::thread(&Server::haveMessageMonitor,this));

    threadRunning.push_back(std::thread(&Server::finBufferMonitor,this));

    threadRunning.push_back(std::thread(&Server::closeMonitor,this));

    unsigned short clientFd;
    while(*UnShutdown && initOk)
    {
        //fprintf(log,"\n\nepoll_wait %u\n",pid);
        num=epoll_wait(epollFd,event,EPOLL_EVENT_SIZE,TIMEOUT);
        if(num==-1)
        {
            //epoll_wait 出错了，我们需要关闭该服务器
            fprintf(log,"\tTYPE 1: epoll_wait error this Server will shutdown\n");
            initOk=false;
            break;
        }


        //if(num) fprintf(log,"\tTYPE 2: 开始轮询epoll返回的事件，事件总量: %d\n",num);
        for(int i=0;i<num;i++)
        {
            //fprintf(log,"\t\tevent %d ",i);
            if( (event[i].events & EPOLLERR) || (event[i].events & EPOLLHUP) || !(event[i].events & EPOLLIN))
            {
                //错误事件
                //EPOLLERR出现错误
                //EPOLLHUP，出现挂断，
                //所有非读的事件
                if(errorEvent(event[i])==-1) break;
            }else if(event[i].data.fd==listenFd)
            {
                //接受连接事件
                acceptEvent();
            }else
            {
                //读事件
                //fprintf(log,"read event\n");
                clientFd=(unsigned short)event[i].data.fd;
                if(clientMp[clientFd]==nullptr) continue;
                if(bufferQ.inQueue(clientFd)==false && closeQ.inQueue(clientFd)==false)
                {
                    comingQ.V(clientFd);//有读事件到来
                }
            }
        }
    }
    fprintf(log,"\tServer now starting to shutdown\n");
    bufferQ.shutdown();
    messageQ.shutdown();
    finBufferQ.shutdown();
    closeQ.shutdown();
    for(auto&th:threadRunning) th.join();
    fprintf(log,"\tServer have already shutdown\n");
}

void Server::output()
{
    std::unique_lock<std::mutex> lm(clientLock);
    fprintf(log,"\t\tConnected IP Report, alived client: %d\n",clientMp.size());
    for(sang::clientMap<WebSocket*,OPEN_FILES_NUM>::iterator it=clientMp.begin();it!=clientMp.end();it++)
    {
        parseIp((*it)->ip);
        fprintf(log,": %u\n",(*it)->port);
    }
    fprintf(log,"\n\n");
}

void Server::parseIp(int ip)
{
    //将存储的int中的ip转化为点分十进制IP并输出
	fprintf(log,"%d.%d.%d.%d",ip>>24&255,ip>>16&255,ip>>8&255,ip&255);
}
void Server::sayHello(int ip,int port)
{
    parseIp(ip);
    fprintf(log,":%d has coonect to our server",port);
}

void Server::sayGoodBye(int ip,int port)
{
    parseIp(ip);
    fprintf(log,":%d has disconnect to our server",port);    
}



