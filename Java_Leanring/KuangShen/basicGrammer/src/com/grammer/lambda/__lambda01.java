package com.grammer.lambda;

import java.util.*;

/*函数式接口*/
interface A{
    /*内部只有一个函数，Runnable就是一个函数式接口*/
    void run();
}

/*1、外部类*/
class A1 implements A{
    @Override
    public void run(){
        System.out.println("A1: 外部类");
    }
}
public class __lambda01 {

    /*2、静态内部类*/
    public static class A2 implements A{
        @Override
        public void run(){
            System.out.println("A2: 静态内部类");
        }
    }
    public static void main(String[] args) {
        A a = new A1();
        a.run();
        a = new A2();
        a.run();

        /*3、局部内部类*/
        class A3 implements A{
            @Override
            public void run(){
                System.out.println("A3: 局部内部类");
            }

        }
        a = new A3();
        a.run();

        /*4、匿名内部类*/
        a = new A(){
            @Override
            public void run()
            {
                System.out.println("A4: 匿名内部类");
            }
        };
        a.run();


        /*5、lambda*/
        a = ()->{
            System.out.println("A5: lambda");
        };
        a.run();

        /**
         * 从1 - > 2 -> 3 -> 4 -> 5是一步步简化的
         */


    }
}
