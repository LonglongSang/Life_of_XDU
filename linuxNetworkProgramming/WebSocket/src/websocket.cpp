#include <thread>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <mutex>
#include <condition_variable>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include <unordered_map>
#include <queue>
#include <string.h>
#include <algorithm>
#include "myDeque.h"
#include "sha1.h"
#include "base64.h"
#include "websocket.h"
#define BUFFER_SIZE_WEBSOCKET 65536
#define WebSocket_HEAD_LEN 2





WebSocket::WebSocket(int clientFd,sockaddr_in infor)
{
    this->clientInfor=infor;
    this->clientFd=clientFd;
    this->ip=ntohl(infor.sin_addr.s_addr);
    this->port=ntohs(infor.sin_port);
    this->Verified=false;
    this->bufferSize=0;
    this->initialized=true;
    buffer=new char[BUFFER_SIZE_WEBSOCKET];
    message=new myDeque<char>();
    if(buffer==nullptr || message==nullptr)
    {
        if(buffer!=nullptr) delete[] buffer;
        if(message!=nullptr) delete message;
        buffer=nullptr;
        message=nullptr;
        initialized=false;
    }
    if(buffer!=nullptr) memset(buffer,0,BUFFER_SIZE_WEBSOCKET);
}

WebSocket::~WebSocket()
{
    if(buffer!=nullptr) delete[] buffer;
    if(message!=nullptr) delete message;
}




int WebSocket::recvMessage()
{
    //返回值
    //-2 表示暂时被占用，不可使用，请稍后再调用本函数
    //n表示read函数的结果
    std::unique_lock<std::mutex> lm(mutexBuffer,std::try_to_lock);
    if(lm.owns_lock()==false || bufferSize!=0) return -2;
    int n=read(clientFd,buffer,BUFFER_SIZE_WEBSOCKET);
    if(n>0) bufferSize=n;
    //for(int i=0;i<n;i++) putchar(buffer[i]);
    //putchar('\n');
    //int n=recv(clientFd,buffer,BUFFER_SIZE_WEBSOCKET,MSG_DONTWAIT);//非阻塞模式
    return n; 
}






int WebSocket::moveFromBufferToMessage()
{
    std::unique_lock<std::mutex> lm(mutexBuffer,std::try_to_lock);
    if(!lm.owns_lock()) return -2;//返回-2表示buffer正在被占用
    if(bufferSize==0) return -1;//返回-1表示数据为空
    bool ok=message->push_back(buffer,bufferSize,NON_BLCOK);
    //将buffer的数据存入message中
    if(ok==true) bufferSize=0;
    //ok为true表示成功，false表示message正在被占用
    return ok?0:-2;
}






int WebSocket::checkIsHaveMessageSegment()
{
    //-2表示被占用，-1表示没数据，0表示有数据
    std::unique_lock<std::mutex> lm(message->getLock(),std::try_to_lock);
    if(lm.owns_lock()==false) return -2;
    if(message->size()==0) return -1;
    if(!Verified)
    {
        //printf("!Verified\n");
        //printf("message size:%d\n",message->size());
        messageLength.push_back({message->getFront(),message->size()});
        return 0;
    }else if(messageLength.size()==1)
    {
        //已经有数据
        return 0;
    }else
    {
        int n=isHaveMessage();
        if(n==-1)
        {
            return -1;
        }else
        {
            messageLength.push_back({message->getFront(),n});
            return 0;
        }
    }
}
int WebSocket::isHaveMessage()
{
    if(message->size()<WebSocket_HEAD_LEN) return -1;
    int front=message->getFront();
    unsigned char typ=(*message)[front+1];
    typ&=127;
    unsigned long long dataLen=0;
    unsigned long long maskLen=((*message)[front+1]&128)?4:0;
    if(typ<126)
    {
        dataLen=typ;
        return (2+dataLen+maskLen<=message->size())?dataLen+2+maskLen:-1;
    }else if(typ==126)
    {
        if(message->size()<4) return -1;
        unsigned int a;
        for(int i=0;i<2;i++){
            a=(*message)[front+i+2];
            dataLen|=a<<((1-i)*8);
        }
        return (4+dataLen+maskLen<=message->size())?4+dataLen+maskLen:-1;
    }else
    {
        //typ==127
        if(message->size()<10) return -1;
        unsigned long long a;
        for(int i=0;i<8;i++){
            a=(*message)[front+i+2];
            dataLen|=a<<((7-i)*8);
        }
        return (10+dataLen+maskLen<=message->size())?dataLen+10+maskLen:-1;
    }
}




bool WebSocket::unmaskMessage(char* result,int& resultLen)
{
    if((result[1]&128)==0) return false;//客户端的消息未掩码处理，则关闭连接
    int maskBegin,dataBegin;
    result[1]&=127;
    if(result[1]<126)
    {
        maskBegin=2;
        dataBegin=6;
    }else if(result[1]==126)
    {
        maskBegin=4;
        dataBegin=8;
    }else
    {
        //result[1]==127
        maskBegin=10;
        dataBegin=14;
    }
    /*
    for(int i=0;i<resultLen-dataBegin;i++)
    {
        result[dataBegin+i]^=result[i%4+maskBegin];
    }
    */
    
    
    auto pri=[](char* result,int &resultLen)
    {
        printf("-----------start-------------\n");
        for(int i=0;i<resultLen;i++)
        {
            printf("%u ",(unsigned char)result[i]);
        }
        printf("\n-----------end---------------\n");
    };
    pri(result,resultLen);
    std::cout<<"total length "<<resultLen<<" dataLen"<<(resultLen-dataBegin)<<std::endl;
    printf("after unmasked\n");
    for(int i=dataBegin;i<resultLen;i++)
    {
        result[i]^=result[(i-dataBegin)%4+maskBegin];
        //putchar(result[i]);
    }
    //putchar('\n');
    for(int i=dataBegin;i<resultLen;i++)
    {
        result[i-4]=result[i];
    }
    resultLen-=4;
    return true;
}
int WebSocket::sendMessage(char* result,int& resultLen,int maxAcceptLength,bool& isHandshake)
{
    std::unique_lock<std::mutex> lm(message->getLock(),std::try_to_lock);
    if(lm.owns_lock()==false) return -2;
    if(messageLength.empty()) return -1;
    messageInfor infor;
    isHandshake=false;
    if(!Verified)
    {
        
        infor=messageLength.front();
        messageLength.pop_front();
        static char temp[10000];
        message->front(temp,infor.len,FATHER_LOCKED);
        temp[infor.len]=0;
        bool ppp=getHandshakeReply(temp,result,resultLen);
        if(ppp)
        {
            isHandshake=true;
            Verified=true;
            message->pop_front(infor.len,FATHER_LOCKED);
            return 0;
        }else
        {
            return -3;
        }
    }

    while(!messageLength.empty())
    {
        infor=messageLength.front();
        messageLength.pop_front();
        resultLen=std::min(maxAcceptLength,infor.len);
        message->pop_front(result,resultLen,FATHER_LOCKED);
        if(infor.len-resultLen!=0) messageLength.push_front({infor.beg,infor.len-resultLen});
        if(!unmaskMessage(result,resultLen)) return -3;
        return 0;
    }
    return 0;
}




bool WebSocket::getHandshakeReply(char* buf,char* result,int& resultLen)
{
    //完成
    /*检查是否是一个websocket的连接
    * buf表示传来的检查字符串
    * 如果是一个websocket连接就返回true，如果为true，将第二个参数secWebKeyAns中写入发来的Sec-WebSocket-Key 
    * 否则返回false
    */
    static std::string connection_upgrade="Connection: Upgrade";
    static std::string upgrade_websocket="Upgrade: websocket";
    int i=0,n=0,cnt,pos,secWebKeyCnt=0;
    char s[100];
    char secWebKey[100];
    bool flag1=false,flag2=false;
    
    
    while(buf[i])
    {
        cnt=0;
        while(buf[i] && buf[i]!='\n' && buf[i]!='\r')
        {
            s[cnt++]=buf[i++];
        }
        s[cnt]=0;
        while(buf[i] && (buf[i]=='\n' || buf[i]=='\r'))
        {
            i++;
        }
        if(strcmp(s,connection_upgrade.c_str())==0) flag1=true;
        if(strcmp(s,upgrade_websocket.c_str())==0) flag2=true;
        if((pos=isSec_WebSocket_Key(s))!=-1)
        {
            for(int i=pos;s[i];i++) secWebKey[secWebKeyCnt++]=s[i];
            secWebKey[secWebKeyCnt]=0;
        }
    }
    if(!flag1 || !flag2 || secWebKeyCnt==0) return false;
    
    handshakeReplyConcat(secWebKey,result,resultLen);
    return true;
}


int WebSocket::isSec_WebSocket_Key(char* s)
{
    //完成
    //判断字符串s是不是websocket请求报文中的：Sec-WebSocket-Key: vb7cURFdVjTfwp78sZ/muA==
    //vb7起始的字符串表示客户端请求报文中的Sec WebSoket Key的值
    static std::string sec="Sec-WebSocket-Key";
    for(int i=0;i<sec.length() && s[i];i++){
        if(sec[i]!=s[i]) return -1;//不是的话返回-1
    }
    return sec.length()+2;//是的话返回vb7起始的位置
}




void WebSocket::handshakeReplyConcat(char* secWebKeyAns,char* result,int& resultLen)
{
    //未完成
    //发送websocket的确认，如果发送成功就返回true，发送失败就返回false，接受到false应该断开连接
    static const char* a="HTTP/1.1 101 Switching Protocols\r\nUpgrade: websocket\r\nConnection: Upgrade\r\n";
    static const char* b="Sec-WebSocket-Accept: ";
    //"HSmrc0sMlYUkAGmm5OPpG2HaGWk="
    static const char* c="Sec-WebSocket-Protocol: chat\r\n\r\n";
    char decoding[100];
    getSha1Base64(secWebKeyAns,decoding,&resultLen);
    int cnt=0;
    for(int i=0;a[i];i++) result[cnt++]=a[i];
    for(int i=0;b[i];i++) result[cnt++]=b[i];
    for(int i=0;i<resultLen;i++) result[cnt++]=decoding[i];
    result[cnt++]='\r';
    result[cnt++]='\n';
    result[cnt++]='\r';
    result[cnt++]='\n';      
    //for(int i=0;c[i];i++) result[cnt++]=c[i];
    result[cnt]=0;
    resultLen=cnt;
    for(int i=0;i<resultLen;i++) putchar(result[i]);
}


std::mutex& WebSocket::getLock()
{
    return mutexLock;
}








static void getSha1Base64(char* ori,char* result,int* resultLen)
{
	//返回ori经过sha1编码和Base64编码后的字符串
	static SHA1 sha1;
	static base64 b64;
	static unsigned r1[5];
	static char r2[20];
	sha1.Reset();
	static const char*append="258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
	int len=strlen(ori)+36;//原来ori的长度加上append的长度
	strcat(ori,append);
	sha1.Input(ori,len);
	sha1.Result(r1);
	memcpy(r2,r1,sizeof(unsigned)*5);
	for(int i=0;i<5;i++)
	{
		std::reverse(r2+i*4,r2+(i+1)*4);
			/*为什么要5个1组翻转呢，因为作者存的使我们日常中的二级制顺序，也就是大端模式
			但现在大多数的电脑中采用的是小端模式，所以我们要4个char一组翻转，就是原来的一个unsigned
			其实最好的方法应该进行一次内存存储模式的大小端检测
			*/
	}
	/*
	for(int i=0;i<20;i++)
	{
		putchar(decimalTohex((r2[i]>>4)&15));
		putchar(decimalTohex(15&r2[i]));
	}
	*/
	std::string ans=b64.base64_encode((unsigned char const*)r2,20);
	memcpy(result,ans.c_str(),ans.length()*sizeof(char));
	*resultLen=(int)ans.length();
}