package com.grammer.exception;

/**
 * 如何使用throws
 */
public class __exception02 {
    public static void run(String a)
    {
        System.out.println(a + "end");
    }
    public static void main(String[] args) {
        try {
            /*捕获来自test1函数里抛出的异常*/
            test1(1, 0);
        } catch (ArithmeticException e) {
            e.printStackTrace();
        } finally {

        }
        run("main");
    }

    /*throws关键字的使用*/
    public static void test1(int a, int b) throws ArithmeticException
    {


        /*当throw后，之后的代码就不会运行了，会跳出当前代码块*/
        if(b == 0) throw new ArithmeticException();

        run("test1");
    }
}
