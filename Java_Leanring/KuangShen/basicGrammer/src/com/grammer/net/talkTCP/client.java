package com.grammer.net.talkTCP;

import java.io.IOException;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

public class client {
    public static void main(String[] args) throws IOException {
        InetAddress a = InetAddress.getByName("localhost");
        int port = 5005;
        Socket client = new Socket(a, port);
        OutputStream out = client.getOutputStream();
        while(true){
            System.out.printf("please input\n");
            char t = (char) System.in.read();
            if(t == 'q') break;
            System.out.printf("send: %c\n", t);
            out.write(t);
        }
        client.close();
    }
}
