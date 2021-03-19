#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>//close(int v)
#include <iostream>
#include <vector>

//please compile in linux
/**
 * int socket(int domain,int type,int protocol);
 * 
 * domain:
 * AF_INET 
 * AF_INET6
 * 上边两个宏定义在sys/socket.h头文件下，分别表示ipv4和ipv6，还有其他的宏（协议簇）可选
 * 
 * type表示在选择何种传输协议：一般TCP选择SOCK_STREAM,UDP选择SOCK_DGRAM
 * protocol表示选择何种协议，一般选择0
 * 如果成功返回套接字，失败返回-1
 * 
 */
int main(int argc,char*argv[]){
	int sockNum;
	std::vector<int> temp;
	for(int i=0;i<10000;i++){
		sockNum=socket(AF_INET,SOCK_STREAM,0);
		temp.push_back(sockNum);
		std::cout<<i<<" "<<sockNum<<std::endl;
		/**
		  * linux系统下socket最多可以打开多少个呢
		  * * 使用命令ulimit -a，会显示一行open files表示最多能打开的文件描述符的数量
		 */
	}
	for(auto&e:temp){
		close(e);
	}
}