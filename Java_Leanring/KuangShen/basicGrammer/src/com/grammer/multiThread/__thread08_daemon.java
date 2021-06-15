package com.grammer.multiThread;

public class __thread08_daemon {
    private static class God implements Runnable{
        @Override
        public void run()
        {
            while(true)
            {

            }
        }
    }
    private static class Man implements Runnable{
        private int dayYouLive = 0;
        @Override
        public void run() {
            while(dayYouLive <= 365)
            {
                System.out.println(dayYouLive++);
            }
        }
    }

    public static void main(String[] args) {
        /*
        * 线程分为用户线程和守护线程
        * 虚拟机必须确保用户线程执行完毕
        * 虚拟机不用等待守护线程执行完毕
        * */

        God god = new God();
        Man man = new Man();
        Thread daemon = new Thread(god, "Daemon thread");//守护线程
        daemon.setDaemon(true);//将daemon线程设置为守护线程

        Thread aMan = new Thread(man, "User's thread");//用户线程，默认的都是用户线程

        daemon.start();
        aMan.start();



    }
}
