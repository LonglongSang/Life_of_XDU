package com.grammer.multiThread;

import java.util.concurrent.locks.ReentrantLock;
public class __thread10_Retranlock {

    private static class node implements Runnable{

        private ReentrantLock lock = new ReentrantLock();
        public int val = 0;
        public static final int N = 100000000;
        @Override
        public void run()
        {

            /*
            for(int i = 0; i < N; i++)
            {
                lock.lock();
                this.val++;
                lock.unlock();
            }
            */

            try{
                lock.lock();
                for(int i = 0; i < N; i++){
                    this.val++;
                }
            }finally {
                lock.unlock();
            }
        }
    }
    public static void main(String[] args)throws InterruptedException {
        node a = new node();
        final int N = 10;
        Thread arr[] = new Thread[N];
        for(int i = 0; i < N; i++) arr[i] = new Thread(a);

        for(int i = 0; i < N; i++) arr[i].start();

        for(int i = 0; i < N; i++) arr[i].join();
        System.out.println(a.val + " " + a.N * N);
    }
}
