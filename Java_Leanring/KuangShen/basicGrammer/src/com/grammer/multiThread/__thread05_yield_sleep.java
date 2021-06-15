package com.grammer.multiThread;


public class __thread05_yield_sleep {
    private static class node implements Runnable
    {

        @Override
        public void run() {
            Thread cur = Thread.currentThread();
            System.out.println(cur.getName() + " Start");
            Thread.yield();//礼让，该线程从执行状态转为就绪状态，让CPU重新调度
            System.out.println(cur.getName() + " End");
        }
    }
    public static void main(String[] args) throws InterruptedException {
        node a = new node();
        Thread t1 = new Thread(a, "t1");
        Thread t2 = new Thread(a, "t2");
        Thread.sleep(1000);
        t1.start();
        t2.start();

    }
}
