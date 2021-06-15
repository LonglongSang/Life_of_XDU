package com.grammer.multiThread;

public class __thread06_state {

    public static void main(String[] args)throws InterruptedException {
        Thread t = new Thread(()->{
            for(int i = 0; i < 10; i++)
            {
                try{
                    Thread.sleep(20);
                }catch(InterruptedException e)
                {
                    e.printStackTrace();
                }
            }
        }, "t");

        Thread.State s = t.getState();//Thread.State是一个枚举类型
        System.out.println(s);
        t.start();
        s = t.getState();
        System.out.println(s);
        while(s != Thread.State.TERMINATED)
        {
            Thread.sleep(10);
            s = t.getState();
            System.out.println(s);
        }
    }
}
