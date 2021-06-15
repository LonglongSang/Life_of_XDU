package com.grammer.exception;

import java.util.Scanner;

public class __exception01 {
    public static void run()
    {
        System.out.println("function end");
    }
    public static void test1()
    {
        int arr[] = new int[10];
        int index;
        Scanner sc = new Scanner(System.in);
        System.out.println("Please input");
        index = sc.nextInt();

        try
        {
            /*主动抛出异常*/
            if(index < 0 || index >= arr.length) throw new ArrayIndexOutOfBoundsException();
            System.out.println("Now Success visit arr[" + index + "]");
        }catch(Exception e)
        {
            System.out.println("-------Exception Infor--------");
            System.out.println(e.toString());
            e.printStackTrace();
            System.out.println("----------------");
        }finally
        {
            System.out.println("Failed to visit arr[" + index + "]");
        }

        /*捕获异常后，还会继续执行之后的代码，如果我们不写catch如果出现异常（exception），程序会自动退出*/
        run();
    }
    public static void test2()
    {
        int a = 10;
        int b = 0;
        try
        {
            System.out.println(a / b);
        }catch(Exception e)
        {
            System.out.println(e.toString());
        }finally
        {
            System.out.println("try catch code block end");
        }
        run();
    }
    public static void test3()
    {
        int a = 10;
        int b = 0;
        /**
         * 快捷键，选中数行代码，ctrl + alt + t，可以快速生成代码块
         */
        try {
            System.out.println(a / b);
        } catch (Exception e) {
            e.printStackTrace();
        }
        run();
    }
    public static void main(String[] args) {

        /*
        处理Error和Exception的5个关键字：try catch finally throw throws
        本代码不演示throws
         */
        test1();
        //test2();
        //test3();
    }
}
