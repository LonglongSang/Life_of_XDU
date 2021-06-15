package com.grammer.multiThread;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
/*实现线程方法2，Runnable接口来实现多进程*/
public class __thread02 implements Runnable
{
    public int val;
    public List<Integer> arr;
    __thread02()
    {
        this.val = 0;
        this.arr = new ArrayList<>();
    }

    public void run()
    {
        int index = Integer.valueOf(Thread.currentThread().getName());
        for(int i = 0, N = arr.get(index); i < N; i++)
        {
            this.val++;
        }
        System.out.println("Thread " + Thread.currentThread().getName() + " do add " + arr.get(index) + " times");
    }


    public static void main(String[] args)throws InterruptedException {
        //System.out.println(Thread.currentThread().getName());
        __thread02 a = new __thread02();
        Random r = new Random();
        final int N = 1000000;
        final int n = 10;//线程数量
        List<Thread> arr = new ArrayList<>();
        for(int i = 0; i < n; i++)
        {
            arr.add(new Thread(a, Integer.toString(i)));
            a.arr.add(r.nextInt(N));
        }
        for(Thread i: arr)
        {
            i.start();
        }
        for(Thread i: arr)
        {
            i.join();
        }
        System.out.println("--------");
        System.out.println(a.val);
        System.out.println("--------");
        for(Integer i: a.arr) System.out.println(i);
        System.out.println("--------");



    }
}
