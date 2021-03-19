package com.basicgrammer2.www;
import java.util.Scanner;



public class __Scanner01 {

    public static void test1(){
        Scanner sc=new Scanner(System.in);
        /*输入：
        a bb ccc
        dddd
        ee
        输出：
        a
        bb
        ccc
        dddd
        ee
         */
        /**
         * 类似C++的cin
         */
        while(sc.hasNext()){
            String c=sc.next();
            System.out.println(c);
        }
        sc.close();
    }

    public static void test2() {
        Scanner sc=new Scanner(System.in);
        /*输入：
        a bb
        ccc
        输出：

         */
        String str=sc.next();
        System.out.println(str);
        str=sc.nextLine();
        System.out.println(str);
        sc.close();//注意关闭Scanner
    }
    public static void test3(){
        Scanner sc=new Scanner(System.in);
        System.out.println("as");
        //System.out.print(sc.nextByte());
        while(sc.hasNextByte()){
            System.out.print(sc.nextByte());
        }
        sc.close();
    }
    public static void test4(){
        /*
        输入：
123123 232 323
dsfsdfsdfsdafdsdf
        输出：
123123
232.0
323.0
dsfsdfsdfsdafdsdf
         */
        Scanner sc=new Scanner(System.in);
        System.out.println(sc.nextInt());
        System.out.println(sc.nextFloat());
        System.out.println(sc.nextDouble());
        System.out.println(sc.next());
        sc.close();
    }
    public static void main(String[] args) {
        test4();
    }
}


