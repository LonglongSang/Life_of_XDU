 #ifndef WEBSOCKET_H
 #define  WEBSOCKET_H
#include <thread>
#include <iostream>
#include <stdlib.h>
#include <mutex>
#include <condition_variable>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include <unordered_map>
#include <queue>
#include <atomic>
#include <string.h>
#include "myDeque.h"
 // 你的代码写在这里



class WebSocket
{
    public:
        WebSocket(int clientFd,sockaddr_in infor);
        ~WebSocket();

        int recvMessage();

        int moveFromBufferToMessage();

        int checkIsHaveMessageSegment();
        int isHaveMessage();

        int sendMessage(char* result,int& resultLen,int maxAcceptLength,bool& isReply);
        bool unmaskMessage(char* result,int& resultLen);



        bool getHandshakeReply(char* buf,char* result,int& resultLen);
        int isSec_WebSocket_Key(char* s);
        void handshakeReplyConcat(char* secWebKeyAns,char* result,int& resultLen);
        
    
    
        unsigned int ip;
        unsigned short port;
        bool Verified;
        int clientFd;//客户端的文件描述符
        std::mutex& getLock();
        std::atomic<char> cntRunning;
    private:
        struct messageInfor
        {
            int beg;
            int len;
        };

        std::mutex mutexLock;
        sockaddr_in clientInfor;//客户端的socket信息
        
        char* buffer;//用于接受报文的缓冲区
        int bufferSize;//记录buffer中数据的长度
        std::mutex mutexBuffer;//保证buffer的互斥访问

        myDeque<char>* message;//即将被取走的WebSocket报文队列
        std::deque<messageInfor> messageLength;//记录message中每个websocket报文的长度
        
        
        
        
        /*
        Verified;
        表示是否初始化完成，什么是初始化呢，我们可能接受来自websocket的报文或者socket的报文
        如果是来自websocket的报文，会有其头部信息，我们需要对其回应，或者是来自socket的报文，无格式
        所以我们需要对不同的客户端进行回应，如果初始化完成，我们就不需要进行初始化了
        */
        bool initialized;

};
static void getSha1Base64(char* ori,char* result,int* resultLen);


 #endif