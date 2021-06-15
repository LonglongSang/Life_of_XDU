package com.grammer.net.talkTCP;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

public class server {
    public static void main(String[] args) throws UnknownHostException {
        InetAddress a = InetAddress.getByName("localhost");
        int port = 5005;
        ServerSocket server = null;
        Socket client = null;
        try{
            server = new ServerSocket(5005);
            client = server.accept();
            InputStream input = client.getInputStream();
            byte[] buffer = new byte[1 << 10];
            int len;
            while((len = input.read(buffer, 0, 1 << 10)) != -1){
                buffer[len] = 0;
                for(int i = 0; i < len; i++){
                    //System.out.printf("%s\n", buffer);
                    System.out.printf("%c", buffer[i]);
                }
            }
            input.close();
            client.close();
            server.close();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
