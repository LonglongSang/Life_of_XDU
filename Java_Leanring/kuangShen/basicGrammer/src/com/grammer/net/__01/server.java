package com.grammer.net.__01;

import java.io.IOException;
import java.net.ServerSocket;
import java.util.Scanner;

public class server {
    private static class ServerInstance implements Runnable{
        private ServerSocket s;
        private int port;
        public boolean close;
        public int cnt;
        public void set(int port, int cnt){
            this.port = port;
            close = false;
            this.cnt = cnt;
        }
        @Override
        public void run(){
            try {
                s = new ServerSocket(port);
            } catch (IOException e) {
                e.printStackTrace();
            }
            Scanner sc = new Scanner(System.in);
            while(cnt-- > 0){
                try {
                    s.accept();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            System.out.println("enter to leave");
            sc.nextLine();
            try {
                s.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        ServerInstance s = new ServerInstance();
        s.set(5005, 10);//至多10次accept，实际上并不是，而是至多accept返回十个Socket十个指针，底层建立超过也没关系
        Thread t = new Thread(s, "1");
        t.start();
        try {
            t.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
