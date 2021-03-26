#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>//close(int v)
#include <iostream>
#include <vector>

int main(int argc,char*argv[]){
    int val=0x11223344;
    /**
     * 小端模式：
     * 在内存中，由地址由低到高依次存储每个字节为： 44 33 22 11
     * 大端模式：
     * 存储为11 22 33 44
     * 
     * 
     * 
     *//
}