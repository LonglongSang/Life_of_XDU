package com.grammer.net;

import java.net.InetAddress;
import java.net.UnknownHostException;

public class __net01 {
    public static void printIp(byte[] arr){
        //将byte数组转为点分十进制ip地址
        for(int i = 0; i < arr.length; i++){
            if(i != 0) System.out.printf(".");
            System.out.printf("%d", arr[i] < 0 ? (int)arr[i] + 256 : (int)arr[i]);
        }
        System.out.printf("\n");
        /*
        for(int i = 0; i < arr.length; i++){
            if(i != 0) System.out.printf(".");
            System.out.printf("%d", arr[i] < 0 ? 128 + (int)(arr[i] & 0x7f) : (int)arr[i]);
        }
        System.out.printf("\n");
         */
    }
    public static void main(String[] args) {

        try{
            InetAddress a = InetAddress.getLocalHost();
            byte[] arr = a.getAddress();
            System.out.println(a);
            printIp(arr);
            System.out.println("host name : " + a.getHostName());
            System.out.println();
        }catch (UnknownHostException e) {
            e.printStackTrace();
        }
        try{
            InetAddress a = InetAddress.getByName("www.baidu.com");
            System.out.println("String type ip address: " + a.getHostAddress());
            System.out.println("host name: " + a.getHostName());
            System.out.println(a);
            System.out.println();
        }catch(UnknownHostException e){
            e.printStackTrace();
        }

        try{
            InetAddress a = InetAddress.getByName("127.0.0.1");
            System.out.println(a);
            System.out.println();
        } catch (UnknownHostException e) {
            e.printStackTrace();
        }

        try{
            InetAddress a = InetAddress.getByName("localhost");
            System.out.println(a);
        } catch (UnknownHostException e) {
            e.printStackTrace();
        }
    }
}
