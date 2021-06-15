package com.grammer.io.charStream;

public class temp {
    private static abstract class A{
        public void func(){
            System.out.println("A");
        }
    }
    private static class B extends A{
        public void func(){
            System.out.println("B");
        }
    }
    private static class C extends B{

    }
    public static void main(String[] args) {
        A a = new B();
        a.func();
    }
}
