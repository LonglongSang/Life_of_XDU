package com.grammer.basis._enum;

enum __enums02_Colors{
    Rx,Gx,Bx;
    private __enums02_Colors(){
        System.out.println("private constructor " + this.toString());
    }
    public void printInfo(){
        System.out.println("this is __enum02_Colors.printInfo()");
    }
    public static void printInfoStatic(){
        System.out.println("this is __enum02_Colors.printInforStatic()");
    }
}
public class __enum02 {
    public static void test1(){
        __enums02_Colors c = __enums02_Colors.Bx;
        c.printInfo();
    }
    public static void test2(){
        __enums02_Colors.printInfoStatic();
    }
    public static void main(String[] args) {
        System.out.println("Hello world");
        //test1();
        //test2();
    }
}
