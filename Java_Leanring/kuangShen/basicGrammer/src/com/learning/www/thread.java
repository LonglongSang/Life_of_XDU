package com.learning.www;
import java.io.PrintStream;
import java.util.Random;
import java.util.Scanner;

public class thread {
    private static class Cinema{
        public static class Counter implements Runnable{
            private boolean waitSomething = true;
            private boolean close = false;
            private final int counterId;
            private final PrintStream out;
            private final Scanner sc;
            private final Cinema cinema;
            Counter(int counterId, Scanner sc, Cinema cinema){
                this.counterId = counterId;
                this.sc = sc;
                out = System.out;
                this.cinema = cinema;
            }
            public synchronized void closeCounter(){
                close = true;
                this.notify();
            }
            public synchronized void notifyCounter(){
                waitSomething = false;
                this.notify();
            }
            private void sale(){
                boolean finish = false;
                out.format("欢迎来到 %s 电影院 %d 号柜台\n", cinema.getCinemaName(), counterId);
                while(!finish){
                    finish = true;
                    out.format("你想要%d柜台买几张票，输入正整数为你要买的票数（请购买100张以下），输入非正整数退出本次买票\n", counterId);
                    String s = sc.nextLine();
                    int typ;
                    try{
                        typ = Integer.parseInt(s);
                        typ = Math.min(typ, 100);
                        for(int i = 0; i < typ; i++){
                            out.format("你从柜台 %d 买了一张编号为 %d 的票\n", counterId, cinema.nextTicket(true));
                        }
                    } catch (NumberFormatException e) {
                        e.printStackTrace();
                        finish = false;
                    }
                }
                cinema.notifyFinish();
                out.format("\n\n\n");
            }
            @Override
            public synchronized void run(){
                while(!close){
                    while(!close && waitSomething){
                        try {
                            wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                    if(close) break;
                    sale();
                    waitSomething = true;
                }
                out.format("%d 柜台关闭\n", counterId);
            }
        }
        private final int[] simulationQueue = new int[100000];
        private int simulationCnt = 0;
        private final int counterNum;
        private int ticketId = 0;
        private final Counter[] cArr;
        private final static int maxCounterNum = 10;
        private final Scanner sc;
        private final Thread[] tArr;
        private final PrintStream out = System.out;
        private final String cinemaName;
        private boolean finish = false;
        private Simula simula;
        public String getCinemaName(){
            return cinemaName;
        }
        Cinema(int counterNum, String cinemaName){
            if(cinemaName == null || cinemaName.equals("")) cinemaName = "皮皮虾";
            this.cinemaName = cinemaName;
            sc = new Scanner(System.in);
            counterNum = Math.max(0, counterNum);
            counterNum = Math.min(maxCounterNum, counterNum);
            this.counterNum = counterNum;
            cArr = new Counter[counterNum];
            tArr = new Thread[counterNum];
            for(int i = 0; i < counterNum; i++){
                cArr[i] = new Counter(i, sc, this);
                tArr[i] = new Thread(cArr[i]);
                tArr[i].start();
            }
        }

        private synchronized void notifyFinish(){
            finish = true;
            notify();
        }
        private synchronized void waitFinish(){
            while(!finish){
                try{
                    this.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            finish = false;
        }
        private class Simula implements Runnable{
            Simula(Cinema cinema, int simulaDuration){
                this.cinema = cinema;
                simulaDuration = Math.max(simulaDuration, 100);
                simulaDuration = Math.min(simulaDuration, 10000);
                this.simulaDuration = simulaDuration;
            }
            private final Cinema cinema;
            private boolean shut = false;
            private final Random r = new Random();
            private final int simulaDuration;
            public synchronized void shutSimula(){
                shut = true;
                notify();
            }
            @Override
            public void run(){
                while(!shut){
                    try {
                        Thread.sleep(r.nextInt(simulaDuration));
                        cinema.nextTicket(false);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                out.format("模仿者Simula已经结束\n");
            }
        }
        private Simula simulation(int simulaDuration){
            Simula simula = new Simula(this, simulaDuration);
            Thread t = new Thread(simula);
            t.start();
            return simula;
        }
        private synchronized void printSimulaQueue(){
            if(simulationCnt == 0) return;
            out.format("-------------------------------\n");
            for(int i = 0; i < simulationCnt; i++){
                out.format("后台线程模仿者买了 %d 号票\n", simulationQueue[i]);
            }
            out.format("-------------------------------\n");
            simulationCnt = 0;
        }
        public void openCinema(boolean doYouWantSimulation, int simulaDuration){
            simula = (doYouWantSimulation && simula == null) ? simulation(simulaDuration) : null;
            while(true) {
                printSimulaQueue();
                out.format("欢迎来到 %s 电影院\n", cinemaName);
                out.format("你想要买票吗，本电影院总共有 %d 个柜台，请选择数字[0, %d]选择购票柜台, -1 离开本电影院\n", counterNum, counterNum - 1);
                String s = sc.nextLine();
                try {
                    int typ = Integer.parseInt(s);
                    if(typ >= 0 && typ < counterNum){
                        cArr[typ].notifyCounter();
                        waitFinish();
                    }else if(typ == -1){
                        break;
                    }
                } catch (NumberFormatException e) {
                    e.printStackTrace();
                }
            }
        }
        //关闭电影院里的柜台线程
        public void closeCinema(){
            for (Counter counter : cArr) {
                counter.closeCounter();
            }
            if(simula != null) simula.shutSimula();
        }
        public synchronized int nextTicket(boolean isPeople) {
            if (ticketId == 0x7fffffff) return -1;//无票了
            if(!isPeople){
                //电脑模拟的买票
                if(simulationCnt == simulationQueue.length) return -1;
                simulationQueue[simulationCnt++] = ticketId;
            }
            return ticketId++;
        }
    }
    public static void main(String[] args) {
        Cinema c = new Cinema(3, "龙氏");


        //true表示需要后台模拟线程去买票，3000表示如果需要后台模拟线程，他们会以[0,3000)的随机间隔去买票
        c.openCinema(true, 3000);
        c.closeCinema();
    }
}
