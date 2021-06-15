package com.grammer.net.fileTransfer;

import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;


public class __01_FileTransfer {
    private static class FileMiddleWare{
        public static void send(Socket client, File file){
            if(file == null || !file.exists() || file.isDirectory() || !file.canRead() || client == null) return;
            try {
                FileInputStream fInput = new FileInputStream(file);
                BufferedInputStream buffered = new BufferedInputStream(fInput, 1 << 3);
                byte[] arr = new byte[1 << 10];
                int len;
                OutputStream os = client.getOutputStream();
                while((len = buffered.read(arr, 0, arr.length)) != -1){
                    os.write(arr, 0, len);
                }
                os.close();
                buffered.close();
                fInput.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        public static void receive(Socket client, File file){
            if(client == null || file == null || !file.exists() || file.isDirectory() || !file.canRead()) return;
            try{
                FileOutputStream fOut = new FileOutputStream(file, false);
                BufferedOutputStream buffered = new BufferedOutputStream(fOut, 1 << 10);
                InputStream oi = client.getInputStream();
                byte[] arr = new byte[1 << 10];
                int len;
                while((len = oi.read(arr, 0, arr.length)) != -1){
                    buffered.write(arr, 0, len);
                }
                oi.close();
                buffered.close();
                fOut.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private static class Server implements Runnable{
        private final int port;
        private final InetAddress ip;
        Server(InetAddress ip, int port) {
            this.port = port;
            this.ip = ip;
        }
        public void main() throws IOException {
            ServerSocket server = new ServerSocket(port, -1, ip);
            Socket client = server.accept();
            FileMiddleWare.receive(client, new File("G:\\Life_of_XDU\\Java_Leanring\\kuangShen\\basicGrammer\\src\\com\\grammer\\net\\fileTransfer\\output.txt"));
            client.close();
            server.close();
        }
        @Override
        public void run(){
            try {
                main();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    private static class Client implements Runnable{
        private final int port;
        private final InetAddress ip;
        Client(InetAddress ip, int port) {
            this.port = port;
            this.ip = ip;
        }
        public void main() throws IOException, InterruptedException {
            Thread.sleep(2000);
            Socket so = new Socket(ip, port);
            FileMiddleWare.send(so, new File("G:\\Life_of_XDU\\Java_Leanring\\kuangShen\\basicGrammer\\src\\com\\grammer\\net\\fileTransfer\\input.txt"));
            so.close();
        }
        @Override
        public void run(){
            try {
                main();
            } catch (IOException | InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    public static void main(String[] args) {
        int port = 5005;
        InetAddress ip = null;
        try {
            ip = InetAddress.getByName("localhost");
        } catch (UnknownHostException e) {
            e.printStackTrace();
        }
        Server s = new Server(ip, port);
        Client c = new Client(ip, port);
        Thread t1 = new Thread(s, "server");
        Thread t2 = new Thread(c, "client");
        t1.start();
        t2.start();
        try {
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("test finish");
    }
}
