package com.grammer.multiThread;
/**
 * 演示synchronized来实现有容量限制的生产者消费者模型，synchronized这个关键字还可以实现条件变量的wait和notify功能
 */

import java.util.concurrent.locks.ReentrantLock;

public class __thread11_ProducerAndConsumer {
    private static class Container{
        public int cnt = 0;
        public int tot = 0;
        public int capacity;//大小为limit的容器
        Container(int capacity){
            this.capacity = capacity;
        }
        public synchronized void push() throws InterruptedException {
            while(this.cnt == this.capacity){
                try{
                    this.wait();
                }catch(InterruptedException e){
                    e.printStackTrace();
                }
            }
            this.cnt++;
            this.tot++;
            this.notifyAll();
        }
        public synchronized void pop()throws InterruptedException{
            while(this.cnt == 0){
                try{
                    this.wait();
                }catch(InterruptedException e){
                    e.printStackTrace();
                }
            }
            this.cnt--;
            this.tot++;
            this.notifyAll();
        }
    }
    private static class Producer implements Runnable{
        public final int N;
        private Container c;
        Producer(Container c, int N){
            this.N = N;
            this.c = c;
        }
        @Override
        public void run(){
            for(int i = 0; i < N; i++)
            {
                try {
                    c.push();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
    private static class Consumer implements Runnable{
        public final int N;
        private Container c;
        Consumer(Container c, int N){
            this.c = c;
            this.N = N;
        }
        @Override
        public void run(){
            for(int i = 0; i < N; i++)
            {
                try {
                    c.pop();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args)throws InterruptedException {
        int N = 1000000;
        int T = 5;
        Container c = new Container(1000000);
        Thread pro[] = new Thread[T];
        Thread con[] = new Thread[T];
        for(int i = 0; i < T; i++){
            con[i] = new Thread(new Consumer(c, N));
            con[i].start();
        }
        for(int i = 0; i < T; i++){
            pro[i] = new Thread(new Producer(c, N));
            pro[i].start();
        }

        for(Thread i: con) i.join();
        for(Thread i: pro) i.join();
        System.out.println(c.tot + " " + c.cnt);
    }
}
