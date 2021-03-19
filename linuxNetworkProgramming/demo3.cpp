#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>//close(int v)
#include <iostream>
#include <vector>
/**
 *这个demo介绍几个重要的结构体 
 */
namespace temp{
    #define sa_family_t unsigned short
    struct sockaddr {  
        sa_family_t sin_family;//地址族：AF_INET 或AF_INET6
        char sa_data[14]; //14字节，包含套接字中的目标地址和端口信息               
    };//sizeof(sockaddr)=16
	#define In_addr_t unsigned int
	struct in_addr{
		In_addr_t s_addr;//32位ipv4地址
	};
	struct sockaddr_in{
		sa_family_t sin_family;//地址族
		uint16_t sin_port;//16位端口号
		struct in_addr sin_addr;//32位ipv4地址,有么有觉得很憨憨，非要指向in_addr这个结构体。。
		char sin_zero[8];//补齐，使sockaddr_in和sockaddr一样大
	};//sizeof(sockaddr_in)=16,和sockaddr这个结构大小一样，方便转换
	#define h_addr h_addr_list[0]   //保存的是IP地址
    struct hostent
	{
		char *h_name;         //正式主机名
		char **h_aliases;     //主机别名
		int h_addrtype;       //主机IP地址类型：IPV4-AF_INET
		int h_length;		  //主机IP地址字节长度，对于IPv4是四字节，即32位
		char **h_addr_list;	  //主机的IP地址列表
	};
	
};
int main(int argc,char*argv[]){

}