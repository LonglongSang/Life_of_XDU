package com.learning.www;

import sun.awt.geom.AreaOp;

import java.util.ArrayList;
import java.util.List;

public class MyThread implements Runnable {
    public int value = 0;
    public static void main(String args[])throws InterruptedException {
        System.out.println("hello world ----");
        MyThread mt = new MyThread();
        List<Thread> arr = new ArrayList<Thread>();
        final int n = 3;
        for(int i = 0; i < n; i++) arr.add(new Thread(mt, i + "hello world"));
        for(int i = 0; i < n; i++) arr.get(i).start();
        for(int i = 0; i < n; i++) arr.get(i).join();
        System.out.println(mt.value);
        test();

    }
    public static void test()
    {
        System.out.println(Thread.currentThread().getName());
    }
    public int n = 10000000;
    public void run() {
        System.out.println(Thread.currentThread().getName());
        synchronized (this)
        {
            for(int i = 0; i < n; i++) this.value++;
        }

    }
}