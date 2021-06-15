package com.grammer.multiThread;

public class __thread07_priority {
    private static class node implements Runnable{
        @Override
        public void run()
        {
            System.out.println(Thread.currentThread().getName() + " RUN");
        }
    }
    public static void main(String[] args) {

        System.out.println(Thread.MIN_PRIORITY);//1
        System.out.println(Thread.NORM_PRIORITY);//5
        System.out.println(Thread.MAX_PRIORITY);//10
        System.out.println("---------------");
        node a = new node();
        final int N = 10;
        Thread arr[] = new Thread[N];
        for(int i = 0; i < N; i++)
        {
            arr[i] = new Thread(a, Integer.toString(i));
            arr[i].setPriority(i + 1);//设置优先级，并无多大用处
            arr[i].getPriority();//获得优先级
        }
        for(int i = 0; i < N; i++) arr[i].start();


    }
}
