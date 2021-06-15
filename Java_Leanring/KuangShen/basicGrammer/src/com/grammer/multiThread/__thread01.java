package com.grammer.multiThread;

/**
 * 实现线程方法1，继承Thread类，并重写run方法，之后调用start启动线程
 */
class P extends Thread
{
    public int val;
    P(int _val)
    {
        this.val = _val;
    }
    @Override
    public void run()
    {
        System.out.printf("run %d\n", this.val);
    }

}
public class __thread01 {
    public static void main(String[] args)throws InterruptedException{
        P a = new P(0);
        a.start();
        a.join();
    }
}
