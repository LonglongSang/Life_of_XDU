package com.grammer.net.__01;


import java.io.IOException;
import java.io.PrintStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;

public class client {
    private static class clientInstance{
        private final InetAddress server;
        private final int port;
        private final PrintStream out;
        private final HashMap<Integer, Socket> socketArr;
        private int cnt = 0;
        clientInstance(InetAddress server, int port) throws Exception {
            if(server == null) throw new NullPointerException("server is null\n");
            else if(port < 0 || port >65535) throw new Exception(port + " is not valid\n");
            this.server = server;
            this.port = port;
            this.socketArr = new HashMap<>();
            this.out = System.out;
        }
        public void closeId(int id) throws IOException {
            Socket socket;
            synchronized (this){
                socket = socketArr.get(id);
            }
            if(socket == null){
                out.format("you close socket id: %d, not exist\n", id);
                return;
            }
            out.format("you close socket id: %d, success\n", id);
            socket.close();
            socketArr.remove(id);
        }
        public void closeAll() throws IOException {
            Iterator<Map.Entry<Integer, Socket>> it;
            for(it = socketArr.entrySet().iterator(); it.hasNext();){
                it.next().getValue().close();
            }
            socketArr.clear();
        }
        public synchronized void showConnectList(){
            Iterator<Map.Entry<Integer, Socket>> it = socketArr.entrySet().iterator();
            Socket socket;
            int id;
            Map.Entry<Integer, Socket> cur;
            out.format("----------------------connected socket list-------------------\n");
            while(it.hasNext()){
                cur = it.next();
                id = cur.getKey();
                socket = cur.getValue();
                out.format("id: %d\tlocal port: %d\n", id, socket.getLocalPort());
            }
            out.format("----------------------connected socket list end-------------------\n");
        }
        public synchronized void add() throws IOException {
            Socket temp = new Socket(server, port);
            socketArr.put(cnt++, temp);
        }
    }
    private static class Test implements Runnable{
        private final InetAddress server;
        private final int port;
        Test(InetAddress server, int port){
            if(server == null) throw new NullPointerException("null pointer");
            this.server = server;
            this.port = port;
        }
        @Override
        public void run(){
            clientInstance instance;
            try {
                 instance = new clientInstance(server, port);
            } catch (Exception e) {
                e.printStackTrace();
                return;
            }
            Scanner sc = new Scanner(System.in);
            String str;
            boolean good = false;
            int typ;
            boolean innerGood;
            while(!good){
                try{
                    instance.showConnectList();
                    System.out.format("input id/num for stop this socket, and -1 for leave, and -2 for stop all client,\n");
                    System.out.format("ans -3 for add a new socket connect, and -4 for add specific numbers of socket connect\n");
                    str = sc.nextLine();
                    typ = Integer.parseInt(str);
                    if(typ == -1){
                        good = true;
                    }else if(typ == -2){
                        instance.closeAll();
                    }else if(typ == -3){
                        instance.add();
                    }else if(typ == -4){
                        innerGood = false;
                        while(!innerGood){
                            innerGood = true;
                            System.out.format("input -1 for back, another number for new socket connect\n");
                            str = sc.nextLine();
                            typ = Integer.parseInt(str);
                            if(typ == -1){

                            }else if(typ >= 0){
                                for(int i = 0; i < typ; i++) instance.add();
                            }else{
                                throw new Exception(typ + " is bad numbers");
                            }
                        }
                    }else{
                        instance.closeId(typ);
                    }
                }catch (Exception e){
                    e.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        InetAddress i = null;
        try {
            i = InetAddress.getByName("localhost");
        } catch (UnknownHostException e) {
            e.printStackTrace();
        }
        int port = 5005;
        Test t = new Test(i, port);
        t.run();
    }
}
