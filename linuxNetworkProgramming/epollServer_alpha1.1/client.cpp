#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <thread>

int serverFh,clientFh,port;
struct sockaddr_in serverInfo,clientInfo;    //位于arpa/inet.h头文件，服务端地址信息的数据结构。
char buffer[1<<16];



void parseIp(int ip){
	printf("%d.%d.%d.%d",ip>>24&255,ip>>16&255,ip>>8&255,ip&255);
}
void sayHello(int ip){
    ip=ntohl(ip);
    printf("Has been connected to server :");
    parseIp(ip);
    putchar('\n');
    
}


int setSocket(){
    //第一步创建socket
    serverFh=socket(AF_INET,SOCK_STREAM,0);
    if(serverFh==-1){
        perror("socket open failed\n");
        return -1;
    }else{
        printf("server file handle is:%d\n",serverFh);
        return 0;
    }    
}
int setServerInfo(char* ip,char* port){
    // 第2步：设置服务端信息，并连接
    memset(&serverInfo,0,sizeof(sockaddr_in));
    serverInfo.sin_family=AF_INET;
    serverInfo.sin_port=htons(atoi(port));
    struct hostent* h;
    h=gethostbyname(ip);
    if(h==NULL){
        perror("gethostbyname failed\n");
        close(serverFh);
        return -1;
    }else{
        printf("gethostbyname success\n");
    }
    memcpy(&serverInfo.sin_addr,h->h_addr,h->h_length);
    if(connect(serverFh,(struct sockaddr*)&serverInfo,sizeof(sockaddr))!=0){
        perror("connect failed\n");
        close(serverFh);
        return -1;
    }else{
        printf("connect success\n");
    }
    return 0;
}
void Input(bool* ok)
{
    char buf[10000];
    printf("Input thread running\n");
    while(*ok)
    {
        int n;
        memset(buf,0,sizeof(buf));
        n=recv(serverFh,buf,sizeof(buf),0);
        if(n<=0) *ok=false;
        if(n) printf("recv: %s\n",buf);
    }
}
void communicate(){
    
    int n;
    printf("如果想要离开，请输入quit并回车\n");
    memset(buffer,0,sizeof(buffer));
    bool ok=true;
    std::thread t(Input,&ok);
    while(ok){
        printf("please input:\n");
        scanf("%[^\n\r]",buffer);
        getchar();
        if(strcmp(buffer,"quit")==0) break;
        if((n=send(serverFh,buffer,strlen(buffer),0))<=0){
            printf("after send leave\n");
            ok=false;
            break;
        }
        printf("send: %s\n",buffer);
    }
    if(t.joinable()) t.join();
}
int main(int argc,char* argv[]){
    /**
     * running:
     * ./[name] [ip] [port]
     * example:
     * ./client 127.0.0.1 5005
     */
    if(argc!=3) return -1;
    if(setSocket()==-1) return -1;
    if(setServerInfo(argv[1],argv[2])==-1) return -1;
    sayHello(serverInfo.sin_addr.s_addr);
    communicate();
    close(clientFh);
    
    return 0;
}

